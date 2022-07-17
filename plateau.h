#ifndef _PLATEAU_H
#define _PLATEAU_H

#include <allegro.h>
#include "decor.h"


extern int NB_CASES_LARG;
extern int NB_CASES_LONG;
extern int DEFAULT_TILE_SIZE;

typedef struct plateau {
    int x;
    int y;
    int xMin;
    int yMin;
    int xMax;
    int yMax;
    int nbDecors;
    DECOR decors[200];
    //void (*dessine_plateau)(decors_list);
} PLATEAU;

extern PLATEAU * chambre;
extern PLATEAU * RDC;

void draw_plateau(PLATEAU plateau, BITMAP * page);

int collision_plateau(PLATEAU plateau, PERSONNAGE perso, int deplacement_max);

//PLATEAU * deplacer_plateau(PLATEAU plateau, int deplacement_x, int deplacement_y);

void init_plateaux();

PLATEAU add_decor(PLATEAU plateau, DECOR decor);

#endif

