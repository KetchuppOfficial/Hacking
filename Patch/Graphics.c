#include "Graphics.h"

#define _$ "\033[0m"
#define _B "\033[46m"
#define _G "\033[32m"
#define _Y "\033[33m"

#define SET(x, y) printf ("\033[%d;%dH", x, y)

#define Print_(string)      \
do                          \
{                           \
    printf ("%s", string);  \
    SET (0, 0);             \
}                           \
while (0)

const char frame[] = {
"                                          "_Y",---.           ,---.                                                                  \n"
"                                         / /\"`.\\.--\"\"\"--./,\'\"\\ \\                                                            \n"
"                                         \\ \\    _       _    / /                                                                   \n"
"                                          `./  / __   __ \\  \\,\'                                                                   \n"
"                                           /    /_O)_(_O\\    \\                                                                     \n"
"                                           |  .-\'  ___  `-.  |                                                                      \n"
"                                        .--|       \\_/       |--.                                                                   \n"
"                                      ,\'    \\   \\   |   /   /    `.                                                               \n"
"                                     /       `.  `--^--\'  ,\'       \\                                                              \n"
"                                 .-\"\"\"\"\"-.     `--.___.--\'    .-\"\"\"\"\"-."_$"                                               \n"
"                    "_G".-----------"_Y"/         \\"_G"------------------"_Y"/         \\"_G"--------------.                        \n"
"                    | .---------"_Y"\\         /"_G"----------------- "_Y"\\         /"_G"------------. |                            \n"
"                    | |"_B"          "_$ _Y"`-`--`--'"_$ _B"                    "_$ _Y"`--'--'-'"_$ _B"             "_$ _G"| |       \n"
"                    | |"_B"                                                             "_$ _G"| |                                   \n"
"                    | |"_B"                                                             "_$ _G"| |                                   \n"
"                    | |"_B"                                                             "_$ _G"| |                                   \n"
"                    | |"_B"                                                             "_$ _G"| |                                   \n"
"                    | |"_B"                                                             "_$ _G"| |                                   \n"
"                    | |"_B"                                                             "_$ _G"| |                                   \n"
"                    | |"_B"                                                             "_$ _G"| |                                   \n"
"                    | |"_B"                                                             "_$ _G"| |                                   \n" 
"                    | |"_B"                                                             "_$ _G"| |                                   \n"
"                    | |"_B"                                                             "_$ _G"| |                                   \n"
"                    | |"_B"                                                             "_$ _G"| |                                   \n"
"                    | |"_B"                                                             "_$ _G"| |                                   \n"
"                    | |"_B"_____________________________________________________________"_$ _G"| |                                   \n"
"                    |_________________________________________________________________|                                              \n"
"                                        "_Y")__________|__|__________(                                                               \n"
"                                       |            ||            |                                                                  \n" 
"                                       |____________||____________|                                                                  \n"
"                                         ),-----.(      ),-----.(                                                                    \n"
"                                        ,\'   ==.   \\   /  .==    `.                                                                \n"
"                                       /            ) (            \\                                                                \n"
"                                       `===========\'   \'===========\'                                                              \n"};

const char greeting[] = "\033[1;34;46m DOLGOV ALEXANDER PRESENTS...";
//                           ./  \.  \.
//                          ./    \.   turquoise (бирюзовый) background
//                         ./      \.
//                 bold text        blue text

const char title[]    = "\033[1;34;46m MEGA PATCHING!";

const char ending[]   = "\033[1;35;46m PATCHING DONE!!!"_$;
//                            ./ \.        \.
//                           ./   \.         purple text
//                          ./     \.
//                  22th line       46th column

void ASCII_Art (void)
{
    system ("clear");
    
    Print_ (frame);
    Print_Greeting ();

    Print_Timer ();

    Print_Ending ();
}

void Print_Greeting (void)
{
    SET (16, 39);
    Print_ (greeting);

    fflush (stdout);
    sleep (1);

    SET (17, 46);

    Print_ (title);

    fflush (stdout);
    sleep (1);
}

void Print_Timer (void)
{
    SET (20, 42);
    
    for (int i = 5; i >= 0; i--)
    {
        printf ("\033[1;31;46m%d SECONDS BEFORE PATCHING"_$, i);

        SET (5, 50);
        if (i % 2 == 0)
        {
            printf (_Y"O_");
            SET (5, 55);
            printf (_Y"O_");
        }
        else
        {
            printf (_Y"_O");
            SET (5, 55);
            printf (_Y"_O");
        }
        SET (0, 0);

        fflush (stdout);
        SET (20, 42);
        
        sleep (1);
    }
}

void Print_Ending (void)
{
    SET (22, 46);
    printf ("%s", ending);
    SET (36, 0);
}
