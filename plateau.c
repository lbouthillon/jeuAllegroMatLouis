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
        afficher_decor(d,page,plateau.x,plateau.y);
    }
};

/*PLATEAU * deplacer_plateau(PLATEAU plateau, int deplacement_x, int deplacement_y){
    plateau.x = plateau.x + deplacement_x;
    plateau.y = plateau.y + deplacement_y;
    for (int i = 0 ; i < plateau.nbDecors ; i++){
        plateau.decors[i].x = plateau.decors[i].x + deplacement_x;
        plateau.decors[i].y = plateau.decors[i].y + deplacement_y;
    }
    return &plateau;
}*/

int collision_plateau(PLATEAU plateau, PERSONNAGE perso, int deplacement_max){
    int deplacement = deplacement_max;
    for (int i = 0 ; i < plateau.nbDecors ; i++){
        DECOR d = plateau.decors[i];
        deplacement = MIN(deplacement,collision(perso, &d, deplacement_max, plateau.x, plateau.y));
    }
    return deplacement;
}

void init_plateaux(){

    p1.nbDecors = 0;
    p1.x = 0;
    p1.y = 0;
    p1.xMin =  - 117;
    p1.xMax = 137;
    p1.yMin = -100;
    p1.yMax = 180;
    p1 = add_decor(p1, *fondBlancDecor);
    p1 = add_decor(p1, *murs2Decor);
    p1 = add_decor(p1, *litDecor);
    p1 = add_decor(p1, *porteSangDecor);
    p1 = add_decor(p1, *goutteSangDecor);
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
