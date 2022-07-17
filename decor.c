#include <stdio.h>
#include "bitmap.h"
#include "decor.h"
#include "personnage.h"
#include <allegro.h>

DECOR * fondBlancDecor = NULL;
DECOR * litDecor = NULL;
DECOR * mursDecor = NULL;
DECOR * porteSangDecor = NULL;
DECOR * goutteSangDecor = NULL;
DECOR * murs2Decor = NULL;

DECOR fondBlancDecorObject ;
DECOR litDecorObject ;
DECOR mursDecorObject;
DECOR porteSandDecorObject;
DECOR goutteSangDecorObject;
DECOR murs2DecorObject;

int collision(PERSONNAGE perso, DECOR * d, int deplacement){
    if (!(d->franchissabe)){
        if (perso.direction == 0 && d->y >= perso.y + PERSONNAGE_HEIGHT && d->y < perso.y + PERSONNAGE_HEIGHT + deplacement && perso.x < d->x + d->width && perso.x + PERSONNAGE_WIDTH > d->x)
            return MAX(0,d->y - perso.y - PERSONNAGE_HEIGHT);
        if (perso.direction == 1 && d->y + d->length <= perso.y + 40 && d->y + d->length > perso.y + 40 - deplacement && perso.x < d->x + d->width && perso.x + PERSONNAGE_WIDTH > d->x)
            return MAX(0,perso.y - d->y - d->length);
        if (perso.direction == 2 && d->x + d->width <= perso.x && d->x + d->width > perso.x - deplacement && perso.y + 40< d->y + d->length && perso.y + PERSONNAGE_HEIGHT > d->y)
            return MAX(0,perso.x - d->x - d->width);
        if (perso.direction == 3 && d->x >= perso.x + PERSONNAGE_WIDTH && d->x < perso.x + PERSONNAGE_WIDTH + deplacement && perso.y + 40 < d->y + d->length && perso.y + PERSONNAGE_HEIGHT > d->y)
            return MAX(0,d->x - perso.x - PERSONNAGE_WIDTH);
    }

    return deplacement;
}



void init_decors(){

    litDecorObject = (DECOR){lit,200,300,92,60,0};
    fondBlancDecorObject = (DECOR){fondBlanc,0,0,640,640,1};
    mursDecorObject = (DECOR){murs,120,120,380,380,1};
    porteSandDecorObject = (DECOR){porteSang,200,35,75,144,1};
    goutteSangDecorObject = (DECOR){goutteSang,220,80,5,3,1};
    murs2DecorObject = (DECOR){murs2,160,160,300,300,1};

    litDecorObject.image = lit;
    fondBlancDecorObject.image = fondBlanc;
    mursDecorObject.image = murs;
    porteSandDecorObject.image = porteSang;
    goutteSangDecorObject.image = goutteSang;
    murs2DecorObject.image = murs2;

    litDecor = &litDecorObject;
    fondBlancDecor = &fondBlancDecorObject;
    mursDecor = &mursDecorObject;
    porteSangDecor = &porteSandDecorObject;
    goutteSangDecor = &goutteSangDecorObject;
    murs2Decor = &murs2DecorObject;



};

void afficher_decor(DECOR decor, BITMAP * page){
    if (!decor.image)
    {
        allegro_message("image du decor NULL");
        exit(EXIT_FAILURE);
    }
    draw_sprite(page,decor.image,decor.x,decor.y);
};
