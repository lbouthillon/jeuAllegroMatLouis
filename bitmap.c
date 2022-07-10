#include <stdio.h>
#include "bitmap.h"
#include <allegro.h>

BITMAP * fondBlanc = NULL;
BITMAP * lit = NULL;
BITMAP * murs = NULL;
BITMAP * bonhomme[4][3] = {NULL};

void init_bitmap(BITMAP * page){
    murs = load_bitmap("murs.bmp", NULL);
    if (!murs)
    {
        allegro_message("prb allocation BITMAP murs");
        exit(EXIT_FAILURE);
    }
    lit = load_bitmap("lit.bmp",NULL);
    if (!lit)
    {
        allegro_message("prb allocation BITMAP lit");
        exit(EXIT_FAILURE);
    }
    fondBlanc = load_bitmap("fondBlanc.bmp",NULL);
    if (!fondBlanc)
    {
        allegro_message("prb allocation BITMAP fondBlanc");
        exit(EXIT_FAILURE);
    }
    bonhomme[1][0] = load_bitmap("bonhommeDos.bmp",NULL);
    if (!bonhomme[1][0])
    {
        allegro_message("prb allocation BITMAP bonhommeDos");
        exit(EXIT_FAILURE);
    }
    bonhomme[1][1] = load_bitmap("bonhommeDos2.bmp",NULL);
    if (!bonhomme[1][1])
    {
        allegro_message("prb allocation BITMAP bonhommeDos");
        exit(EXIT_FAILURE);
    }
    bonhomme[1][2] = load_bitmap("bonhommeDos3.bmp",NULL);
    if (!bonhomme[1][2])
    {
        allegro_message("prb allocation BITMAP bonhommeDos");
        exit(EXIT_FAILURE);
    }
    bonhomme[0][0] = load_bitmap("bonhomme.bmp",NULL);
    if (!bonhomme[0][0])
    {
        allegro_message("prb allocation BITMAP bonhommeSud");
        exit(EXIT_FAILURE);
    }
    bonhomme[0][1] = load_bitmap("bonhomme2.bmp",NULL);
    if (!bonhomme[0][1])
    {
        allegro_message("prb allocation BITMAP bonhommeSud");
        exit(EXIT_FAILURE);
    }
    bonhomme[0][2] = load_bitmap("bonhomme3.bmp",NULL);
    if (!bonhomme[0][2])
    {
        allegro_message("prb allocation BITMAP bonhommeSud");
        exit(EXIT_FAILURE);
    }
    bonhomme[3][0] = load_bitmap("bonhommeDroit.bmp",NULL);
    if (!bonhomme[3][0])
    {
        allegro_message("prb allocation BITMAP bonhommeDroit");
        exit(EXIT_FAILURE);
    }
    bonhomme[3][1] = load_bitmap("bonhommeDroit2.bmp",NULL);
    if (!bonhomme[3][1])
    {
        allegro_message("prb allocation BITMAP bonhommeDroit");
        exit(EXIT_FAILURE);
    }
    bonhomme[3][2] = load_bitmap("bonhommeDroit3.bmp",NULL);
    if (!bonhomme[3][2])
    {
        allegro_message("prb allocation BITMAP bonhommeDroit");
        exit(EXIT_FAILURE);
    }
    bonhomme[2][0] = load_bitmap("bonhommeGauche.bmp",NULL);
    if (!bonhomme[2][0])
    {
        allegro_message("prb allocation BITMAP bonhommeGauche");
        exit(EXIT_FAILURE);
    }
    bonhomme[2][1] = load_bitmap("bonhommeGauche2.bmp",NULL);
    if (!bonhomme[2][1])
    {
        allegro_message("prb allocation BITMAP bonhommeGauche");
        exit(EXIT_FAILURE);
    }
    bonhomme[2][2] = load_bitmap("bonhommeGauche3.bmp",NULL);
    if (!bonhomme[2][2])
    {
        allegro_message("prb allocation BITMAP bonhommeGauche");
        exit(EXIT_FAILURE);
    }
    //draw_sprite(page,fondBlanc,0,0);
}




