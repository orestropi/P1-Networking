// #include <iostream>
// #include <thread>
// #include <sys/socket.h>
// #include <fstream>
// #include <sys/stat.h>
// #include <ios>
// #include <stdlib.h>
// #include <stdio.h>
// #include <string>
// #include <sys/wait.h>
// #include <unistd.h>


// using namespace std;
// int main(int argc, char const *argv[]){
//     return 0;}
// //     int parent_sock=0;
// //     int total = 0;
// //     struct sockaddr *address;
// //     socklen_t *addresslen = ;
// //     int clientNum = listen(parent_sock,clientNum);
// //     while(1){
    
// //     int client = accept(parent_sock, address,addresslen);  
// //     pid_t returnValue = fork();
// //     if(returnValue == 0){
// //         read_in::handleClient();
// //     }
// //     else if(returnValue<0){
// //         //return error message
// //     }else{
// //         //
// //         ++total;
// //     }


    
// //     }
   
    

// //     return 0; // success
// // }

// // class read_in{
// //     public:
// //     char x;
// //     std::ifstream file; //File being passed in
// //     char* filename; //file name
// //     uintmax_t size = file.tellg();
// //     u_int32_t socketIn, newSocket;
// //     char buffer[1024];
// // //Decoding QR Code using Ssystem(part 2)
// // void handleClient(){
// //     u_int32_t length;
// // socketIn = socket(PF_INET, SOCK_STREAM,0);
// //     recv(socketIn, &length, 4, 0);
    
// //     u_int32_t bytesRecievedSoFar = 0;
// //     u_int32_t bytesActuallyRecieved;
// //     while (bytesRecievedSoFar < length){
// //     bytesActuallyRecieved = recv(socketIn, (buffer+bytesRecievedSoFar/(sizeof(u_int32_t))), length-bytesRecievedSoFar, 0);
// //     bytesRecievedSoFar += bytesActuallyRecieved;
// //     }


// //     char* URL = qrDecode();
// // //read_in::read()
// //    // buffer = qrDecode()
// // //send URL
// //    // newSocket = socket()
// //     send(newSocket, URL,URL.length(), 0);

// //     return 0; // success
// // }
// // char* qrDecode()
// // {
// //  const char imageFile = read(file,filename);
// //   char* i;
// //   printf ("Checking if processor is available...");
// //   if (system(NULL)) puts ("Ok");
// //     else exit (EXIT_FAILURE);
// //   printf ("Parsing QR Code ...\n");
// //   i =system ("java -cp javase.jar:core.jar com.google.zxing.client.j2se.CommandLineRunner " + imageFile);
// //   printf ("Parsed result: %d.\n",i);
// //   return i;
// // }


// //     //Function that reads in file
// //     const char read(std::ifstream file, char* filename)
// //     {
// //         int upperBound = 1431655765; //A third of 4 GB
// //         if(file.tellg()-1>upperBound){
// //             int errorSocket = socket(1,0,0);
// //             connect(errorSocket, /*client address,address size*/);
// //         }
// //         const char imageFile = 0;
// //         // Opening a file way 1
// //         //std::ifstream myfile(filename, ios::in|ios::binary);
// //     //opens file way 2
// //     file.open(filename, ios::binary | ios::in);
// //     //ios is a class so I don't know why thats throwing an error
// //     //reads in file based on size in bits -> Probably going to change to mach the ifstream
// //     // Set read to imagefile variable
// //     file.read(&x, sizeof(x));
// //     //Should keep track of position in file, hopefully based on bit position
// //     //file.seekp(0,ios::end);
// //    // file
// //    //This is how we'll call the qr code function
// //    return imageFile;
// //     }
// //     //makes a socket ??
// //     //int front = socket(domain, type, protocol)
// //     //Creates main thread and calls qrDecode function
// // };

// /*
// //from fridays class
// //Psuedocode for another method we might want to use
// class read_in2{
//     u_int32_t length;
//     char buffer[10000];
//     //technically want to recieve in loop as well
//     recv(sock, &length, 4, 0);
// // recv length bytes
//     u_int32_t bytesRecievedSoFar = 0;
//     while (bytesRecievedSoFar < length){
//     bytesActuallyRecieve = recv(sock, (buffer+bytesRecievedSoFar/(sizeof(u_int32_t))), length-bytesRecievedSoFar, 0);
//     bytesRecievedSoFar += bytesActuallyRecieve;
// }
//     //opens file
//     file.open(filenameExample, ios::binary | ios::in);
//     //write buffer into file
//     file.write(buffer);
//     //Close file  
//     file.close();
// }

