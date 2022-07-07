#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "plateau.h"
#include "personnage.h"
#define NB_CASES_LONG 10
#define NB_CASES_LARG 10

int main()
{



    // paramètres de l'élément à animer
    int posx,posy;    // coordonnées
    int width = NB_CASES_LARG * 64;
    int length = NB_CASES_LONG * 64;
    allegro_init();
    install_keyboard();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,length,width,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    else{
        int deplacement = 5;


        PERSONNAGE perso = {0,0,0,0};


    // initialisation des variables de la forme

    // tailles et position initiale au centre

    BITMAP * page;
    BITMAP * heros;
    BITMAP * sol;
    BITMAP *bonhommeDos;
    BITMAP *bonhommeSud;
    BITMAP *bonhommeDroit;
    BITMAP *bonhommeGauche;
    page = create_bitmap(800,600);

    page = init_page();

    heros = load_bitmap("bonhomme.bmp",NULL);
    if(!heros){
        allegro_message("error bonhomme");
    }
    sol = load_bitmap("SolBlanc.bmp",NULL);
    if (!sol)
    {
        allegro_message("prb allocation BITMAP sol");
        exit(EXIT_FAILURE);
    }
    bonhommeDos = load_bitmap("bonhommeDos.bmp",NULL);
    if (!bonhommeDos)
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
    bonhommeDroit = load_bitmap("bonhommeDroit.bmp",NULL);
    if (!bonhommeDroit)
    {
        allegro_message("prb allocation BITMAP bonhommeDroit");
        exit(EXIT_FAILURE);
    }
    bonhommeGauche = load_bitmap("bonhommeGauche.bmp",NULL);
    if (!bonhommeGauche)
    {
        allegro_message("prb allocation BITMAP bonhommeGauche");
        exit(EXIT_FAILURE);
    }


     afficher_personnage(perso,page);

    int x =100;
    int y= 100;

    // mouvements :
    // se déplacera de 5 pixels à chaque étape de déplacement

    draw_sprite(page,heros,posx,posy);
    // Boucle interactive
    while (!key[KEY_ESC])
    {

        // 1) EFFACER POSITION ACTUELLE (redessiner à la couleur du fond)
//
//        rectfill(screen,posx,posy,posx+tx,posy+ty,makecol(0,0,0));
//        rectfill(screen,x,y,x+tx,y+ty,makecol(100,100,100));
        // 2) DETERMINER NOUVELLE POSITION

        // prise en compte du clavier : deplacement direct de la position
        if (key[KEY_Z])
        {
            clear_bitmap(page);
            perso.y = perso.y-deplacement; // mouvement négatif en ordonnées
            draw_sprite(page,bonhommeDos,perso.x,perso.y);
        }

        if (key[KEY_S])
        {
            clear_bitmap(page);
            perso.y = perso.y+deplacement; // mouvement positif en ordonnées
            draw_sprite(page,heros,perso.x,perso.y);
        }

        if (key[KEY_H])
        {
            clear_bitmap(page);
            heros = load_bitmap("bonhomme.bmp",NULL);
            perso.x = perso.x-deplacement; // mouvement négatif en abscisses
            draw_sprite(page,bonhommeGauche,perso.x,perso.y);
        }

        if (key[KEY_D])
        {
            clear_bitmap(page);
            heros = load_bitmap("bonhomme.bmp",NULL);
            perso.x = perso.x+deplacement; // mouvement positif en abscisses
            draw_sprite(page,bonhommeDroit,perso.x,perso.y);

        }

        blit(page,screen,0,0,0,0,800,600);
        rest(20);

    }

    return 0;
}
}
END_OF_MAIN();
