socket:

	CC = g++
	CFLAGS = -I.
	TARGET = test_socket
	LIBS = -lEposCmd

	$(TARGET): $(TARGET).cpp
	$(CC) -o $(TARGET) $(TARGET).cpp $(CFLAGS) $(LIBS)

example:

	CC = g++
	CFLAGS = -I.
	TARGET = HelloEposCmd
	LIBS = -lEposCmd

	$(TARGET): $(TARGET).cpp
	$(CC) -o $(TARGET) $(TARGET).cpp $(CFLAGS) $(LIBS)

