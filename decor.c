#include <stdio.h>
#include "decor.h"
#include <allegro.h>

/*int collision(int posx, int posy, DECOR * d)
{

};*/

void afficher_decor(DECOR decor, BITMAP * page){
    draw_sprite(page,decor.image,decor.x,decor.y);
};
