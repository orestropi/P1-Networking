#include <iostream>
#include <thread>
#include <sys/socket.h>
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

//(part 1)
class read_in{
    ifstream file;
    char* filename;
    file.open(filename, ios::binary | ios::in))
    //file.reAD(&)
int front = socket(domain, type, protocol)
std::thread obj()
}
