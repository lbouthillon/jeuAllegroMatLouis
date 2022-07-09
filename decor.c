#include <stdio.h>
#include "bitmap.h"
#include "decor.h"
#include <allegro.h>

DECOR * fondBlancDecor = NULL;
DECOR * litDecor = NULL;

DECOR fondBlancDecorObject ;
DECOR litDecorObject ;



void init_decors(){

    litDecorObject = (DECOR){lit,200,300,64,95,0};
    fondBlancDecorObject = (DECOR){fondBlanc,0,0,640,640,1};
    litDecorObject.image = lit;
    fondBlancDecorObject.image = fondBlanc;
    litDecor = &litDecorObject;
    fondBlancDecor = &fondBlancDecorObject;



};

void afficher_decor(DECOR decor, BITMAP * page){
    if (!decor.image)
    {
        allegro_message("image du decor NULL");
        exit(EXIT_FAILURE);
    }
    draw_sprite(page,decor.image,decor.x,decor.y);
};
