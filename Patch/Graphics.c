#include "Graphics.h"

const char frame[] = {
"                                          \033[33m,---.           ,---.                           \n"
"                                         / /\"`.\\.--\"\"\"--./,\'\"\\ \\                 \n"
"                                         \\ \\    _       _    / /                        \n"
"                                          `./  / __   __ \\  \\,\'                        \n"
"                                           /    /_O)_(_O\\    \\                          \n"
"                                           |  .-\'  ___  `-.  |                           \n"
"                                        .--|       \\_/       |--.                        \n"
"                                      ,\'    \\   \\   |   /   /    `.                    \n"
"                                     /       `.  `--^--\'  ,\'       \\                   \n"
"                                 .-\"\"\"\"\"-.     `--.___.--\'    .-\"\"\"\"\"-.\033[0m        \n"
"                    \033[32m.-----------\033[33m/         \\\033[32m------------------\033[33m/         \\\033[32m--------------. \n"
"                    | .---------\033[33m\\         /\033[32m----------------- \033[33m\\         /\033[32m------------. |\n"
"                    | |\033[46m          \033[0m\033[33m`-`--`--'\033[0m\033[46m                    \033[0m\033[33m`--'--'-'\033[0m\033[46m             \033[0m\033[32m| |   \n"
"                    | |\033[46m                                                             \033[0m\033[32m| |   \n"
"                    | |\033[46m                                                             \033[0m\033[32m| |   \n"
"                    | |\033[46m                                                             \033[0m\033[32m| |   \n"
"                    | |\033[46m                                                             \033[0m\033[32m| |   \n"
"                    | |\033[46m                                                             \033[0m\033[32m| |   \n"
"                    | |\033[46m                                                             \033[0m\033[32m| |   \n"
"                    | |\033[46m                                                             \033[0m\033[32m| |   \n"
"                    | |\033[46m                                                             \033[0m\033[32m| |   \n" 
"                    | |\033[46m                                                             \033[0m\033[32m| |   \n"
"                    | |\033[46m                                                             \033[0m\033[32m| |   \n"
"                    | |\033[46m                                                             \033[0m\033[32m| |   \n"
"                    | |\033[46m                                                             \033[0m\033[32m| |   \n"
"                    | |\033[46m_____________________________________________________________\033[0m\033[32m| |   \n"
"                    |_________________________________________________________________|                          \n"
"                                        \033[33m)__________|__|__________(                                       \n"
"                                       |            ||            |                                              \n" 
"                                       |____________||____________|                                              \n"
"                                         ),-----.(      ),-----.(                                                \n"
"                                        ,\'   ==.   \\   /  .==    `.                                            \n"
"                                       /            ) (            \\                                            \n"
"                                       `===========\'   \'===========\'                                          \n"};

const char greeting[] = "\033[1;34;46m DOLGOV ALEXANDER PRESENTS...";
//                           ./  \.  \.
//                          ./    \.   turquoise (бирюзовый) background
//                         ./      \.
//                 bold text        blue text

const char title[]    = "\033[1;34;46m MEGA PATCHING!";

const char ending[]   = "\033[22;46H\033[1;35;46m PATCHING DONE!!!\033[0m";
//                            ./ \.        \.
//                           ./   \.         purple text
//                          ./     \.
//                  22th line       46th column

void ASCII_Art (void)
{
    system ("clear");
    
    Print_Frame ();
    Print_Greeting ();

    Print_Timer ();

    printf ("%s\033[36;0H", ending);
    //              \.   \.
    //               \.   0th column
    //                \.
    //                  16~th line
}

void Print_Frame (void)
{
    printf ("%s\n", frame);

    printf ("\033[0;0H");
    //             \. \.
    //              top left corner
}

void Print_Greeting (void)
{
    printf ("\033[16;39H");
    //             \.     \.
    //              \.      39th column
    //               \.
    //                 16th line

    printf ("%s\033[0;0H", greeting);

    fflush (stdout);
    sleep (1);

    printf ("\033[17;46H");
    //             \.     \.
    //              \.      46 cells forward
    //               \.
    //                 set cursor in the beginning of the next line

    printf ("%s\033[0;0H", title);
    //               \. \.
    //               top left corner

    fflush (stdout);
    sleep (1);
}

void Print_Timer (void)
{
    printf ("\033[20;42H");
    //             \.  \.
    //              \.   42th column
    //               \.
    //                 20th line
    
    for (int i = 5; i >= 0; i--)
    {
        printf ("\033[1;31;46m%d SECONDS BEFORE PATCHING\033[0m", i);

        if (i % 2 == 0)
            printf ("\033[5;50H\033[33mO_\033[5;55H\033[33mO_\033[0;0H");
        else
            printf ("\033[5;50H\033[33m_O\033[5;55H\033[33m_O\033[0;0H");

        fflush (stdout);
        printf ("\033[20;42H");
        
        sleep (1);
    }
}
