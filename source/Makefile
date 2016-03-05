CC=c++
CFLAGS="-std=c++11"
INCLUDES=../include
BINARIES=items.o container.o

all: items.o container.o

clean:
	rm -f $(BINARIES)

items.o: items.cpp $(INCLUDES)/items.h
	$(CC) $(CFLAGS) -c items.cpp

container.o: container.cpp $(INCLUDES)/container.h
	$(CC) $(CFLAGS) -c container.cpp

