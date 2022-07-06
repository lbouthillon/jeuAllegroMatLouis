#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "plateau.h"
#include "personnage.h"
#define NB_CASES_LONG 15
#define NB_CASES_LARG 15


int main()
{
    BITMAP *page;

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
        page = init_page();

        PERSONNAGE perso = {0,0,0,0};

        afficher_personnage(perso,page);

        blit(page,screen,0,0,0,0,length,width);
        while(1)
        {

        };
    }
}END_OF_MAIN();
