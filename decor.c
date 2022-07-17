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

int collision(PERSONNAGE perso, DECOR * d, int deplacement, int Xref, int Yref){

    if (!(d->franchissabe)){
        if (perso.direction == 0 && d->y + Yref >= perso.y + PERSONNAGE_HEIGHT && d->y + Yref < perso.y + PERSONNAGE_HEIGHT + deplacement && perso.x + 7 < d->x + Xref + d->width && perso.x + PERSONNAGE_WIDTH - 7 > d->x + Xref)
            return MAX(0,d->y + Yref - perso.y - PERSONNAGE_HEIGHT);
        if (perso.direction == 1 && d->y + Yref + d->length <= perso.y + 40 && d->y + Yref + d->length > perso.y + 40 - deplacement && perso.x + 7 < d->x + Xref + d->width && perso.x + PERSONNAGE_WIDTH - 7 > d->x + Xref)
            return MAX(0,perso.y - d->y - Yref - d->length);
        if (perso.direction == 2 && d->x + Xref + d->width <= perso.x + 7 && d->x + Xref + d->width > perso.x + 7 - deplacement && perso.y + 40< d->y + Yref + d->length && perso.y + PERSONNAGE_HEIGHT > d->y + Yref)
            return MAX(0,perso.x - d->x - Xref - d->width);
        if (perso.direction == 3 && d->x + Xref >= perso.x - 7 + PERSONNAGE_WIDTH && d->x + Xref < perso.x - 7 + PERSONNAGE_WIDTH + deplacement && perso.y + 40 < d->y + Yref + d->length && perso.y + PERSONNAGE_HEIGHT > d->y + Yref)
            return MAX(0,d->x + Xref - perso.x + 7 - PERSONNAGE_WIDTH);
    }

    return deplacement;
}


void init_decors(){

    litDecorObject = (DECOR){lit,220,300,92,60,0};
    fondBlancDecorObject = (DECOR){fondBlanc,-200,-200,1040,1040,1};
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

void afficher_decor(DECOR decor, BITMAP * page, int Xref, int Yref){
    if (!decor.image)
    {
        allegro_message("image du decor NULL");
        exit(EXIT_FAILURE);
    }
    draw_sprite(page,decor.image,decor.x + Xref,decor.y + Yref);
};
