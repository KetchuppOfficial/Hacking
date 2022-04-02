CC = gcc
CFLAGS = -c -Wall -Werror -Wextra

all: Patch

Patch: Patch.o
	$(CC) Patch.o ../../../C/My_Lib/My_Lib.a -o Patch.out
	rm Patch.o

Patch.o:
	$(CC) $(CFLAGS) Patch.c -o Patch.o

run:
	./Patch.out ../Hacking_Artem/CRACK.COM

clean:
	rm log_file.log
	rm Patch.out
