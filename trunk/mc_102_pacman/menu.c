#include "carrega_jogo.h"

void menu_inicial_jogo(BITMAP *buffer, BITMAP *menu, int *botao_mouse_pressionado, int *estado_jogo, int fases_cenario[QTDE_FASES][2][TILES_X][TILES_Y], int *fase_atual, int *score, SAMPLE *som_menu, MIDI *menu1, MIDI *menu2, MIDI *menu3, BITMAP *pacman, BITMAP *texturas[], int ultima_movimentacao, BITMAP *sheet, BITMAP *score_back, SAMPLE *intro, MIDI *fase1) {

    if (*botao_mouse_pressionado == FALSE) {
        if (mouse_b & 1) {
            *botao_mouse_pressionado = TRUE;
        }
    } else {
        if (!(mouse_b & 1)) {
            *botao_mouse_pressionado = FALSE;
            if ((mouse_x > 230 && mouse_x < 390) && (mouse_y > 280 && mouse_y < 305)) {
                play_sample(som_menu, 500, 0, 2000, 0);
                *estado_jogo = JOGO;
                carrega_matriz_jogo(fases_cenario);
                // Contador
                install_int(contador, 1000);
                novo_contador(TEMPO_FASE);
                clear_bitmap(buffer);
                *fase_atual = 0;
                *score = 0;
                atualiza_tela(buffer, 0, fases_cenario, pacman, texturas, ultima_movimentacao, sheet);
                draw_sprite(buffer, score_back, 0, 0);
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                stop_midi();
                play_sample(intro, 500, 0, 1000, 0);
                rest(4000);
                play_midi(fase1, TRUE);
            }

            if ((mouse_x > 195 && mouse_x < 430) && (mouse_y > 320 && mouse_y < 340)) {
                play_sample(som_menu, 500, 0, 2000, 0);
                stop_midi();
                play_midi(menu1, TRUE);
                *estado_jogo = MENU_SELECIONAR_FASE;
            }

            if ((mouse_x > 265 && mouse_x < 350) && (mouse_y > 355 && mouse_y < 375)) {
                play_sample(som_menu, 500, 0, 2000, 0);
                stop_midi();
                play_midi(menu2, TRUE);
                *estado_jogo = MENU_SCORES;
            }


            if ((mouse_x > 240 && mouse_x < 386) && (mouse_y > 390 && mouse_y < 410)) {
                play_sample(som_menu, 500, 0, 2000, 0);
                stop_midi();
                play_midi(menu3, TRUE);
                *estado_jogo = MENU_INSTRUCOES;
            }

            if ((mouse_x > 280 && mouse_x < 340) && (mouse_y > 420 && mouse_y < 445)) {
                play_sample(som_menu, 500, 0, 2000, 0);
                *estado_jogo = SAIR;
            }


        }
    }
    draw_sprite(buffer, menu, 0, 0);
}

