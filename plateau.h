#ifndef _PLATEAU_H
#define _PLATEAU_H

#include <allegro.h>
#include "decor.h"


extern int NB_CASES_LARG;
extern int NB_CASES_LONG;
extern int DEFAULT_TILE_SIZE;

typedef struct plateau {
    int nbDecors;
    DECOR decors[200];
    //void (*dessine_plateau)(decors_list);
} PLATEAU;

void draw_plateau(PLATEAU plateau, BITMAP * page);

PLATEAU add_decor(PLATEAU plateau, DECOR decor);

#endif

