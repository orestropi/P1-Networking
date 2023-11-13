# P1-Networking

How to Run the Program:

First run the command "make all" in the project directory

Then Initilize the server In any of these ways(in project directory):

1) ./server  [port number]  [RATE number requests] [RATE number seconds] [MAX USERS number of users]  [TIME OUT number of seconds]
2) ./server  [port number]  [RATE number requests] [RATE number seconds] [MAX USERS number of users]
3) ./server  [port number]  [RATE number requests] [RATE number seconds]
4) ./server  [port number]  [RATE number requests]
5) ./server  [port number]  
6) ./server  

Then Initilize as many clients as you want In any of these ways(in project directory):
1) ./client IPaddress QRCodeFileName [port number]
2) ./client IPaddress QRCodeFileName

Here is an example of multiple clients recieving a QR code->
![image](https://user-images.githubusercontent.com/73619173/146481972-4fc41309-012f-4c13-9d59-bc663cc57934.png)

Here is how the directory looks after two clients got their URLs:
![image](https://user-images.githubusercontent.com/73619173/146482072-ec5217e3-a533-4976-8967-ace5d33825de.png)

Here is the logging file output:
![image](https://user-images.githubusercontent.com/73619173/146482215-1166ec3e-fef5-42db-97a0-92f2429e8981.png)

Any Questions?
Contact me at:
phone:857-928-3387
email:oropi@wpi.edu
discord:Orest#5659

More Details:
1. Server Initialization:
   - The server listens on a specified port 
   - It supports command-line arguments to configure various parameters:
- maximum number of concurrent users
- maximum requests
- request time limit
- timeout for client connections.

2. Security Features:
   - The code includes parameters and settings for security features like maximum request limits, timeouts, and maximum user connections.

3. Forking for Multiple Clients:
   - The server uses forked processes to handle multiple clients concurrently. Each client connection is processed in a separate child process.
   - The parent process continues listening for new connections.

4. Connection Handling:
   - The server accepts incoming client connections using TCP sockets.
   - It maintains a count of connected clients and imposes limits on the maximum number of clients that can connect concurrently.

5. QR Code Processing:
   - The server receives QR code data from clients and stores it in a file named "QRCodeServerVersion.png."
   - It uses an external Java program to decode the QR code and extract a URL. The URL is written to an output file, "output.txt."

6. Error Handling:
   - The code includes error handling for various situations, such as when a connection fails or a received packet is too large.

7. Logging:
   - The server logs various events and activities, such as the initiation of the server, client connections, rate limit violations, and more. Logs are stored in a file named "LoggingForServer.txt."

8. External Dependencies:
   - The server relies on external tools and libraries, such as a Java program (possibly for QR code decoding), to accomplish specific tasks.

