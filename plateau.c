#include <stdio.h>
#include "plateau.h"
#include "decor.h"
#include "bitmap.h"
#include <allegro.h>

NB_CASES_LARG = 15;
NB_CASES_LONG = 15;
DEFAULT_TILE_SIZE = 64;

PLATEAU * plateauDebut = NULL;
PLATEAU p1;

void draw_plateau(PLATEAU plateau, BITMAP * page){
    for (int i = 0 ; i < plateau.nbDecors ; i++){
        DECOR d = plateau.decors[i];
        afficher_decor(d,page);
    }
};

void init_plateaux(){

    p1.nbDecors = 0;
    p1 = add_decor(p1, *fondBlancDecor);
    p1 = add_decor(p1, *mursDecor);
    p1 = add_decor(p1, *litDecor);
    plateauDebut = &p1;
};

PLATEAU add_decor(PLATEAU plateau, DECOR decor){
    plateau.decors[plateau.nbDecors] = decor;
    plateau.nbDecors = plateau.nbDecors + 1;
    return plateau;
};

/*BITMAP * init_page()
{
    rectfill(screen,200,100,100,200,makecol(0,255,0));
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
    rectfill(screen,200,100,100,200,makecol(0,255,0));
    return page;
}*/
