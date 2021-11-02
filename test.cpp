#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <fstream>
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
    uintmax_t size = file_size(filename);
    //Function that reads in file
    void read(std::ifstream file, char* filename)
    {
  
    //opens file
    file.open(filename, ios::binary | ios::in);
    //reads in file based on size in bits
    file.read(&x, sizeof(x));
    file.seekp(0,ios::end);
   // file
    }
    //makes a socket ??
    //int front = socket(domain, type, protocol)
    //Creates main thread and calls read function
    thred th(read, file, filename);
}