void menu_sel_fase(BITMAP *buffer, BITMAP *menu, int *botao_mouse_pressionado, int *estado_jogo, int fases_cenario[QTDE_FASES][2][TILES_X][TILES_Y], int *fase_atual, int *score, SAMPLE *som_menu, MIDI *fase1, MIDI *fase2, MIDI *fase3, BITMAP *pacman, BITMAP *texturas[], int ultima_movimentacao, BITMAP *sheet, BITMAP *score_back, SAMPLE *intro, MIDI *menu_m) {

    if (*botao_mouse_pressionado == FALSE) {
        if (mouse_b & 1) {
            *botao_mouse_pressionado = TRUE;
        }
    } else {
        if (!(mouse_b & 1)) {
            *botao_mouse_pressionado = FALSE;
            if ((mouse_x > 70 && mouse_x < 400) && (mouse_y > 125 && mouse_y < 165)) {
                play_sample(som_menu, 500, 0, 2000, 0);
                *estado_jogo = JOGO;
                carrega_matriz_jogo(fases_cenario);
                // Contador
                install_int(contador, 1000);
                novo_contador(TEMPO_FASE);
                clear_bitmap(buffer);
                *fase_atual = 0;
                *score = 0;
                atualiza_tela(buffer, 0, fases_cenario, pacman, texturas, ultima_movimentacao, sheet);
                draw_sprite(buffer, score_back, 0, 0);
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                stop_midi();
                play_sample(intro, 500, 0, 1000, 0);
                rest(4000);
                play_midi(fase1, TRUE);
            }

            if ((mouse_x > 70 && mouse_x < 440) && (mouse_y > 195 && mouse_y < 240)) {
                play_sample(som_menu, 500, 0, 2000, 0);
                *estado_jogo = JOGO;
                carrega_matriz_jogo(fases_cenario);
                // Contador
                install_int(contador, 1000);
                novo_contador(TEMPO_FASE);
                clear_bitmap(buffer);
                *fase_atual = 1;
                *score = 0;
                atualiza_tela(buffer, 1, fases_cenario, pacman, texturas, ultima_movimentacao, sheet);
                draw_sprite(buffer, score_back, 0, 0);
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                stop_midi();
                play_sample(intro, 500, 0, 1000, 0);
                rest(4000);
                play_midi(fase2, TRUE);
            }

            if ((mouse_x > 70 && mouse_x < 390) && (mouse_y > 270 && mouse_y < 315)) {
                play_sample(som_menu, 500, 0, 2000, 0);
                *estado_jogo = JOGO;
                carrega_matriz_jogo(fases_cenario);
                // Contador
                install_int(contador, 1000);
                novo_contador(TEMPO_FASE);
                clear_bitmap(buffer);
                *fase_atual = 2;
                *score = 0;
                atualiza_tela(buffer, 2, fases_cenario, pacman, texturas, ultima_movimentacao, sheet);
                draw_sprite(buffer, score_back, 0, 0);
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                stop_midi();
                play_sample(intro, 500, 0, 1000, 0);
                rest(4000);
                play_midi(fase3, TRUE);
            }

            if ((mouse_x > 20 && mouse_x < 100) && (mouse_y > 440 && mouse_y < 460)) {
                play_sample(som_menu, 500, 0, 2000, 0);
                stop_midi();
                play_midi(menu_m, TRUE);
                *estado_jogo = MENU;
            }
        }

    }
     draw_sprite(buffer, menu, 0, 0);
}

void menu_jogo(BITMAP *buffer, BITMAP *menu, int *botao_mouse_pressionado, int *estado_jogo, SAMPLE *som_menu, MIDI *menu_m) {
    if (*botao_mouse_pressionado == FALSE) {
        if (mouse_b & 1) {
            *botao_mouse_pressionado = TRUE;
        }
    } else {
        if (!(mouse_b & 1)) {
            *botao_mouse_pressionado = FALSE;

            if ((mouse_x > 20 && mouse_x < 100) && (mouse_y > 440 && mouse_y < 460)) {
                play_sample(som_menu, 500, 0, 2000, 0);
                stop_midi();
                play_midi(menu_m, TRUE);
                *estado_jogo = MENU;
            }
        }
    }
    draw_sprite(buffer, menu, 0, 0);
}

void final_jogo(BITMAP *buffer, BITMAP *final, BITMAP *numeros, int score) {
    int num;
    int digitos = 1;
    int digitos_inicial = 1;

    draw_sprite(buffer, final, 0, 0);

    if (score < 0) {
        //colocar sinal de menos
        masked_blit(numeros, buffer, 0, (10)*30, 265, 185, numeros->w, 27);
        score = -score;
    }

    num = score;
    while (num / 10 > 0) {
        num /= 10;
        digitos++;
    }

    digitos_inicial = digitos;

    while (digitos > 0) {
        if (digitos > 1) {
            masked_blit(numeros, buffer, 0, (int) (score / ((digitos - 1)*10))*30, (digitos_inicial - digitos)*20 + 285, 185, numeros->w, 27);
            score -= ((digitos - 1) * 10 * ((int) (score / ((digitos - 1)*10))));
        } else {

            masked_blit(numeros, buffer, 0, score * 30, (digitos_inicial - digitos)*20 + 285, 185, numeros->w, 27);
        }

        digitos--;
    }
}
