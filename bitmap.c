#include <stdio.h>
#include "bitmap.h"
#include <allegro.h>

fondBlanc = load_bitmap("fondBlanc.bmp",NULL);
if (!fondBlanc)
{
    allegro_message("prb allocation BITMAP fondBlanc");
    exit(EXIT_FAILURE);
}

BITMAP * getFondBlanc(){
    return fondBlanc;
}
