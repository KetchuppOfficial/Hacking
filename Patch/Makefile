CC = gcc
CFLAGS = -c -Wall -Werror -Wextra

all: Patch

Patch: Patch.o Graphics.o
	$(CC) Patch.o Graphics.o ../../../C/My_Lib/My_Lib.a -o Patch.out
	rm Patch.o
	rm Graphics.o

Patch.o:
	$(CC) $(CFLAGS) Patch.c -o Patch.o

Graphics.o:
	$(CC) $(CFLAGS) Graphics.c -o Graphics.o

run:
	./Patch.out /mnt/d/DOSBox/Bin/TASM/CRACK.COM

clean:
	rm log_file.log
	rm Patch.out
