//Client side
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
#define MAX 1000
int PORT =  2012;
#define SA struct sockaddr
using namespace std;
// int main(int argc, char const *argv[]){
//     // int clientSocket;
//     // char buffer[1024];
//     // // need a variable for the server address
//     // socklen_t address_size;


//     // //Connect the socket to the server
//     // connect(clientSocket, /server address/, address_size);
//     // //Recive message from the server
//     // recv(clientSocket,buffer,1024,0);
//     // //Add information to text file
//     // std::ofstream outfile ("test.txt");
//     // outfile << buffer << std::endl;
//     // outfile.close();

//     // return 0; //success

// }

void func(int sockfd)
{
    char buff[MAX];
    int n;
    for (;;) {
        bzero(buff, sizeof(buff));
        printf("Enter the string : ");
        n = 0;
        while ((buff[n++] = getchar()) != '\n')
            ;
        write(sockfd, buff, sizeof(buff));
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("From Server : %s", buff);
        if ((strncmp(buff, "exit", 4)) == 0) {
            printf("Client Exit...\n");
            break;
        }
    }
}
   
int main(int argc, char *argv[])
{
    char* mainIP = argv[1];
	char* QRCodeFileName=argv[2];
	if(argc>3)
		{PORT=atoi(argv[3]);}
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;
   
    // socket create and varification
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
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);
   
    // connect the client socket to server socket
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
        printf("connection with the server failed...\n");
        exit(0);
    }
    else
        printf("connected to the server..\n");
    //Reading QR CODE File
    ifstream file;
	file.open(QRCodeFileName, ios::binary);
	file.seekg(0, ios::end);
	u_int32_t fileLength = file.tellg();
	char *fileBuffer = new char[fileLength];
	file.seekg(0, ios::beg);
	file.read(fileBuffer, fileLength);
	file.close();

	send(sockfd, &fileLength, 4, 0);

    send(sockfd, fileBuffer, fileLength, 0);



    // function for chat
    //func(sockfd);
   u_int32_t recievedBytesSoFar = 0;
	u_int32_t retCode;
	// while(recievedBytesSoFar < 4){
	// 	u_int32_t *placeToPutNewBytes = &retCode;
	// 	placeToPutNewBytes += recievedBytesSoFar;
	// 	int thisRound = recv(sockfd, placeToPutNewBytes, (4 - recievedBytesSoFar), 0);
	// 	recievedBytesSoFar += thisRound;
	// }
char buffFM[MAX];
        //bzero(buffFM, sizeof(buffFM));
        int counter = 0;
        while(counter==0){
        if(recv(sockfd, buffFM, sizeof(buffFM),0)>0){
        printf(buffFM);
        counter++;}
        }
	if(retCode == 1){
		return 0;
	}else{        
        
}

		
        
        
        //fflush(stdout);
		close(sockfd);
		exit(0);
	
    // close the socket
    close(sockfd);
}