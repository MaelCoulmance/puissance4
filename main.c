#include <stddef.h>
#include <stdio.h>

#include "init.h"
#include "grille.h"
#include "manip.h"
#include "game.h"

#ifndef EXIT_SUCCESS
    #define EXIT_SUCCESS 0  // not always defined when compiled on Linux
#endif 


extern char *utf8_scanf(size_t);
extern void get_dimensions(int, char**, int*, int*);


int main(int argc, char* argv[])
{
    int lines, columns;
    get_dimensions(argc, argv, &lines, &columns);

    P4_INIT_CONSOLE;

    char *nameJ1;
    char *nameJ2;


    P4_CLEAR_CONSOLE;
    printf("Entrez le nom du premier joueur:\n");
    nameJ1 = utf8_scanf(100);

    P4_CLEAR_CONSOLE;
    printf("Entrez le nom du second joueur:\n");
    nameJ2 = utf8_scanf(100);



    grille_t*   grille;
    gstatus_t   status;
    bool        isJ1Playing;


    while (1) {
        grille = make_grille((size_t)lines, (size_t)columns);
        status = Status_Normal;
        isJ1Playing = true;

        while (status == Status_Normal) {
            status = gameLoop(grille, isJ1Playing, nameJ1, nameJ2);
            isJ1Playing = !isJ1Playing;
        }
        
        free_grille(grille);

        if (!endGameScreen(status, nameJ1, nameJ2))
            break;
    }

    P4_RESET_CONSOLE;

    return EXIT_SUCCESS;
}