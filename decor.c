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
DECOR * horlogeDecor = NULL;

DECOR fondBlancDecorObject ;
DECOR litDecorObject ;
DECOR mursDecorObject;
DECOR porteSandDecorObject;
DECOR goutteSangDecorObject;
DECOR murs2DecorObject;
DECOR horlogeDecorObject;

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

    BITMAP * litImages[20] = {NULL};
    BITMAP * fondBlancImages[20] = {NULL};
    BITMAP * mursImages[20] = {NULL};
    BITMAP * porteSangImages[20] = {NULL};
    BITMAP * goutteSangImages[20] = {NULL};
    BITMAP * murs2Images[20] = {NULL};
    BITMAP * horlogeImages[20] = {NULL};


    litDecorObject = (DECOR){1,0,350,250,92,60,0,litImages};
    fondBlancDecorObject = (DECOR){1,0,-200,-200,1040,1040,1,fondBlancImages};
    mursDecorObject = (DECOR){1,0,120,120,380,380,1,mursImages};
    porteSandDecorObject = (DECOR){1,0,200,35,75,144,1,porteSangImages};
    goutteSangDecorObject = (DECOR){1,0,220,80,5,3,1,goutteSangImages};
    murs2DecorObject = (DECOR){1,0,160,160,300,300,1,murs2Images};
    horlogeDecorObject = (DECOR){12,0,350,80,42,94,0,horlogeImages};

    litDecorObject.images[0] = lit;
    fondBlancDecorObject.images[0] = fondBlanc;
    mursDecorObject.images[0] = murs;
    porteSandDecorObject.images[0] = porteSang;
    goutteSangDecorObject.images[0] = goutteSang;
    murs2DecorObject.images[0] = murs2;

    horlogeDecorObject.images[0] = horloge[0];
    horlogeDecorObject.images[1] = horloge[1];
    horlogeDecorObject.images[2] = horloge[2];
    horlogeDecorObject.images[3] = horloge[3];
    horlogeDecorObject.images[4] = horloge[2];
    horlogeDecorObject.images[5] = horloge[1];
    horlogeDecorObject.images[6] = horloge[0];
    horlogeDecorObject.images[7] = horloge[4];
    horlogeDecorObject.images[8] = horloge[5];
    horlogeDecorObject.images[9] = horloge[6];
    horlogeDecorObject.images[10] = horloge[5];
    horlogeDecorObject.images[11] = horloge[4];

    litDecor = &litDecorObject;
    fondBlancDecor = &fondBlancDecorObject;
    mursDecor = &mursDecorObject;
    porteSangDecor = &porteSandDecorObject;
    goutteSangDecor = &goutteSangDecorObject;
    murs2Decor = &murs2DecorObject;
    horlogeDecor = &horlogeDecorObject;



};

void afficher_decor(DECOR * decor, BITMAP * page, int Xref, int Yref){
    if (!decor->images[decor->state])
    {
        allegro_message("image du decor NULL");
        exit(EXIT_FAILURE);
    }
    //printf("%d",decor.length);
    //printf("%c",'\n');
    draw_sprite(page,decor->images[decor->state],decor->x + Xref,decor->y + Yref);
    decor->state = (decor->state + 1)%decor->nbImages;
};
