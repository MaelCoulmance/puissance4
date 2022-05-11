#include <assert.h>
#include "manip.h"


bool insert_value(grille_t* grille, size_t idColumn, content_t value)
{
    assert(grille);
    assert(idColumn < grille->columns);
    assert(value != Content_Empty);

    if (grille->nextLine[idColumn] < 0)
        return false;

    grille->values[grille->nextLine[idColumn]][idColumn] = value;
    grille->nextLine[idColumn]++;

    return true;
}

bool is_loose(grille_t* grille)
{
    assert(grille);

    for (size_t i = 0; i < grille->lines; i++) {
        for (size_t j = 0; j < grille->columns; j++) {
            if (grille->values[i][j] == Content_Empty)
                return false;
        }
    }

    return true;
}


static inline bool is_line_full(grille_t* grille, int idLine, content_t value)
{
    // assumes grille != NULL and idLine < lines and value != empty

    int acc = 0;
    for (size_t i = 0; i < grille->columns; i++) {
        if (grille->values[grille->lines - idLine - 1][i] != value) {
            acc = 0;
        } else {
            acc++;
        }

        if (acc == 4)
            return true;
    }

    return false;
}

static inline bool is_column_full(grille_t* grille, int idColumn, content_t value)
{
    // assumes grille != NULL and idColumn < columns and value != empty

    int acc = 0;
    for (size_t i = 0; i < grille->lines; i++) {
        if (grille->values[i][idColumn] != value) {
            acc = 0;
        } else {
            acc++;
        }

        if (acc == 4)
            return true;
    }

    return false;
}

static inline bool is_diagonal_full(grille_t* grille, int idLine, int idColumn, content_t value)
{
    // assume grille != NULL
    //        0 <= idLine < lines
    //        0 <= idColumn < columns
    //        value != empty
    

    if (idLine + 3 < (int)grille->lines) {
        if (idColumn + 3 < (int)grille->columns) {
            if (grille->values[idLine][idColumn] == value
            &&  grille->values[idLine+1][idColumn+1] == value 
            &&  grille->values[idLine+2][idColumn+2] == value 
            &&  grille->values[idLine+3][idColumn+3] == value)
                { return true; }
        }

        if (idColumn-3 >= 0) {
            if (grille->values[idLine][idColumn] == value 
            &&  grille->values[idLine+1][idColumn-1] == value 
            &&  grille->values[idLine+2][idColumn-2] == value 
            &&  grille->values[idLine+3][idColumn-3] == value)
                { return true; }
        }

    }

    return false;
}


bool is_win(grille_t* grille, content_t value)
{
    assert(grille);
    assert(value != Content_Empty);

    for (size_t i = 0; i < grille->lines; i++) {
        if (is_line_full(grille, i, value))
            return true;
    }

    for (size_t i = 0; i < grille->columns; i++) {
        if (is_column_full(grille, i, value))
            return true;
    }

    for (int i = 0; i < (int)grille->lines; i++) {
        for (int j = 0; j < (int)grille->columns; j++) {
            if (is_diagonal_full(grille, i, j, value))
                return true;
        }
    }

    return false;
}