// Copyright (C) 2022, Maël Coulmance

#ifndef PUISSANCE4_GRILLE_H
#define PUISSANCE4_GRILLE_H

#include <stddef.h>
#include <stdbool.h>

typedef enum content_e {
    Content_Empty   = 0x0000,
    Content_Circle  = 0x0001,
    Content_Cross   = 0x0002
} content_t;

typedef struct grille_s {
    size_t          lines;
    size_t          columns;
    content_t**     values;
    int*            nextLine;
} grille_t;


grille_t* make_grille(size_t, size_t);

void free_grille(grille_t*);

void print_grille(grille_t*);

#endif 