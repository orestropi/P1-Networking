#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <fstream>

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