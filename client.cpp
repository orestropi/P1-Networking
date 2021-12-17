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

//Part of Driver code from https://www.geeksforgeeks.org/tcp-server-client-implementation-in-c/   
//Also some help from P3 partner   Robert Eskridge
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
    servaddr.sin_addr.s_addr = inet_addr(mainIP);
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
	u_int32_t retCode;
char buffFM[MAX];
        //bzero(buffFM, sizeof(buffFM));
        int counter = 0;
        while(counter==0){
        if(recv(sockfd, buffFM, sizeof(buffFM),0)>0){
        counter++;}
        }
	if(retCode == 1){
		return 0;
	}else{printf("\nThis is the URL Recieved from the server: %s\n", buffFM);
}

		
        
        
        //fflush(stdout);
		close(sockfd);
		exit(0);
	
    // close the socket
    close(sockfd);
}