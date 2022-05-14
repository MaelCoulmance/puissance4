// Copyright (C) 2022, Maël Coulmance

#ifndef PUISSANCE4_INIT_H
#define PUISSANCE4_INIT_H

#include <stddef.h>

#ifdef _MSC_VER
    #include <Windows.h>

    #define P4_WINDOWS_CONSOLE
    #define P4_SLEEP(Ms)                        Sleep(Ms)
    #define P4_SCANF(FMT, VAR, BUFLEN)          scanf_s(FMT, VAR, BUFLEN)

#elif (defined(__GNUC__) || defined(__clang__) || defined(__MINGW32__)) && defined(_WIN32)
    #include <windows.h>
    #include <unistd.h>

    #define P4_WINDOWS_CONSOLE
    #define P4_SLEEP(Ms)                        sleep((Ms)/1000)
    #define P4_SCANF(FMT, VAR, BUFLEN)          scanf_s(FMT, VAR, BUFLEN)

#else 
    #include <unistd.h>

    #define P4_SLEEP(Ms)                        sleep((Ms)/1000)
    #define P4_SCANF(FMT, VAR, BUFLEN)          scanf(FMT, VAR)

#endif 


#ifdef P4_WINDOWS_CONSOLE
    #define P4_CLEAR_CONSOLE    printf("\x1b[2J\x1b[1;1H");

    #define P4_INIT_CONSOLE     UINT __default_cp1__ = GetConsoleCP();              \
                                UINT __default_cp2__ = GetConsoleOutputCP();        \
                                SetConsoleOutputCP(CP_UTF8);                        \
                                SetConsoleCP(CP_UTF8);

    #define P4_RESET_CONSOLE    SetConsoleOutputCP(__default_cp2__);\
                                SetConsoleCP(__default_cp1__);

#else 
    #define P4_CLEAR_CONSOLE    printf("\e[2J\e[1;1H");
    #define P4_INIT_CONSOLE
    #define P4_RESET_CONSOLE

#endif 


#define P4_DEFAULT_LINES    6UL
#define P4_DEFAULT_COLUMNS  4UL

#define P4_DEFAULT_WIDTH    5UL
#define P4_DEFAULT_HEIGHT   1UL

#endif 