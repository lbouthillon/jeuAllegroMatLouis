#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "decor.h"
#include "plateau.h"
#include "personnage.h"
#include "bitmap.h"
#define NB_CASES_LONG 10
#define NB_CASES_LARG 10

// création du personnage avec ses deux coordonnees, sa direction (entre 0 et 3) et son status (entre 0 et 2)
PERSONNAGE perso = {0,0,0,0};


// initialise le personnage à la position 300, 300 avec l'image du bonhomme de face.
void initialisation(BITMAP * heros, int x, int y){
    perso.x = x;
    perso.y = y;
    perso.image = heros;
}

int main()
{

    char phrase[] = "salutation jeune homme";
    char lit[] = "Voici votre lit";


    // paramètres de l'élément à animer
    int posx = 300,posy = 300;    // coordonnées
    //paramètres du plateau
    int width = NB_CASES_LARG * 64;
    int length = NB_CASES_LONG * 64;

    allegro_init();
    install_keyboard();
    install_mouse();
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"A");
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,length,width,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    else{
        show_mouse(screen);

        //paramètre de mouvement entre chaque frame
        int deplacement = 5;

        BITMAP * page;
        SAMPLE * evertale;
        SAMPLE * marcherSol;

        page = create_bitmap(800,600);


        //création des bitmap utilisés dans le jeu
        init_bitmap(page);
        init_decors();
        init_plateaux();
        PLATEAU plateauCourant = *chambre;
        //creation du DECOR fond blanc avec ses coord, sa taille et sa franchissabilité
        /*DECOR fondBlancDecor = {fondBlanc,0,0,640,640,1};
        fondBlancDecor.image = fondBlanc;

        DECOR litDecor = {lit,400,300,64,95,0};
        litDecor.image = lit;*/
        //initialisation du plateau
        //PLATEAU plateau;
        //plateau.nbDecors = 0;
        //plateau.decors[0] = *fondBlancDecor;
        //plateau = add_decor(plateau, *fondBlancDecor);
        //plateau = add_decor(plateau, *litDecor);

        draw_plateau(plateauCourant,page);


        evertale = load_sample("debutJeu.wav");
        if(!evertale){
            allegro_message("error evertale");
        }

        marcherSol = load_sample("marcherSol.wav");
        if(!marcherSol){
            allegro_message("error marcherSol");
        }

        initialisation(bonhomme[0][0],posx,posy);
        //dessine le perso.image aux coordonnées perso.x et perso.y
        afficher_personnage(perso,page);

        //rect(page,120,120,500,500,makecol(0,0,0));
        //play_sample(marcherSol,50,0,1000,1);
        play_sample(evertale,50,0,1000,1);

        blit(page,screen,0,0,0,0,800,600);
        message(phrase,page);
    // Boucle interactive
    int timer = 30;
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


            perso.direction = 1;


            //if (plateauCourant.y == 180 && plateauCourant.x >= 70 && plateauCourant.x <= 105){
              //  perso.direction = 0;
                //allegro_message("sortie");
                //RDC->x = plateauCourant.x;
                //RDC->y = plateauCourant.y;
                //plateauCourant = *RDC;

            //}
            //clear_bitmap(page);
            //draw_plateau(plateauCourant,page);





            plateauCourant.y = MIN(plateauCourant.y + collision_plateau(plateauCourant, perso, deplacement),plateauCourant.yMax);
            perso.state = (perso.state + 1)%30;



            //afficher_personnage(perso,page);
        }
        if (key[KEY_S])
        {
            //clear_bitmap(page);
            //draw_plateau(plateauCourant,page);


            perso.direction = 0;
            plateauCourant.y = MAX(plateauCourant.y-collision_plateau(plateauCourant, perso, deplacement),plateauCourant.yMin);
            perso.state = (perso.state + 1)%30;



            //afficher_personnage(perso,page);
        }

        if (key[KEY_A])
        {
            //clear_bitmap(page);
            //draw_plateau(plateauCourant,page);


            perso.direction = 2;
            plateauCourant.x = MIN(plateauCourant.x+collision_plateau(plateauCourant, perso, deplacement),plateauCourant.xMax);
            perso.state = (perso.state + 1)%30;


            //afficher_personnage(perso,page);
        }
        if (key[KEY_D])
        {
            //clear_bitmap(page);
            //draw_plateau(plateauCourant,page);


            perso.direction = 3;
            plateauCourant.x = MAX(plateauCourant.x - collision_plateau(plateauCourant, perso, deplacement),plateauCourant.xMin);
            perso.state = (perso.state + 1)%30;


            //afficher_personnage(perso,page);
        }
        if (mouse_b & 2){
            if((mouse_x >= 200 && mouse_x <= 265) &&(mouse_y >= 300 && mouse_y <= 395)){
                message(lit,page);
                timer = 50;
            }
        }
        if (mouse_b & 1 || timer == 0){
            messageSupr();
        }

        plateauCourant = plateauCourant.changementPlateau(plateauCourant,&perso,page);



        clear_bitmap(page);
        draw_plateau(plateauCourant,page);
        afficher_personnage(perso,page);

        if (key[KEY_E]){
            draw_sprite(page,menu,460,0);
            if (key[KEY_H]){
                    printf("hola");
                if((mouse_x >= 0 && mouse_x <= 640) &&(mouse_y >= 0 && mouse_y <= 640)){
                    draw_sprite(page,sac,0,0);
                }
            }
        }

        blit(page,screen,0,0,0,0,800,600);
        rest(20);
        timer --;
        }
        return 0;

    }
}
END_OF_MAIN();
