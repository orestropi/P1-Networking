#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <fstream>
#include <sys/stat.h>
#include <ios>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;
int main(){
    int parent_sock=0;
    int total = 0;
    struct sockaddr *address;
    socklen_t *addresslen = ;
    int clientNum = listen(parent_sock,clientNum);
    while(1){
    
    int client = accept(parent_sock, address,addresslen);  
    pid_t returnValue = fork();
    if(returnValue == 0){
        read_in::handleClient();
    }
    else if(returnValue<0){
        //return error message
    }else{
        //
        ++total;
    }


    
    }
   
    

    return 0; // success
}

class read_in{
    char x;
    std::ifstream file; //File being passed in
    char* filename; //file name
    uintmax_t size = file.tellg();
    u_int32_t socketIn, newSocket;
    char buffer[1024];
//Decoding QR Code using Ssystem(part 2)
void handleClient(){
    u_int32_t length;
socketIn = socket(PF_INET, SOCK_STREAM,0);
    recv(socketIn, &length, 4, 0);
    
    u_int32_t bytesRecievedSoFar = 0;
    u_int32_t bytesActuallyRecieved;
    while (bytesRecievedSoFar < length){
    bytesActuallyRecieved = recv(socketIn, (buffer+bytesRecievedSoFar/(sizeof(u_int32_t))), length-bytesRecievedSoFar, 0);
    bytesRecievedSoFar += bytesActuallyRecieved;
    }


    //char* URL = qrDecode
//read_in::read()
    buffer = qrDecode()
//send URL
    send(newSocket, buffer, len(buffer), 0);

    return 0; // success
}
int qrDecode()
{
 const char imageFile = read(file,filename);
  int i;
  printf ("Checking if processor is available...");
  if (system(NULL)) puts ("Ok");
    else exit (EXIT_FAILURE);
  printf ("Parsing QR Code ...\n");
  i=system ("java -cp javase.jar:core.jar com.google.zxing.client.j2se.CommandLineRunner " + imageFile);
  printf ("Parsed result: %d.\n",i);
  return 0;
}


    //Function that reads in file
    const char read(std::ifstream file, char* filename)
    {
        int upperBound = 1431655765; //A third of 4 GB
        if(file.tellg()-1>upperBound){
            int errorSocket = socket(1,0,0);
            connect(errorSocket, /*client address,address size*/);
        }
        const char imageFile = 0;
        // Opening a file way 1
        //std::ifstream myfile(filename, ios::in|ios::binary);
    //opens file way 2
    file.open(filename, ios::binary | ios::in);
    //ios is a class so I don't know why thats throwing an error
    //reads in file based on size in bits -> Probably going to change to mach the ifstream
    // Set read to imagefile variable
    file.read(&x, sizeof(x));
    //Should keep track of position in file, hopefully based on bit position
    //file.seekp(0,ios::end);
   // file
   //This is how we'll call the qr code function
   return imageFile;
    }
    //makes a socket ??
    //int front = socket(domain, type, protocol)
    //Creates main thread and calls qrDecode function
}

/*
//from fridays class
//Psuedocode for another method we might want to use
class read_in2{
    u_int32_t length;
    char buffer[10000];
    //technically want to recieve in loop as well
    recv(sock, &length, 4, 0);
// recv length bytes
    u_int32_t bytesRecievedSoFar = 0;
    while (bytesRecievedSoFar < length){
    bytesActuallyRecieve = recv(sock, (buffer+bytesRecievedSoFar/(sizeof(u_int32_t))), length-bytesRecievedSoFar, 0);
    bytesRecievedSoFar += bytesActuallyRecieve;
}
    //opens file
    file.open(filenameExample, ios::binary | ios::in);
    //write buffer into file
    file.write(buffer);
    //Close file  
    file.close();
}


//Decoding QR code
if (qrDecode(filenameExample) == 0){printf ("Parsed result: %d.\n",i);
}else{printf('invalid QR Code')}*/
