#ifndef _PERSONNAGE_H
#define _PERSONNAGE_H
#include <allegro.h>


extern int PERSONNAGE_WIDTH;
extern int PERSONNAGE_HEIGHT;
//extern string[] DIRECTIONS;

typedef struct personnage {
    int x;
    int y;
    int direction;
    int state;
} PERSONNAGE;

void afficher_personnage(PERSONNAGE perso, BITMAP * page);

#endif
