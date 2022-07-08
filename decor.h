#ifndef _DECOR_H
#define _DECOR_H

#include <allegro.h>

typedef struct decor {
    BITMAP * image;
    int x;
    int y;
    int length;
    int width;
    int franchissabe;
} DECOR;

//int collision(int posx,int posy,DECOR * d);

void afficher_decor(DECOR decor, BITMAP * page);

#endif
