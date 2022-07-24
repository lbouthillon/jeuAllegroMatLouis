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
DECOR * horlogeBasDecor = NULL;
DECOR * horlogeHautDecor = NULL;

DECOR fondBlancDecorObject ;
DECOR litDecorObject ;
DECOR mursDecorObject;
DECOR porteSandDecorObject;
DECOR goutteSangDecorObject;
DECOR murs2DecorObject;
DECOR horlogeBasDecorObject;
DECOR horlogeHautDecorObject;

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
    BITMAP * horlogeBasImages[20] = {NULL};
    BITMAP * horlogeHautImages[20] = {NULL};


    litDecorObject = (DECOR){1,1,0,350,250,92,60,0,litImages};
    fondBlancDecorObject = (DECOR){1,1,0,-200,-200,1040,1040,1,fondBlancImages};
    mursDecorObject = (DECOR){1,1,0,120,120,380,380,1,mursImages};
    porteSandDecorObject = (DECOR){1,1,0,200,35,75,144,1,porteSangImages};
    goutteSangDecorObject = (DECOR){1,1,0,220,80,5,3,1,goutteSangImages};
    murs2DecorObject = (DECOR){1,1,0,160,160,300,300,1,murs2Images};
    horlogeBasDecorObject = (DECOR){4,12,0,350,120,49,42,0,horlogeBasImages};
    horlogeHautDecorObject = (DECOR){1,1,0,350,75,45,42,0,horlogeHautImages};

    litDecorObject.images[0] = lit;
    fondBlancDecorObject.images[0] = fondBlanc;
    mursDecorObject.images[0] = murs;
    porteSandDecorObject.images[0] = porteSang;
    goutteSangDecorObject.images[0] = goutteSang;
    murs2DecorObject.images[0] = murs2;
    //horlogeHautDecorObject.images[0] = horlogeHaut[0];

    for (int i = 0 ; i < 16 ; i++){
        horlogeHautDecorObject.images[i] = horlogeHaut[i];
    }

    horlogeBasDecorObject.images[0] = horlogeBas[0];
    horlogeBasDecorObject.images[1] = horlogeBas[1];
    horlogeBasDecorObject.images[2] = horlogeBas[2];
    horlogeBasDecorObject.images[3] = horlogeBas[3];
    horlogeBasDecorObject.images[4] = horlogeBas[2];
    horlogeBasDecorObject.images[5] = horlogeBas[1];
    horlogeBasDecorObject.images[6] = horlogeBas[0];
    horlogeBasDecorObject.images[7] = horlogeBas[4];
    horlogeBasDecorObject.images[8] = horlogeBas[5];
    horlogeBasDecorObject.images[9] = horlogeBas[6];
    horlogeBasDecorObject.images[10] = horlogeBas[5];
    horlogeBasDecorObject.images[11] = horlogeBas[4];

    litDecor = &litDecorObject;
    fondBlancDecor = &fondBlancDecorObject;
    mursDecor = &mursDecorObject;
    porteSangDecor = &porteSandDecorObject;
    goutteSangDecor = &goutteSangDecorObject;
    murs2Decor = &murs2DecorObject;
    horlogeBasDecor = &horlogeBasDecorObject;
    horlogeHautDecor = &horlogeHautDecorObject;



};

void afficher_decor(DECOR * decor, BITMAP * page, int Xref, int Yref){
    if (!decor->images[decor->state/decor->dureeImage])
    {
        allegro_message("image du decor NULL");
        exit(EXIT_FAILURE);
    }
    //printf("%d",decor.length);
    //printf("%c",'\n');
    draw_sprite(page,decor->images[decor->state/decor->dureeImage],decor->x + Xref,decor->y + Yref);
    decor->state = (decor->state + 1)%(decor->nbImages*decor->dureeImage);
};