// //Decoding QR code
// if (qrDecode(filenameExample) == 0){printf ("Parsed result: %d.\n",i);
// }else{printf('invalid QR Code')}*/
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

#include <sys/stat.h>

using namespace std;

int MAX = 1000;
int MAXREQUESTS = 3;
int MAXREQUESTSTIMELIMIT = 60;
int TIMEOUT = 60;
int PORT =  2012;
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
// Function designed for chat between client and server.
void func(int sockfd)
{
    char buff[MAX];
    int n;

    // infinite loop for chat
    for (;;) {
        bzero(buff, MAX);
   
        // read the message from client and copy it in buffer
        recv(sockfd, buff, sizeof(buff),0);
        // print buffer which contains the client contents
        printf("From client: %s\t To client : ", buff);
        bzero(buff, MAX);
        n = 0;
        // copy server message in the buffer
        while ((buff[n++] = getchar()) != '\n')
            ;
   
        // and send that buffer to client
        send(sockfd, buff, sizeof(buff),0);
   
        // if msg contains "Exit" then server exit and chat ended.
        if (strncmp("exit", buff, 4) == 0) {
            printf("Server Exit...\n");
            break;
        }
    }
}
   
// Main server code
int main()
{
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;
   
    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));
   
    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
   
    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");
   
    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);
   
    // Accept the data packet from client and verification
    connfd = accept(sockfd, (SA*)&cli, (socklen_t *)&len);
    if (connfd < 0) {
        printf("server accept failed...\n");
        exit(0);
    }
    else
        printf("server accept the client...\n");
    int clientsConnected=0;
    // Function for recieving length
    char buff[MAX];
    recv(sockfd, buff, sizeof(buff),0);
	u_int32_t length;
	u_int32_t bytesRecievedSoFar = 0;
	printf("Message length: %i\n", length);

	//get length
	while(bytesRecievedSoFar < 4){
		u_int32_t *buffer = &length;
		buffer += bytesRecievedSoFar;
		int cycle = recv(connfd, buffer, (4-bytesRecievedSoFar),0);
		bytesRecievedSoFar += cycle;
	}

    //check input size
	if(length > (1 * 1024 * 1024 * 1024)){
		exit(-1);
	}

	//read message from client
	char *buffer = (char*)malloc(length);

	bytesRecievedSoFar = 0;
	while(bytesRecievedSoFar < length){
		char *placeToPutNewBytes = buffer;
		placeToPutNewBytes += bytesRecievedSoFar;
		int cycle =  recv(connfd, placeToPutNewBytes, (length - bytesRecievedSoFar), 0);
		bytesRecievedSoFar += cycle;
	}
	printf("Message length: %i\n", length);
	printf("Client Message: %s\n", buffer);

	FILE *file = fopen("transmitted.png", "wb");
	fwrite(buffer, sizeof(char), length, file);
	fclose(file);
	//call java package on transmitted file
    system("java -cp javase.jar:core.jar com.google.zxing.client.j2se.CommandLineRunner transmitted.png > output.txt");	//get URL from java package
    // After chatting close the socket







    char buffFM[MAX];
    std::vector<std::string> URLtoSendToClient;
    ifstream file("output.txt");
    if (file.is_open())
    {
        string line;
        int counter = 0;
        //Task 5: Longest Prefix Matching
        while (getline(file, line))
        {
            // note that the newline character is not included
            // in the getline() function
            if (counter == 3)
            {
                URLtoSendToClient = split(line, ' ');
                strcpy(buffFM, URLtoSendToClient[0].c_str());
                printf("line 1: ");
            }
            counter++;
        }
    }











    	printf("starting response\n");
	//send back to client
        strcpy(buffFM, "hello world");
        //memcpy(buffFM, "hello world", strlen("hello world"));
        //bzero(buffFM, sizeof(buffFM));
        send(connfd, buffFM, sizeof(buffFM),0);
	//fclose(fileOut);
        printf(buffFM);
        printf("size of buf %d",sizeof(buffFM));

    close(sockfd);
}