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
extern DECOR * porteSangDecor;
extern DECOR * goutteSangDecor;
extern DECOR * murs2Decor;

int collision(PERSONNAGE perso,DECOR * d, int deplacement, int Xref, int Yref);

void afficher_decor(DECOR decor, BITMAP * page, int Xref, int Yref);

void init_decors();

#endif
