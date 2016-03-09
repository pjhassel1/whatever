CC=c++
CFLAGS="-std=c++11"
INCLUDES=../include
BINARIES=items.o container.o map.o setup_map.o room.o

all: $(BINARIES)

.PHONY: clean
clean:
	rm -f $(BINARIES)

items.o: items.cpp $(INCLUDES)/items.h
	$(CC) $(CFLAGS) -c items.cpp

container.o: container.cpp $(INCLUDES)/container.h $(INCLUDES)/items.h
	$(CC) $(CFLAGS) -c container.cpp

room.o: room.cpp $(INCLUDES)/room.h $(INCLUDES)/container.h $(INCLUDES)/items.h
	$(CC) $(CFLAGS) -c room.cpp

setup_map.o: setup_map.cpp $(INCLUDES)/setup_map.h $(INCLUDES)/map.h \
		$(INCLUDES)/container.h $(INCLUDES)/items.h $(INCLUDES)/room.h
	$(CC) $(CFLAGS) -c setup_map.cpp

map.o: map.cpp $(INCLUDES)/map.h $(INCLUDES)/container.h $(INCLUDES)/items.h \
		$(INCLUDES)/room.h
	$(CC) $(CFLAGS) -c map.cpp
