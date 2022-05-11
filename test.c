#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>

#define MAX_INPUT_LENGTH 255


char* utf8_scanf(size_t length) {
    wchar_t wstr[MAX_INPUT_LENGTH];
    char *res = (char*)(malloc(length * sizeof (char)));

    unsigned long read;
    void *con = GetStdHandle(STD_INPUT_HANDLE);

    ReadConsole(con, wstr, length, &read, NULL);

    int size = WideCharToMultiByte(CP_UTF8, 0, wstr, read, res, sizeof(res), NULL, NULL);
    res[size] = 0;

    return res;
}
#else

char* utf8_scanf(size_t length) {
    char *res = (char*)(malloc(length * sizeof (char)));

    scanf("%s", res);

    return res;
}
#endif 

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    char *name = utf8_scanf(100);

    printf("ENTERED: %s", name);

    return 0;
}