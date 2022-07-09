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



    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,length,width,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    else{

        int deplacement = 5;

    BITMAP * page;


    SAMPLE * evertale;
    SAMPLE * marcherSol;

    page = create_bitmap(800,600);

    //page = init_page();

    init_bitmap(page);

    DECOR fondBlancDecor = {fondBlanc,0,0,640,640,1};
    fondBlancDecor.image = fondBlanc;
    PLATEAU plateau;
    plateau.nbDecors = 0;
    plateau.decors[0] = fondBlancDecor;
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


    int x =100;
    int y= 100;

    initialisation(bonhomme[0][0]);

    // mouvements :
    // se déplacera de 5 pixels à chaque étape de déplacement
    afficher_personnage(perso,page);
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
        }

            blit(page,screen,0,0,0,0,800,600);
            rest(20);
        }
        return 0;

    }
}
END_OF_MAIN();
