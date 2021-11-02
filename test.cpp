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

//Decoding QR Code using Ssystem(part 2)
int qrDecode (string imageFile)
{
  int i;
  printf ("Checking if processor is available...");
  if (system(NULL)) puts ("Ok");
    else exit (EXIT_FAILURE);
  printf ("Parsing QR Code ...\n");
  i=system ("java -cp javase.jar:core.jar com.google.zxing.client.j2se.CommandLineRunner " + imageFile);
  printf ("Parsed result: %d.\n",i);
  return 0;
}

class read_in{
    char x;
    std::ifstream file; //File being passed in
    char* filename; //file name
    uintmax_t size = file.tellg();
    //Function that reads in file
    void read(std::ifstream file, char* filename)
    {
        // Opening a file way 1
        //std::ifstream myfile(filename, ios::in|ios::binary);
    //opens file way 2
    file.open(filename, ios::binary | ios::in);
    //ios is a class so I don't know why thats throwing an error
    //reads in file based on size in bits -> Probably going to change to mach the ifstream
    file.read(&x, sizeof(x));
    //Should keep track of position in file, hopefully based on bit position
    file.seekp(0,ios::end);
   // file
    }
    //makes a socket ??
    //int front = socket(domain, type, protocol)
    //Creates main thread and calls read function
    thred th(read, file, filename);
}



