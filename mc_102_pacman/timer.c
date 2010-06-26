#include <allegro.h>

int vcontador = 0;

void novo_contador(int novo) {
    vcontador = novo;
}

void contador()
{
   vcontador--;
}

void update_timer(BITMAP *buffer, BITMAP *sheet) {
    BITMAP *bolinha;
    bolinha = create_bitmap(9, 9);
    rectfill(bolinha, 0, 0, 8, 8, makecol(255, 0, 255));
    circlefill(bolinha, 4, 4, 3, makecol(255,255,255));
    int seg, min;
    min = vcontador/60;
    seg = vcontador%60;
    draw_sprite(buffer, bolinha, 590, 5);
    draw_sprite(buffer, bolinha, 590, 15);
    masked_blit(sheet, buffer, 0, (min/10)*30, 550, 0, sheet->w, 27);
    masked_blit(sheet, buffer, 0, (min%10)*30, 570, 0, sheet->w, 27);
    masked_blit(sheet, buffer, 0, (seg/10)*30, 600, 0, sheet->w, 27);
    masked_blit(sheet, buffer, 0, (seg%10)*30, 620, 0, sheet->w, 27);
    destroy_bitmap(bolinha);
    vsync();
}


