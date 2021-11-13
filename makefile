
output: client.o server.o
	g++ client.o -o client
	g++ server.o -o server

client.o: client.cpp
	g++ -c client.cpp

server.o: server.cpp
	g++ -c server.cpp

make clean:
	rm *.o client server
