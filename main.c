#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "decor.h"
#include "plateau.h"
#include "personnage.h"
#include "bitmap.h"
#define NB_CASES_LONG 10
#define NB_CASES_LARG 10



PERSONNAGE perso = {0,0,0,0};


void initialisation(BITMAP * heros){
    perso.x = 300;
    perso.y = 300;
    perso.image = heros;
}

int main()
{
    // paramètres de l'élément à animer
    int posx = 300,posy = 300;    // coordonnées
    int width = NB_CASES_LARG * 64;
    int length = NB_CASES_LONG * 64;
    allegro_init();
    install_keyboard();
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"A");

    //init_bitmap();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,length,width,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    else{

        int deplacement = 5;




    // initialisation des variables de la forme

    // tailles et position initiale au centre

     // 0 -> bas , 1 -> haut, 2 -> gauche, 3 -> droite

    BITMAP * page;
    BITMAP * heros;
    BITMAP * sol;
    BITMAP * bonhomme[4][3];
    BITMAP *fondBlanc;


    SAMPLE * evertale;
    SAMPLE * marcherSol;

    page = create_bitmap(800,600);



    //page = init_page();

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
    fondBlanc = load_bitmap("fondBlanc.bmp",NULL);
    if (!fondBlanc)
    {
        allegro_message("prb allocation BITMAP fondBlanc");
        exit(EXIT_FAILURE);
    }
    DECOR fondBlancDecor = {fondBlanc,0,0,640,640,1};
    fondBlancDecor.image = fondBlanc;
    PLATEAU plateau;
    plateau.nbDecors = 0;
    //plateau.decors[0] = fondBlancDecor;
    plateau = add_decor(plateau, fondBlancDecor);
    draw_plateau(plateau,page);


        evertale = load_sample("debutJeu.wav");
        if(!evertale){
            allegro_message("error evertale");
        }

        marcherSol = load_sample("marcherSol.wav");
        if(!marcherSol){
            allegro_message("error marcherSol");
        }
     //afficher_personnage(perso,page);


    int x =100;
    int y= 100;

    initialisation(heros);

    // mouvements :
    // se déplacera de 5 pixels à chaque étape de déplacement
    //draw_sprite(page,fondBlanc,0,0);
    afficher_personnage(perso,page);
    //draw_sprite(page,heros,perso.x,perso.y);
    rect(page,120,120,500,500,makecol(0,0,0));
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
            draw_plateau(plateau,page);
            rect(page,120,120,500,500,makecol(0,0,0));
            //play_sample(marcherSol,50,0,1000,1);
            if(perso.y>80){
                perso.y = MAX(perso.y-deplacement,80); // mouvement négatif en ordonnées
                perso.state = (perso.state + 1)%30;
            }
            perso.image = bonhomme[1][perso.state/10];
            afficher_personnage(perso,page);
            //draw_sprite(page,bonhomme[1][perso.state/10],perso.x,perso.y);
        }
        if (key[KEY_S])
        {
            clear_bitmap(page);
            draw_plateau(plateau,page);
            rect(page,120,120,500,500,makecol(0,0,0));
            if(perso.y<442){
                perso.y = MIN(perso.y+deplacement,442); // mouvement positif en ordonnées
                perso.state = (perso.state + 1)%30;
            }
            perso.image = bonhomme[0][perso.state/10];
            afficher_personnage(perso,page);
            //draw_sprite(page,bonhomme[0][perso.state/10],perso.x,perso.y);
        }

        if (key[KEY_A])
        {
            clear_bitmap(page);
            draw_plateau(plateau,page);
            rect(page,120,120,500,500,makecol(0,0,0));
            if(perso.x>120){
                perso.x = MAX(perso.x-deplacement,120); // mouvement négatif en abscisses
                perso.state = (perso.state + 1)%30;
            }
            perso.image = bonhomme[2][perso.state/10];
            afficher_personnage(perso,page);
            //draw_sprite(page,bonhomme[2][perso.state/10],perso.x,perso.y);
        }
        if (key[KEY_D])
        {
            clear_bitmap(page);
            draw_plateau(plateau,page);
            rect(page,120,120,500,500,makecol(0,0,0));
            if(perso.x<460){
                perso.x = MIN(perso.x+deplacement,460); // mouvement positif en abscisses
                perso.state = (perso.state + 1)%30;
            }
            perso.image = bonhomme[3][perso.state/10];
            afficher_personnage(perso,page);
            //draw_sprite(page,bonhomme[3][perso.state/10],perso.x,perso.y);
        }

            blit(page,screen,0,0,0,0,800,600);
            rest(20);
        }
        return 0;

    }
}
END_OF_MAIN();
