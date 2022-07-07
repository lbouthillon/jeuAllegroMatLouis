#include <stdio.h>
#include "personnage.h"
#include <allegro.h>


PERSONNAGE_HEIGHT = 58;
PERSONNAGE_WIDTH = 40;

BITMAP * init_heros()
{
    BITMAP * heros;
    heros = load_bitmap("bonhomme.bmp",NULL);
    if (!heros)
    {
        allegro_message("prb allocation BITMAP heros");
        exit(EXIT_FAILURE);
    }
    return heros;
}


//string[] DIRECTIONS = ["Up";"Down";"Left";"Right"];
//BITMAP * heros = load_bitmap("bonhomme.bmp",NULL);
//bonhommeDos = load_bitmap("bonhommeDos.bmp",NULL);
/*    if (!bonhommeDos)
    {
        allegro_message("prb allocation BITMAP bonhommeDos");
        exit(EXIT_FAILURE);
    }
    bonhommeSud = load_bitmap("bonhommeSud.bmp",NULL);
    if (!bonhommeSud)
    {
        allegro_message("prb allocation BITMAP bonhommeSud");
        exit(EXIT_FAILURE);
    }
    bonhommeDroite = load_bitmap("bonhommeDroite.bmp",NULL);
    if (!bonhommeDroite)
    {
        allegro_message("prb allocation BITMAP bonhommeDroite");
        exit(EXIT_FAILURE);
    }
    bonhommeGauche = load_bitmap("bonhommeGauche.bmp",NULL);
    if (!bonhommeGauche)
    {
        allegro_message("prb allocation BITMAP bonhommeGauche");
        exit(EXIT_FAILURE);
    }*/

void afficher_personnage(PERSONNAGE perso, BITMAP * page,int x,int y)
{
    draw_sprite(page,init_heros(),x,y);
};
