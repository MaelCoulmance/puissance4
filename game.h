// Copyright (C) 2022, Maël Coulmance

#ifndef PUISSANCE4_GAME_H
#define PUISSANCE4_GAME_H

#include <stddef.h>
#include <stdbool.h>

#include "grille.h"


typedef enum game_status_e {
    Status_Normal   = 0x0000,
    Status_GameOver = 0xFFFF,
    Status_WinJ1    = 0x0001,
    Status_WinJ2    = 0x0002
} gstatus_t;

gstatus_t gameLoop(grille_t*, bool, const char*, const char*);

bool endGameScreen(gstatus_t, const char*, const char*);

#endif 