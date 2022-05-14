// Copyright (C) 2022, Maël Coulmance

#ifndef PUISSANCE4_MANIP_H
#define PUISSANCE4_MANIP_H

#include <stddef.h>
#include <stdbool.h>

#include "grille.h"


bool insert_value(grille_t*, size_t, content_t);

bool is_win(grille_t*, content_t);

bool is_loose(grille_t*);

#endif 