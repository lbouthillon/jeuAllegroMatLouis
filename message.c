#include <stdio.h>
#include "plateau.h"
#include "decor.h"
#include <allegro.h>


void message(char chaine[],BITMAP * page){
    printf("%d",strlen(chaine));
    int x = 10;
    int y = 630;
    int a = 10;
    int b = 630;
    for (int i = 0 ; i<strlen(chaine); i++){
        rest(50);
        textprintf_ex(screen, font, x, y, makecol(255, 255, 0), -1, "%c", chaine[i]);
        x = x + 10;
    }
}
