#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFF_LEN 0x83   // 131 in decimal - capacity of the password buffer

int main (void)
{
    FILE *file = fopen ("/mnt/d/DOSBox/Bin/TASM/Password.txt", "wb");

    char function[] = {0xFA, 0xDB, 0xB1, 0x53, 0xBF, 0x00, 0x00, 0xB4, 0x3F, 0xB9, 0x01, 0x00, 0xBA, 
                       0x08, 0x10, 0xCD, 0x21, 0x3D, 0x00, 0x00, 0x74, 0x15, 0x90, 0x90, 0x8A, 0x26, 
                       0x08, 0x10, 0x88, 0xA5, 0x09, 0x10, 0x47, 0x3B, 0x3E, 0x8A, 0x10, 0x73, 0x04, 
                       0x90, 0x90, 0xEB, 0xDC, 0xC6, 0x06, 0x89, 0x10, 0x00, 0xE8, 0x06, 0xF1, 0xC3};

    char *buffer = (char *)calloc (BUFF_LEN + sizeof function, sizeof (char));

    buffer[BUFF_LEN - 2] = 0xFF;
    buffer[BUFF_LEN - 1] = 0xFF;

    memmove (buffer + BUFF_LEN, function, sizeof function);

    fwrite (buffer, sizeof (char), BUFF_LEN + sizeof function, file);

    free (buffer);
    fclose (file);
    
    return 0;
}