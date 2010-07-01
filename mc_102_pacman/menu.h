/* 
 * File:   menu.h
 * Author: User
 *
 * Created on 30 de Junho de 2010, 22:10
 */

#ifndef MENU_H
#define	MENU_H

#include "carrega_jogo.h"

/**
 *
 * @param buffer
 * @param final
 * @param numeros
 * @param score
 */
void final_jogo(BITMAP *buffer, BITMAP *final, BITMAP *numeros, int score);

/**
 *
 * @param buffer
 * @param menu
 * @param botao_mouse_pressionado
 * @param estado_jogo
 * @param som_menu
 * @param menu_m
 */
void menu_jogo(BITMAP *buffer, BITMAP *menu, int *botao_mouse_pressionado, int *estado_jogo, SAMPLE *som_menu, MIDI *menu_m);

/**
 *
 * @param buffer
 * @param menu
 * @param botao_mouse_pressionado
 * @param estado_jogo
 * @param fases_cenario
 * @param fase_atual
 * @param score
 * @param som_menu
 * @param fase1
 * @param fase2
 * @param fase3
 * @param pacman
 * @param texturas
 * @param ultima_movimentacao
 * @param sheet
 * @param score_back
 * @param intro
 * @param menu_m
 */
void menu_sel_fase(BITMAP *buffer, BITMAP *menu, int *botao_mouse_pressionado, int *estado_jogo, int fases_cenario[QTDE_FASES][2][TILES_X][TILES_Y], int *fase_atual, int *score, SAMPLE *som_menu, MIDI *fase1, MIDI *fase2, MIDI *fase3, BITMAP *pacman, BITMAP *texturas[], int ultima_movimentacao, BITMAP *sheet, BITMAP *score_back, SAMPLE *intro, MIDI *menu_m);

/**
 * 
 * @param buffer
 * @param menu
 * @param botao_mouse_pressionado
 * @param estado_jogo
 * @param fases_cenario
 * @param fase_atual
 * @param score
 * @param som_menu
 * @param menu1
 * @param menu2
 * @param menu3
 * @param pacman
 * @param texturas
 * @param ultima_movimentacao
 * @param sheet
 * @param score_back
 * @param intro
 * @param fase1
 */
void menu_inicial_jogo(BITMAP *buffer, BITMAP *menu, int *botao_mouse_pressionado, int *estado_jogo, int fases_cenario[QTDE_FASES][2][TILES_X][TILES_Y], int *fase_atual, int *score, SAMPLE *som_menu, MIDI *menu1, MIDI *menu2, MIDI *menu3, BITMAP *pacman, BITMAP *texturas[], int ultima_movimentacao, BITMAP *sheet, BITMAP *score_back, SAMPLE *intro, MIDI *fase1);


#endif	/* MENU_H */

