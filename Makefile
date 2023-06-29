CC = g++
CFLAGS = -I.
TARGET = test_socket
LIBS = -lEposCmd

socket:
	$(CC) test_socket.cpp -o test_socket  $(CFLAGS) $(LIBS)

example:
	$(CC) HelloEposCmd.cpp -o HelloEposCmd  $(CFLAGS) $(LIBS)

