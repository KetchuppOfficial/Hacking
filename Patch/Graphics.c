#include "Patch.h"

#define $ "\033[0m"
#define B "\033[46m"
#define G "\033[32m"
#define Y "\033[33m"

#define BoGT "\033[1;33;46m" // Bold, green text; turquoise background
#define BoPT "\033[1;35;46m" // Bold, purple text; turquoise background
#define BoRT "\033[1;31;46m" // Bold, red text; turquoise background

#define Set(x, y) printf ("\033[%d;%dH", x, y)

#define Print_(string)      \
do                          \
{                           \
    printf ("%s", string);  \
    Set (0, 0);             \
}                           \
while (0)

const char frame[] = {
"                                          "Y",---.           ,---.                                                                \n"
"                                         / /\"`.\\.--\"\"\"--./,\'\"\\ \\                                                         \n"
"                                         \\ \\    _       _    / /                                                                \n"
"                                          `./  / __   __ \\  \\,\'                                                                \n"
"                                           /    /_O)_(_O\\    \\                                                                  \n"
"                                           |  .-\'  ___  `-.  |                                                                   \n"
"                                        .--|       \\_/       |--.                                                                \n"
"                                      ,\'    \\   \\   |   /   /    `.                                                            \n"
"                                     /       `.  `--^--\'  ,\'       \\                                                           \n"
"                                 .-\"\"\"\"\"-.     `--.___.--\'    .-\"\"\"\"\"-."$"                                             \n"
"                    "G".-----------"Y"/         \\"G"------------------"Y"/         \\"G"--------------.                          \n"
"                    | .---------"Y"\\         /"G"----------------- "Y"\\         /"G"------------. |                             \n"
"                    | |"B"          "$ Y"`-`--`--'"$ B"                    "$ Y"`--'--'-'"$ B"             "$ G"| |               \n"
"                    | |"B"                                                             "$ G"| |                                   \n"
"                    | |"B"                                                             "$ G"| |                                   \n"
"                    | |"B"                                                             "$ G"| |                                   \n"
"                    | |"B"                                                             "$ G"| |                                   \n"
"                    | |"B"                                                             "$ G"| |                                   \n"
"                    | |"B"                                                             "$ G"| |                                   \n"
"                    | |"B"                                                             "$ G"| |                                   \n"
"                    | |"B"                                                             "$ G"| |                                   \n" 
"                    | |"B"                                                             "$ G"| |                                   \n"
"                    | |"B"                                                             "$ G"| |                                   \n"
"                    | |"B"                                                             "$ G"| |                                   \n"
"                    | |"B"                                                             "$ G"| |                                   \n"
"                    | |"B"_____________________________________________________________"$ G"| |                                   \n"
"                    |_________________________________________________________________|                                           \n"
"                                        "Y")__________|__|__________(                                                             \n"
"                                       |            ||            |                                                               \n" 
"                                       |____________||____________|                                                               \n"
"                                         ),-----.(      ),-----.(                                                                 \n"
"                                        ,\'   ==.   \\   /  .==    `.                                                             \n"
"                                       /            ) (            \\                                                             \n"
"                                       `===========\'   \'===========\'                                                           \n"};

#undef B
#undef G

const char greeting[] = BoGT"DOLGOV ALEXANDER PRESENTS...";

const char title[]    = BoGT"MEGA PATCHING!";

const char ending[]   = BoPT"PATCHING DONE!!!"$;


void ASCII_Art (void)
{
    #ifdef LINUX
    system ("clear");
    #endif
    
    #ifdef WINDOWS
    system ("cls");
    mciSendString("play Mario.mp3 repeat", NULL, 0, NULL);
    #endif
    
    Print_ (frame);
    Print_Greeting ();

    Print_Timer ();

    Print_Ending ();
}

void Print_Greeting (void)
{
    Set (16, 39);
    Print_ (greeting);

    fflush (stdout);
    sleep (1);

    Set (17, 46);

    Print_ (title);

    fflush (stdout);
    sleep (1);
}

void Print_Timer (void)
{
    Set (20, 42);
    
    for (int i = 5; i >= 0; i--)
    {
        printf (BoRT"%d SECONDS BEFORE PATCHING"$, i);

        Set (5, 50);
        if (i % 2 == 0)
        {
            printf (Y"O_");
            Set (5, 55);
            printf (Y"O_");
        }
        else
        {
            printf (Y"_O");
            Set (5, 55);
            printf (Y"_O");
        }
        Set (0, 0);

        fflush (stdout);
        Set (20, 42);
        
        sleep (1);
    }
}

#undef $
#undef Y

void Print_Ending (void)
{
    Set (22, 46);
    printf ("%s", ending);
    Set (36, 0);
}
