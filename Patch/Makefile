CC = gcc
CFLAGS = -c -Wall -Werror -Wextra

SYSTEM = WINDOWS

ifeq ($(SYSTEM), LINUX)

# For Linux
# ----------------------------------------------------------------------------
all: Linux

Linux: main.o Graphics.o
	$(CC) main.o Graphics.o ../../../C/My_Lib/My_Lib.a -o Patch.out
	rm main.o
	rm Graphics.o

run:
	./Patch.out /mnt/d/DOSBox/Bin/TASM/CRACK.COM

clean:
	rm Patch.out
	rm *.log
# ----------------------------------------------------------------------------

endif

ifeq ($(SYSTEM), WINDOWS)

# For Windows
# ----------------------------------------------------------------------------
all: Windows

Windows: main.o Graphics.o My_Lib.o
	$(CC) main.o Graphics.o My_Lib.o "C:\Windows\System32\winmm.dll" -o Patch.exe
	del main.o
	del Graphics.o
	del My_Lib.o

My_Lib.o:
	$(CC) $(CFLAGS) My_Lib/My_Lib.c -o My_Lib.o

run:
	Patch.exe "D:\DOSBox\Bin\TASM\CRACK.COM"

clean:
	del Patch.exe
	del *.log
# ----------------------------------------------------------------------------

endif

main.o:
	$(CC) $(CFLAGS) main.c -o main.o 

Graphics.o:
	$(CC) $(CFLAGS) Graphics.c -o Graphics.o
