#include <stdio.h>
#include "plateau.h"
#include "decor.h"
#include "bitmap.h"
#include <allegro.h>

NB_CASES_LARG = 15;
NB_CASES_LONG = 15;
DEFAULT_TILE_SIZE = 64;

PLATEAU * chambre = NULL;
PLATEAU p1;
PLATEAU * RDC = NULL;
PLATEAU p2;
int menuVisible = 0;

void evenementPlateau1 (PLATEAU plateauCourant, PERSONNAGE perso, BITMAP * page){

    if (key[KEY_E] && collision(perso, plateauCourant.decors[5], 5, plateauCourant.x, plateauCourant.y)==0){
            plateauCourant.decors[6]->nbImages = 16;
        }
    if (key[KEY_Q]){
        printf("%d", menuVisible);
        printf("%c", '\n');
        if (menuVisible){
            draw_sprite(page,menu,460,0);
            while (key[KEY_Q]){
                blit(page,screen,0,0,0,0,800,600);
                rest(10);
            }
            while (!key[KEY_Q]){
                blit(page,screen,0,0,0,0,800,600);
                rest(10);
            }
            while (key[KEY_Q]){
                blit(page,screen,0,0,0,0,800,600);
                rest(10);
            }

        }
        menuVisible = 1-menuVisible;

    }
    /*if (menuVisible) {
            draw_sprite(page,menu,460,0);
            if((mouse_b & 1)&&(mouse_x >= 0 && mouse_x <= 640) &&(mouse_y >= 0 && mouse_y <= 640)){
                draw_sprite(page,sac,0,0);
            }
        }*/

}

void evenementPlateau2 (PLATEAU plateauCourant, PERSONNAGE perso, BITMAP * page){
}

PLATEAU changementPlateau1(PLATEAU plateauCourant, PERSONNAGE * persoPtr, BITMAP * page){

    if (persoPtr->direction == 1 && plateauCourant.y == 180 && plateauCourant.x >= 70 && plateauCourant.x <= 105){
        //allegro_message("apres if");
        while (persoPtr->y != 282){
            persoPtr->y = MAX(persoPtr->y - 5,282);
            for (int j = 0 ; j < 5 ; j++){
                clear_bitmap(page);
                draw_plateau(plateauCourant,page);
                afficher_personnage(*persoPtr,page);
                blit(page,screen,0,0,0,0,800,600);
                rest(20);
            }
        }


        for (int i = 0 ; i < 6 ; i++){
            //perso->y = perso->y - 5;
            persoPtr->state = 10* (i+3);
            for (int j = 0 ; j < 15 ; j++){
                clear_bitmap(page);
                draw_plateau(plateauCourant,page);
                afficher_personnage(*persoPtr,page);
                blit(page,screen,0,0,0,0,800,600);
                rest(20);
            }
        }
        //allegro_message("2eme partie");
        persoPtr->state = 0;
        persoPtr->direction = 0;
        persoPtr->y = persoPtr->y - 30+18;
        //allegro_message("sortie");
        RDC->x = plateauCourant.x;
        RDC->y = plateauCourant.y;
        plateauCourant = *RDC;
        for (int i = 0 ; i < 6 ; i++){
            persoPtr->y = persoPtr->y + 5;
            for (int j = 0 ; j < 3 ; j++){
                clear_bitmap(page);
                draw_plateau(plateauCourant,page);
                afficher_personnage(*persoPtr,page);
                blit(page,screen,0,0,0,0,800,600);
                rest(20);
            }
        }
        return *RDC;
    }
    return plateauCourant;
}

PLATEAU changementPlateau2(PLATEAU plateauCourant, PERSONNAGE * persoPtr, BITMAP * page){

    if (persoPtr->direction == 1 && plateauCourant.y == 180 && plateauCourant.x >= 70 && plateauCourant.x <= 105){
        //allegro_message("apres if");
        while (persoPtr->y != 282){
            persoPtr->y = MAX(persoPtr->y - 5,282);
            for (int j = 0 ; j < 5 ; j++){
                clear_bitmap(page);
                draw_plateau(plateauCourant,page);
                afficher_personnage(*persoPtr,page);
                blit(page,screen,0,0,0,0,800,600);
                rest(20);
            }
        }


        for (int i = 0 ; i < 6 ; i++){
            //perso->y = perso->y - 5;
            persoPtr->state = 10* (i+3);
            for (int j = 0 ; j < 15 ; j++){
                clear_bitmap(page);
                draw_plateau(plateauCourant,page);
                afficher_personnage(*persoPtr,page);
                blit(page,screen,0,0,0,0,800,600);
                rest(20);
            }
        }
        //allegro_message("2eme partie");
        persoPtr->state = 0;
        persoPtr->direction = 0;
        persoPtr->y = persoPtr->y - 30+18;
        //allegro_message("sortie");
        chambre->x = plateauCourant.x;
        chambre->y = plateauCourant.y;
        plateauCourant = *chambre;
        for (int i = 0 ; i < 6 ; i++){
            persoPtr->y = persoPtr->y + 5;
            for (int j = 0 ; j < 3 ; j++){
                clear_bitmap(page);
                draw_plateau(plateauCourant,page);
                afficher_personnage(*persoPtr,page);
                blit(page,screen,0,0,0,0,800,600);
                rest(20);
            }
        }
        return *chambre;
    }
    return plateauCourant;
}


void draw_plateau(PLATEAU plateau, BITMAP * page){
    for (int i = 0 ; i < plateau.nbDecors ; i++){
        DECOR * d = plateau.decors[i];
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
        DECOR * d = plateau.decors[i];
        deplacement = MIN(deplacement,collision(perso, d, deplacement_max, plateau.x, plateau.y));
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
    p1 = add_decor(p1, fondBlancDecor);
    p1 = add_decor(p1, murs2Decor);
    p1 = add_decor(p1, litDecor);
    p1 = add_decor(p1, porteSangDecor);
    p1 = add_decor(p1, goutteSangDecor);
    p1 = add_decor(p1, horlogeBasDecor);
    p1 = add_decor(p1, horlogeHautDecor);
    p1.changementPlateau = changementPlateau1;
    p1.evenements = evenementPlateau1;
    chambre = &p1;

    p2.nbDecors = 0;
    p2.x = 0;
    p2.y = 0;
    p2.xMin =  - 117;
    p2.xMax = 137;
    p2.yMin = -100;
    p2.yMax = 180;
    p2 = add_decor(p2, fondBlancDecor);
    p2 = add_decor(p2, murs2Decor);
    p2 = add_decor(p2, porteSangDecor);
    p2.changementPlateau = changementPlateau2;
    p2.evenements = evenementPlateau2;
    RDC = &p2;
};

PLATEAU add_decor(PLATEAU plateau, DECOR * decor){
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
