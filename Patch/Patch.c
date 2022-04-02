#include <stdio.h>
#include "../../../C/My_Lib/My_Lib.h"

int main (int argc, char *argv[])
{
    OPEN_LOG_FILE;
    
    FILE *file = NULL;
    
    switch (argc)
    {
        case 2:
            file = Open_File (argv[1], "rb");
            break;

        default:
            MY_ASSERT (false, "inc argc", NOT_ENOUGH_ARGS, ERROR);
    }

    long n_symbs = Define_File_Size (file);
    MY_ASSERT (n_symbs != ERROR, "Define_File_Size ()", FUNC_ERROR, ERROR);

    char *buffer = Make_Buffer (file, n_symbs);
    MY_ASSERT (buffer, "char *buffer", NE_MEM, ERROR);

    buffer[0x00D0] = 0xA9; // changes one byte to turn one function into another

    Close_File (file, argv[1]);

    FILE *new_file = Open_File ("NewCrack.COM", "wb");

    fwrite (buffer, sizeof (char), n_symbs, new_file);
    
    free (buffer);
    Close_File (new_file, "NewCrack.COM");

    return 0;
}