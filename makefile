
all: client.o server.o
	g++ client.cpp -o client
	g++ server.cpp -o server

clean:
	$(RM) client client.o server server.o