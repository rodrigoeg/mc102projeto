#ifndef MENU_H
#define	MENU_H

#include "carrega_jogo.h"

/**
 * Exibe a tela de fim de jogo
 * @param buffer BITMAP*
 * @param final BITMAP*
 * @param numeros BITMAP*
 * @param score int
 */
void final_jogo(BITMAP *buffer, BITMAP *final, BITMAP *numeros, int score);

/**
 * Funçao generica que faz alguns menus do jogo
 * @param buffer BITMAP*
 * @param menu BITMAP*
 * @param botao_mouse_pressionado int*
 * @param estado_jogo int*
 * @param som_menu SAMPLE*
 * @param menu_m MIDI*
 */
void menu_jogo(BITMAP *buffer, BITMAP *menu, int *botao_mouse_pressionado, int *estado_jogo, SAMPLE *som_menu, MIDI *menu_m);

/**
 * Mostra o menu de seleção de fazes
 * @param buffer BITMAP*
 * @param menu BITMAP*
 * @param botao_mouse_pressionado int*
 * @param estado_jogo int*
 * @param fases_cenario int[][][][]
 * @param fase_atual int*
 * @param score int*
 * @param som_menu SAMPLE*
 * @param fase1 MIDI*
 * @param fase2 MIDI*
 * @param fase3 MIDI*
 * @param namcap BITMAP*
 * @param texturas BITMAP*
 * @param ultima_movimentacao
 * @param sheet BITMAP*
 * @param score_back BITMAP*
 * @param intro SAMPLE*
 * @param menu_m MIDI*
 */
void menu_sel_fase(BITMAP *buffer, BITMAP *menu, int *botao_mouse_pressionado, int *estado_jogo, int fases_cenario[QTDE_FASES][2][QTDE_TILES_X][QTDE_TILES_Y], int *fase_atual, int *score, SAMPLE *som_menu, MIDI *fase1, MIDI *fase2, MIDI *fase3, BITMAP *namcap, BITMAP *texturas[], int ultima_movimentacao, BITMAP *sheet, BITMAP *score_back, SAMPLE *intro, MIDI *menu_m);

/**
 * Mostra o menu inicial do jogo
 * @param buffer BITMAP*
 * @param menu BITMAP*
 * @param botao_mouse_pressionado int*
 * @param estado_jogo int*
 * @param fases_cenario int[][][][]
 * @param fase_atual int*
 * @param score int*
 * @param som_menu SAMPLE*
 * @param menu1 MIDI*
 * @param menu2 MIDI*
 * @param menu3 MIDI*
 * @param namcap BITMAP*
 * @param texturas BITMAP*
 * @param ultima_movimentacao
 * @param sheet BITMAP*
 * @param score_back BITMAP*
 * @param intro SAMPLE*
 * @param fase1 MIDI*
 */
void menu_inicial_jogo(BITMAP *buffer, BITMAP *menu, int *botao_mouse_pressionado, int *estado_jogo, int fases_cenario[QTDE_FASES][2][QTDE_TILES_X][QTDE_TILES_Y], int *fase_atual, int *score, SAMPLE *som_menu, MIDI *menu1, MIDI *menu2, MIDI *menu3, BITMAP *namcap, BITMAP *texturas[], int ultima_movimentacao, BITMAP *sheet, BITMAP *score_back, SAMPLE *intro, MIDI *fase1);


#endif	/* MENU_H */
