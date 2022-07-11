#ifndef _DECOR_H
#define _DECOR_H

#include <allegro.h>
#include "personnage.h"



typedef struct decor {
    BITMAP * image;
    int x;
    int y;
    int length;
    int width;
    int franchissabe;
} DECOR;

extern DECOR * fondBlancDecor;
extern DECOR * litDecor;
extern DECOR * mursDecor;

int collision(PERSONNAGE perso,DECOR * d, int deplacement);

void afficher_decor(DECOR decor, BITMAP * page);

void init_decors();

#endif
