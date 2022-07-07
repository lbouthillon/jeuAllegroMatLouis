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
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"A");

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

    BITMAP * bonhomme[4][3]; // 0 -> haut , 1 -> bas, 2 -> gauche, 3 -> droite

    BITMAP * page;
    BITMAP * heros;
    BITMAP * sol;
    BITMAP *bonhommeDos[3];
    BITMAP *bonhommeSud;
    BITMAP *bonhommeDroit;
    BITMAP *bonhommeGauche;

    SAMPLE * evertale;

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
    if (!bonhommeSud)
    {
        allegro_message("prb allocation BITMAP bonhommeSud");
        exit(EXIT_FAILURE);
    }
    bonhomme[0][1] = load_bitmap("bonhomme.bmp",NULL);
    if (!bonhommeSud)
    {
        allegro_message("prb allocation BITMAP bonhommeSud");
        exit(EXIT_FAILURE);
    }
    bonhomme[0][2] = load_bitmap("bonhomme.bmp",NULL);
    if (!bonhommeSud)
    {
        allegro_message("prb allocation BITMAP bonhommeSud");
        exit(EXIT_FAILURE);
    }
    bonhomme[3][0] = load_bitmap("bonhommeDroit.bmp",NULL);
    if (!bonhommeSud)
    {
        allegro_message("prb allocation BITMAP bonhommeDroit");
        exit(EXIT_FAILURE);
    }
    bonhomme[3][1] = load_bitmap("bonhommeDroit2.bmp",NULL);
    if (!bonhommeSud)
    {
        allegro_message("prb allocation BITMAP bonhommeDroit");
        exit(EXIT_FAILURE);
    }
    bonhomme[3][2] = load_bitmap("bonhommeDroit3.bmp",NULL);
    if (!bonhommeSud)
    {
        allegro_message("prb allocation BITMAP bonhommeDroit");
        exit(EXIT_FAILURE);
    }
    bonhomme[2][0] = load_bitmap("bonhommeGauche.bmp",NULL);
    if (!bonhommeGauche)
    {
        allegro_message("prb allocation BITMAP bonhommeGauche");
        exit(EXIT_FAILURE);
    }
    bonhomme[2][1] = load_bitmap("bonhommeGauche2.bmp",NULL);
    if (!bonhommeGauche)
    {
        allegro_message("prb allocation BITMAP bonhommeGauche");
        exit(EXIT_FAILURE);
    }
    bonhomme[2][2] = load_bitmap("bonhommeGauche3.bmp",NULL);
    if (!bonhommeGauche)
    {
        allegro_message("prb allocation BITMAP bonhommeGauche");
        exit(EXIT_FAILURE);
    }

<<<<<<< HEAD

=======
    evertale = load_sample("debutJeu.wav");
    if(!evertale){
        allegro_message("error evertale");
    }
     afficher_personnage(perso,page);
>>>>>>> 08da3fd3292f966df8a5f0cee2074c706370a96a

    int x =100;
    int y= 100;

    // mouvements :
    // se déplacera de 5 pixels à chaque étape de déplacement

    draw_sprite(page,heros,posx,posy);
    play_sample(evertale,50,0,1000,1);
    // Boucle interactive
    while (!key[KEY_ESC])
    {
        // 1) EFFACER POSITION ACTUELLE (redessiner à la couleur du fond)
//
//        rectfill(screen,posx,posy,posx+tx,posy+ty,makecol(0,0,0));
//        rectfill(screen,x,y,x+tx,y+ty,makecol(100,100,100));
        // 2) DETERMINER NOUVELLE POSITION

        // prise en compte du clavier : deplacement direct de la position
        if (key[KEY_W])
        {
            clear_bitmap(page);
            perso.y = perso.y-deplacement; // mouvement négatif en ordonnées
            perso.state = (perso.state + 1)%30;
            draw_sprite(page,bonhomme[1][perso.state/10],perso.x,perso.y);
        }

        if (key[KEY_S])
        {
            clear_bitmap(page);
            perso.y = perso.y+deplacement; // mouvement positif en ordonnées
            perso.state = (perso.state + 1)%30;
            draw_sprite(page,bonhomme[0][perso.state/10],perso.x,perso.y);
        }

        if (key[KEY_A])
        {
            clear_bitmap(page);
            perso.x = perso.x-deplacement; // mouvement négatif en abscisses
            perso.state = (perso.state + 1)%30;
            draw_sprite(page,bonhomme[2][perso.state/10],perso.x,perso.y);
        }

        if (key[KEY_D])
        {
            clear_bitmap(page);
            perso.x = perso.x+deplacement; // mouvement positif en abscisses
            perso.state = (perso.state + 1)%30;
            draw_sprite(page,bonhomme[3][perso.state/10],perso.x,perso.y);
        }

        blit(page,screen,0,0,0,0,800,600);
        rest(20);

    }

    return 0;
}
}
END_OF_MAIN();
