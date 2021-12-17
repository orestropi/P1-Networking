#include <arpa/inet.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>
#include <ctime>
#include <chrono>
#include <vector>
#include <iterator>
#include <string>

#include <iostream>
#include <filesystem>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <chrono>
#include <thread>
#include <ctime>
#include <chrono>
#include <sys/stat.h>

using namespace std;

//defaults for security features
int MAX = 1000;
int MAXREQUESTS = 3;
int MAXREQUESTSTIMELIMIT = 60;
int TIMEOUT = 60;
int MAXUSERS = 3;
int PORT = 2012;
#define SA struct sockaddr

//Part of parsing code from Evan Teran
template <typename Out>
void split(const std::string &s, char delim, Out result)
{
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim))
    {
        *result++ = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

//Part of Driver code from https://www.geeksforgeeks.org/tcp-server-client-implementation-in-c/
//Also some help from P3 partner Robert Eskridge
//Xirema on stack overflow was helpful with some of the clock functions
//Bunch of server code came from lecture too
// Main server code
int main(int argc, char *argv[])
{   
    if(argc>1)
		{PORT=atoi(argv[1]);}    
    //Opening up logs
    ofstream serverLogs;
	serverLogs.open("LoggingForServer.txt", ios_base::app);
    time_t time = chrono::system_clock::to_time_t(chrono::system_clock::now());
    serverLogs << "Server Initiated at port: " << PORT << ", during time " << ctime(&time) << endl;

    if(argc>2)
		{MAXREQUESTS=atoi(argv[2]);}
    if(argc>3)
		{MAXREQUESTSTIMELIMIT=atoi(argv[3]);}
    if(argc>4)
		{TIMEOUT=atoi(argv[4]);}
    if(argc>5)
		{MAXUSERS=atoi(argv[5]);}

    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        {printf("Socket successfully created..\n");}
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA *)&servaddr, sizeof(servaddr))) != 0)
    {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0)
    {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);
    int clientsConnected = 0;
    int totalClientsConnected = 0;

    while (1)
    {
        //logging - Dont allow more than max users to use our program at once, the program will not let the client connect until someonelse is done
        if(clientsConnected>MAXUSERS){            time = chrono::system_clock::to_time_t(chrono::system_clock::now());
            serverLogs << "Max Users exceeded at time: " << ctime(&time) << endl;}
        //Dont allow more than max users to use our program at once, the program will not let the client connect until someonelse is done
        while(clientsConnected>MAXUSERS){}
        int messagesRecievedWithinTimeFrame= 0;
        //Rate limiting implemented by every MAXREQUESTSTIMELIMIT seconds, reseting the amount we have sent back to 0
              chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    //Logging Rate Limiting
    if(MAXREQUESTS<messagesRecievedWithinTimeFrame){            
        time = chrono::system_clock::to_time_t(chrono::system_clock::now());
        serverLogs << "Rate limit violated with IP: " << inet_ntoa(cli.sin_addr) << ", during time " << ctime(&time) << endl;}
    if(std::chrono::steady_clock::now() - start > std::chrono::seconds(MAXREQUESTSTIMELIMIT)){messagesRecievedWithinTimeFrame= 0;}
    //We wait till we can send more messages
    while(MAXREQUESTS<messagesRecievedWithinTimeFrame){if(std::chrono::steady_clock::now() - start > std::chrono::seconds(MAXREQUESTSTIMELIMIT)){messagesRecievedWithinTimeFrame= 0;}}
    //TIMEOUT functionality
    //if(clientConnectedForMoreThen TIMEOUT){disconect client}
    //Log this event
        connfd = accept(sockfd, (SA *)&cli, (socklen_t *)&len);
        if (connfd < 0)
        {
            printf("server accept failed...\n");
            exit(0);
        }
        else
        {
            printf("server accept the client...\n");
            time = chrono::system_clock::to_time_t(chrono::system_clock::now());
            serverLogs << "Connection to client with IP: " << inet_ntoa(cli.sin_addr) << ", during time " << ctime(&time) << endl;
        }
        pid_t pid = fork();
        clientsConnected++;
        if (pid == 0)
        {
            //child
        time = chrono::system_clock::to_time_t(chrono::system_clock::now());
        serverLogs << "Connection closed with client with IP: " << inet_ntoa(cli.sin_addr) << ", during time " << ctime(&time) << endl;
            close(sockfd);
            // Function for recieving length
            char buff[MAX];
            recv(sockfd, buff, sizeof(buff), 0);
            u_int32_t length;
            u_int32_t bytesRecievedSoFar = 0;
            printf("Message length: %i\n", length);

            //Rate limiting implementation;
            messagesRecievedWithinTimeFrame++;
            //get length
            while (bytesRecievedSoFar < 4)
            {
                u_int32_t *buffer = &length;
                buffer += bytesRecievedSoFar;
                int cycle = recv(connfd, buffer, (4 - bytesRecievedSoFar), 0);
                bytesRecievedSoFar += cycle;
            }

            //check if message exeeds 4GB
            if (length > (1024 * 1024 * 1024 * 1))
            { //about 4GB
                exit(-1);
            }

            //parse message from client
            char *buffer = (char *)malloc(length);

            bytesRecievedSoFar = 0;
            while (bytesRecievedSoFar < length)
            {
                char *store = buffer;
                store += bytesRecievedSoFar;
                int cycle = recv(connfd, store, (length - bytesRecievedSoFar), 0);
                bytesRecievedSoFar += cycle;
            }

            FILE *file = fopen("QRCodeServerVersion.png", "wb");
            fwrite(buffer, sizeof(char), length, file);
            fclose(file);
            //use java program
            system("java -cp javase.jar:core.jar com.google.zxing.client.j2se.CommandLineRunner QRCodeServerVersion.png > output.txt"); //get URL from java package

            int counter = 0;
            char buffFM[MAX];
            fstream outCheck;
            outCheck.open("output.txt", ios::in);
            if (outCheck.is_open())
            {
                string currentLine;
                while (getline(outCheck, currentLine))
                {
                    counter++;
                    if (counter == 3)
                    {
                        strcpy(buffFM, currentLine.c_str());
                        //cout << buffFM << "heyooooo\n";
                    }
                    //cout << currentLine << "\n";
                }
                outCheck.close();
            }

            printf("starting response\n");
            //send back to client
            send(connfd, buffFM, sizeof(buffFM), 0);
            printf(buffFM);
            printf("size of buf %d\n", sizeof(buffFM));
            //Client not connected anymore
            clientsConnected--;
            exit(0);
        }
        else if (pid < 0)
        {
            printf("O.o");
        }
        else
        {
            //parent
            close(connfd);
            totalClientsConnected++;
        }
        //wait
    }	
    serverLogs.close();

}