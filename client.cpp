//Client side
#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <fstream>
#include <sys/stat.h>
#include <ios>
#include <stdlib.h>
#include <stdio.h>
#include <string>

int main(int argc, char const *argv[]){
    int clientSocket;
    char buffer[1024];
    // need a variable for the server address
    socklen_t address_size;


    //Connect the socket to the server
    connect(clientSocket, /server address/, address_size);
    //Recive message from the server
    recv(clientSocket,buffer,1024,0);
    //Add information to text file
    std::ofstream outfile ("test.txt");
    outfile << buffer << std::endl;
    outfile.close();

    return 0; //success

}

