#include <stdio.h>
#include <assert.h>

#include "init.h"
#include "grille.h"
#include "manip.h"
#include "game.h"


gstatus_t gameLoop(grille_t* grille, bool isJ1Playing, const char *nameJ1, const char *nameJ2)
{
    assert(grille && nameJ1 && nameJ2);

    P4_CLEAR_CONSOLE;

    const char *name = isJ1Playing ? nameJ1 : nameJ2;
    const content_t c = isJ1Playing ? Content_Circle : Content_Cross;

    print_grille(grille);
    printf("C'est au tour de %s de jouer: ", name);

    int choice;
    do {
        P4_SCANF("%d", &choice, sizeof (int));
        choice--;
    }
    while (choice < 0 || choice >= (int)grille->columns);


    if (!insert_value(grille, (size_t)choice, c)) {
        P4_CLEAR_CONSOLE;
        printf("La colonne est déjà pleine...\n");
        P4_SLEEP(1500);
        return Status_Normal;
    }

    if (is_loose(grille))
        return Status_GameOver;

    if (is_win(grille, c))
        return isJ1Playing ? Status_WinJ1 : Status_WinJ2;

    return Status_Normal;
}


bool endGameScreen(gstatus_t status, const char *nameJ1, const char *nameJ2)
{
    P4_CLEAR_CONSOLE;

    switch (status) {
    case Status_GameOver:
        printf("La grille est pleine... Match nul!\n");
        break;

    case Status_WinJ1:
        printf("%s remporte la partie !\n", nameJ1);
        break;

    case Status_WinJ2:
        printf("%s remporte la partie !\n", nameJ2);
        break;

    default:
        printf("implementation bug");
        P4_SLEEP(3000);
        return false;
    }

    printf("Souhaitez vous rejouer ? (o/n)");

    char choice[2];

    while (1) {
        P4_SCANF("%s", choice, 2 * sizeof (char));

        if (choice[1] == '\n' && (choice[0] == 'o' || choice[0] == 'O'))
            return true;

        else if (choice[1] == '\n' && (choice[0] == 'n' || choice[0] == 'N')) 
            return false;
    }
}