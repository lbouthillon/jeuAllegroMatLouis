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
BITMAP * horlogeBas[7] = {NULL};
BITMAP * horlogeHaut[16] = {NULL};
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
    horlogeBas[0] = load_bitmap("horlogeBas1.bmp",NULL);
    if (!horlogeBas[0])
    {
        allegro_message("prb allocation BITMAP horlogeBas1");
        exit(EXIT_FAILURE);
    }
    horlogeBas[1] = load_bitmap("horlogeBas2.bmp",NULL);
    if (!horlogeBas[1])
    {
        allegro_message("prb allocation BITMAP horlogeBas2");
        exit(EXIT_FAILURE);
    }
    horlogeBas[2] = load_bitmap("horlogeBas3.bmp",NULL);
    if (!horlogeBas[2])
    {
        allegro_message("prb allocation BITMAP horlogeBas3");
        exit(EXIT_FAILURE);
    }
    horlogeBas[3] = load_bitmap("horlogeBas4.bmp",NULL);
    if (!horlogeBas[3])
    {
        allegro_message("prb allocation BITMAP horlogeBas4");
        exit(EXIT_FAILURE);
    }
    horlogeBas[4] = load_bitmap("horlogeBas5.bmp",NULL);
    if (!horlogeBas[4])
    {
        allegro_message("prb allocation BITMAP horlogeBas5");
        exit(EXIT_FAILURE);
    }
    horlogeBas[5] = load_bitmap("horlogeBas6.bmp",NULL);
    if (!horlogeBas[5])
    {
        allegro_message("prb allocation BITMAP horlogeBas6");
        exit(EXIT_FAILURE);
    }
    horlogeBas[6] = load_bitmap("horlogeBas7.bmp",NULL);
    if (!horlogeBas[6])
    {
        allegro_message("prb allocation BITMAP horlogeBas7");
        exit(EXIT_FAILURE);
    }
    horlogeHaut[0] = load_bitmap("horlogeHaut.bmp",NULL);
    if (!horlogeHaut[0])
    {
        allegro_message("prb allocation BITMAP horlogeHaut");
        exit(EXIT_FAILURE);
    }
    horlogeHaut[1] = load_bitmap("horlogeHaut1.bmp",NULL);
    if (!horlogeHaut[1])
    {
        allegro_message("prb allocation BITMAP horlogeHaut1");
        exit(EXIT_FAILURE);
    }
    horlogeHaut[2] = load_bitmap("horlogeHaut2.bmp",NULL);
    if (!horlogeHaut[2])
    {
        allegro_message("prb allocation BITMAP horlogeHaut2");
        exit(EXIT_FAILURE);
    }
    horlogeHaut[3] = load_bitmap("horlogeHaut3.bmp",NULL);
    if (!horlogeHaut[3])
    {
        allegro_message("prb allocation BITMAP horlogeHaut3");
        exit(EXIT_FAILURE);
    }
    horlogeHaut[4] = load_bitmap("horlogeHaut4.bmp",NULL);
    if (!horlogeHaut[4])
    {
        allegro_message("prb allocation BITMAP horlogeHaut4");
        exit(EXIT_FAILURE);
    }
    horlogeHaut[5] = load_bitmap("horlogeHaut5.bmp",NULL);
    if (!horlogeHaut[5])
    {
        allegro_message("prb allocation BITMAP horlogeHaut5");
        exit(EXIT_FAILURE);
    }
    horlogeHaut[6] = load_bitmap("horlogeHaut6.bmp",NULL);
    if (!horlogeHaut[6])
    {
        allegro_message("prb allocation BITMAP horlogeHaut6");
        exit(EXIT_FAILURE);
    }
    horlogeHaut[7] = load_bitmap("horlogeHaut7.bmp",NULL);
    if (!horlogeHaut[7])
    {
        allegro_message("prb allocation BITMAP horlogeHaut7");
        exit(EXIT_FAILURE);
    }
    horlogeHaut[8] = load_bitmap("horlogeHaut8.bmp",NULL);
    if (!horlogeHaut[8])
    {
        allegro_message("prb allocation BITMAP horlogeHaut8");
        exit(EXIT_FAILURE);
    }
    horlogeHaut[9] = load_bitmap("horlogeHaut9.bmp",NULL);
    if (!horlogeHaut[9])
    {
        allegro_message("prb allocation BITMAP horlogeHaut9");
        exit(EXIT_FAILURE);
    }
    horlogeHaut[10] = load_bitmap("horlogeHaut10.bmp",NULL);
    if (!horlogeHaut[10])
    {
        allegro_message("prb allocation BITMAP horlogeHaut10");
        exit(EXIT_FAILURE);
    }
    horlogeHaut[11] = load_bitmap("horlogeHaut11.bmp",NULL);
    if (!horlogeHaut[11])
    {
        allegro_message("prb allocation BITMAP horlogeHaut11");
        exit(EXIT_FAILURE);
    }
    horlogeHaut[12] = load_bitmap("horlogeHaut12.bmp",NULL);
    if (!horlogeHaut[12])
    {
        allegro_message("prb allocation BITMAP horlogeHaut12");
        exit(EXIT_FAILURE);
    }
    horlogeHaut[13] = load_bitmap("horlogeHaut13.bmp",NULL);
    if (!horlogeHaut[13])
    {
        allegro_message("prb allocation BITMAP horlogeHaut13");
        exit(EXIT_FAILURE);
    }
    horlogeHaut[14] = load_bitmap("horlogeHaut14.bmp",NULL);
    if (!horlogeHaut[14])
    {
        allegro_message("prb allocation BITMAP horlogeHaut14");
        exit(EXIT_FAILURE);
    }
    horlogeHaut[15] = load_bitmap("horlogeHaut15.bmp",NULL);
    if (!horlogeHaut[15])
    {
        allegro_message("prb allocation BITMAP horlogeHaut15");
        exit(EXIT_FAILURE);
    }
    //draw_sprite(page,fondBlanc,0,0);
}




