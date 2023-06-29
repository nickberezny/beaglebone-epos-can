CC = g++
CFLAGS = -I.
TARGET = test_socket
LIBS = -lEposCmd

socket:
	test_socket: test_socket.cpp
	$(CC) -o test_socket test_socket.cpp $(CFLAGS) $(LIBS)

example:
	HelloEposCmd: HelloEposCmd.cpp
	$(CC) -o HelloEposCmd HelloEposCmd.cpp $(CFLAGS) $(LIBS)

