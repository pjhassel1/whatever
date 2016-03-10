CC=c++
CFLAGS=-std=c++11 -g
INCLUDES=include
BINARIES=source/items.o source/container.o source/room.o source/setup_map.o \
	source/utility.o source/map.o

all: midterm

.PHONY: clean
clean:
	$(MAKE) -C source clean
	rm -f midterm

.PHONY: source
source:
	$(MAKE) -C source

main.cpp:
	$(MAKE) -c main.cpp

midterm: source main.cpp
	$(MAKE) -C source all
	$(CC) $(CFLAGS) -o midterm main.cpp $(BINARIES)
