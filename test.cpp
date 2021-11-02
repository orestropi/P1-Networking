#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <fstream>
#include <sys/stat.h>
#include <ios>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;
class read_in{
    char x;
    std::ifstream file; //File being passed in
    char* filename; //file name
    uintmax_t size = file.tellg();
//Decoding QR Code using Ssystem(part 2)
int qrDecode()
{
  string imagefile = read(file,filename)
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
    string read(std::ifstream file, char* filename)
    {
        string imagefile;
        // Opening a file way 1
        //std::ifstream myfile(filename, ios::in|ios::binary);
    //opens file way 2
    file.open(filename, ios::binary | ios::in);
    //ios is a class so I don't know why thats throwing an error
    //reads in file based on size in bits -> Probably going to change to mach the ifstream
    // Set read to imagefile variable
    file.read(&x, sizeof(x));
    //Should keep track of position in file, hopefully based on bit position
    file.seekp(0,ios::end);
   // file
   //This is how we'll call the qr code function
   return imagefile;
    }
    //makes a socket ??
    //int front = socket(domain, type, protocol)
    //Creates main thread and calls qrDecode function
    std::thread th(read_in::qrDecode);
}


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
}else{printf('invalid QR Code')}

