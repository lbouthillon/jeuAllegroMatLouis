#ifndef _DECOR_H
#define _DECOR_H

#include <allegro.h>
#include "personnage.h"




typedef struct decor {
    int dureeImage;
    int nbImages;
    int state;
    int x;
    int y;
    int length;
    int width;
    int franchissabe;
    BITMAP * images[20];
} DECOR;

extern DECOR * fondBlancDecor;
extern DECOR * litDecor;
extern DECOR * mursDecor;
extern DECOR * porteSangDecor;
extern DECOR * goutteSangDecor;
extern DECOR * murs2Decor;
extern DECOR * horlogeBasDecor;
extern DECOR * horlogeHautDecor;

int collision(PERSONNAGE perso,DECOR * d, int deplacement, int Xref, int Yref);

void afficher_decor(DECOR * decor, BITMAP * page, int Xref, int Yref);

void init_decors();

#endif
