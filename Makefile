CC=c++
CFLAGS="-std=c++11"
INCLUDES="include"

all: midterm

midterm: main.c
	$(CC) $(CFLAGS) -o midterm main.c
