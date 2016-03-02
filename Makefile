CC=c++
CFLAGS="-std=c++11"
INCLUDES="include"

all: midterm

items.o:
	$(MAKE) -C source items.o

midterm: main.c
	$(CC) $(CFLAGS) -o midterm main.c
