#ifndef PATCH_H_INCLUDED
#define PATCH_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WINDOWS

#ifdef WINDOWS
#include <Windows.h>
#include "My_Lib/My_Lib.h"
#endif

#ifdef LINUX
#define Error ERROR
#include "../../../C/My_Lib/My_Lib.h"
#endif

void ASCII_Art      (void);
void Print_Greeting (void);
void Print_Timer    (void);
void Print_Ending   (void);

#endif