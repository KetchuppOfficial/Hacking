#include "Patch.h"

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
            MY_ASSERT (false, "inc argc", NOT_ENOUGH_ARGS, Error);
    }

    long n_symbs = Define_File_Size (file);
    MY_ASSERT (n_symbs != ERROR, "Define_File_Size ()", FUNC_ERROR, Error);

    char *buffer = Make_Buffer (file, n_symbs);
    MY_ASSERT (buffer, "char *buffer", NE_MEM, Error);

    buffer[0x00D0] = 0xA9; // changes one byte to turn one function into another

    Close_File (file, argv[1]);
    file = Open_File (argv[1], "wb");

    fwrite (buffer, sizeof (char), n_symbs, file);
    
    free (buffer);
    Close_File (file, argv[1]);

    ASCII_Art ();

    return 0;
}