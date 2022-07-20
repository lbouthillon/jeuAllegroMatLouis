#include <stdio.h>
#include "bitmap.h"
#include <allegro.h>

BITMAP * fondBlanc = NULL;
BITMAP * lit = NULL;
BITMAP * murs = NULL;
BITMAP * porteSang = NULL;
BITMAP * goutteSang = NULL;
BITMAP * murs2 = NULL;
BITMAP * bonhomme[4][9] = {NULL};
BITMAP * horloge[7] = {NULL};
BITMAP * menu = NULL;
BITMAP * sac = NULL;

void init_bitmap(BITMAP * page){
    murs = load_bitmap("murs.bmp", NULL);
    if (!murs)
    {
        allegro_message("prb allocation BITMAP murs");
        exit(EXIT_FAILURE);
    }
    murs2 = load_bitmap("murs2.bmp", NULL);
    if (!murs2)
    {
        allegro_message("prb allocation BITMAP murs2");
        exit(EXIT_FAILURE);
    }
    porteSang = load_bitmap("porteSang.bmp", NULL);
    if (!porteSang)
    {
        allegro_message("prb allocation BITMAP porteSang");
        exit(EXIT_FAILURE);
    }
    goutteSang = load_bitmap("goutteSang.bmp", NULL);
    if (!goutteSang)
    {
        allegro_message("prb allocation BITMAP goutteSang");
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
    bonhomme[1][3] = load_bitmap("bonhommeDosDescente1.bmp",NULL);
    if (!bonhomme[1][3])
    {
        allegro_message("prb allocation BITMAP bonhommeDosDescente1");
        exit(EXIT_FAILURE);
    }
    bonhomme[1][4] = load_bitmap("bonhommeDosDescente2.bmp",NULL);
    if (!bonhomme[1][4])
    {
        allegro_message("prb allocation BITMAP bonhommeDosDescente2");
        exit(EXIT_FAILURE);
    }
    bonhomme[1][5] = load_bitmap("bonhommeDosDescente3.bmp",NULL);
    if (!bonhomme[1][5])
    {
        allegro_message("prb allocation BITMAP bonhommeDosDescente3");
        exit(EXIT_FAILURE);
    }
    bonhomme[1][6] = load_bitmap("bonhommeDosDescente4.bmp",NULL);
    if (!bonhomme[1][6])
    {
        allegro_message("prb allocation BITMAP bonhommeDosDescente4");
        exit(EXIT_FAILURE);
    }
    bonhomme[1][7] = load_bitmap("bonhommeDosDescente5.bmp",NULL);
    if (!bonhomme[1][7])
    {
        allegro_message("prb allocation BITMAP bonhommeDosDescente5");
        exit(EXIT_FAILURE);
    }
    bonhomme[1][8] = load_bitmap("bonhommeDosDescente6.bmp",NULL);
    if (!bonhomme[1][8])
    {
        allegro_message("prb allocation BITMAP bonhommeDosDescente6");
        exit(EXIT_FAILURE);
    }
    menu = load_bitmap("menu.bmp",NULL);
    if (!menu)
    {
        allegro_message("prb allocation BITMAP menu");
        exit(EXIT_FAILURE);
    }
    sac = load_bitmap("sac.bmp",NULL);
    if (!sac)
    {
        allegro_message("prb allocation BITMAP sac");
        exit(EXIT_FAILURE);
    }
    horloge[0] = load_bitmap("horloge1.bmp",NULL);
    if (!horloge[0])
    {
        allegro_message("prb allocation BITMAP horloge1");
        exit(EXIT_FAILURE);
    }
    horloge[1] = load_bitmap("horloge2.bmp",NULL);
    if (!horloge[1])
    {
        allegro_message("prb allocation BITMAP horloge2");
        exit(EXIT_FAILURE);
    }
    horloge[2] = load_bitmap("horloge3.bmp",NULL);
    if (!horloge[2])
    {
        allegro_message("prb allocation BITMAP horloge3");
        exit(EXIT_FAILURE);
    }
    horloge[3] = load_bitmap("horloge4.bmp",NULL);
    if (!horloge[3])
    {
        allegro_message("prb allocation BITMAP horloge4");
        exit(EXIT_FAILURE);
    }
    horloge[4] = load_bitmap("horloge5.bmp",NULL);
    if (!horloge[4])
    {
        allegro_message("prb allocation BITMAP horloge5");
        exit(EXIT_FAILURE);
    }
    horloge[5] = load_bitmap("horloge6.bmp",NULL);
    if (!horloge[5])
    {
        allegro_message("prb allocation BITMAP horloge6");
        exit(EXIT_FAILURE);
    }
    horloge[6] = load_bitmap("horloge7.bmp",NULL);
    if (!horloge[6])
    {
        allegro_message("prb allocation BITMAP horloge7");
        exit(EXIT_FAILURE);
    }
    //draw_sprite(page,fondBlanc,0,0);
}




