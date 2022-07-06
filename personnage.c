#include <stdio.h>
#include "personnage.h"
#include <allegro.h>


PERSONNAGE_HEIGHT = 58;
PERSONNAGE_WIDTH = 40;
//string[] DIRECTIONS = ["Up";"Down";"Left";"Right"];

void afficher_personnage(PERSONNAGE perso, BITMAP * page)
{
    BITMAP *heros;
    heros = load_bitmap("bonhomme.bmp",NULL);
    if (!heros)
    {
        allegro_message("prb allocation BITMAP heros");
        exit(EXIT_FAILURE);
    }
    draw_sprite(page,heros,200,200);
};
