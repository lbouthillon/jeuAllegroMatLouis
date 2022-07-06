#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#define NB_CASES_LONG 15
#define NB_CASES_LARG 7


int main()
{
    BITMAP *page;
    BITMAP *sol;
    BITMAP *heros;
    allegro_init();
    install_keyboard();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,600,196,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    else{
        int x = 0;
        int y = 0;
        page = create_bitmap(600,196);
        sol = load_bitmap("sol.bmp",NULL);
        if (!sol)
        {
            allegro_message("prb allocation BITMAP sol");
            exit(EXIT_FAILURE);
        }
        heros = load_bitmap("heros.bmp",NULL);
        if (!heros)
        {
            allegro_message("prb allocation BITMAP heros");
            exit(EXIT_FAILURE);
        }
        for (int largeur = 0 ; largeur < NB_CASES_LARG; largeur++ ) {
            for (int longueur = 0 ; longueur < NB_CASES_LONG; longueur++ ) {
                draw_sprite(page,sol,x,y);
                x = x + 40;
            }
            y = y + 28;
            x = 0;
        }
        draw_sprite(page,heros,285,63);
        blit(page,screen,0,0,0,0,600,196);
        while(1);
    }
}END_OF_MAIN();
