# P1-Networking
https://ia.wpi.edu/cs3516/resources.php?page=show_project&id=7

Final:

All tasks are attempted and implemented

FYI:This was only tested for the QRCode png file given to us(stored in directory)

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
