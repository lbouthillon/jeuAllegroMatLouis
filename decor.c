#include <stdio.h>
#include "decor.h"
#include <allegro.h>

/*int collision(int posx, int posy, DECOR * d)
{

};*/

void afficher_decor(DECOR decor, BITMAP * page){
    if (!decor.image)
    {
        allegro_message("image du decor NULL");
        exit(EXIT_FAILURE);
    }
    draw_sprite(page,decor.image,decor.x,decor.y);
};
