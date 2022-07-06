#include <stdio.h>
#include "plateau.h"
#include <allegro.h>

NB_CASES_LARG = 15;
NB_CASES_LONG = 15;
DEFAULT_TILE_SIZE = 64;

BITMAP * init_page()
{
    BITMAP * page;
    BITMAP * sol;
    int x = 0;
    int y = 0;
    int width = NB_CASES_LARG * DEFAULT_TILE_SIZE;
    int length = NB_CASES_LONG * DEFAULT_TILE_SIZE;
    page = create_bitmap(length,width);
    sol = load_bitmap("SolBlanc.bmp",NULL);
    if (!sol)
    {
        allegro_message("prb allocation BITMAP sol");
        exit(EXIT_FAILURE);
    }
    for (int largeur = 0 ; largeur < NB_CASES_LARG; largeur++ )
    {
        for (int longueur = 0 ; longueur < NB_CASES_LONG; longueur++ )
        {
            draw_sprite(page,sol,x,y);
            x = x + 64;
        }
        y = y + 64;
        x = 0;
    }
    return page;
}
