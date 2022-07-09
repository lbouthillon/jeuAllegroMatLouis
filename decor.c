#include <stdio.h>
#include "bitmap.h"
#include "decor.h"
#include <allegro.h>

DECOR * fondBlancDecor = NULL;
DECOR * litDecor = NULL;

void init_decors(){
    fondBlancDecor = &(DECOR){fondBlanc,0,0,640,640,1};
    fondBlancDecor->image = fondBlanc;

    litDecor = &(DECOR){lit,400,300,64,95,0};
    litDecor->image = lit;
};

void afficher_decor(DECOR decor, BITMAP * page){
    if (!decor.image)
    {
        allegro_message("image du decor NULL");
        exit(EXIT_FAILURE);
    }
    draw_sprite(page,decor.image,decor.x,decor.y);
};
