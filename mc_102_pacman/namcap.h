/* 
 * File:   namcap.h
 * Author: User
 *
 * Created on 30 de Junho de 2010, 22:10
 */

#ifndef NAMCAP_H
#define	NAMCAP_H

#include "carrega_jogo.h"

/**
 *
 * @param fases_cenario
 * @param fase_atual
 * @param estado_jogo
 * @param score
 * @param scores
 * @param sequencia
 * @param buffer
 * @param pacman
 * @param texturas
 * @param ultima_movimentacao
 * @param sheet
 * @param score_back
 * @param intro
 * @param fase2
 * @param fase3
 * @param come
 */
void come_numero(int fases_cenario[QTDE_FASES][2][TILES_X][TILES_Y], int *fase_atual, int *estado_jogo, int *score, int scores[10], int *sequencia, BITMAP *buffer, BITMAP *pacman, BITMAP *texturas[], int ultima_movimentacao, BITMAP *sheet, BITMAP *score_back, SAMPLE *intro, MIDI *fase2, MIDI *fase3, SAMPLE *come);

/**
 * 
 * @param fases_cenario
 * @param direcao
 * @param fase_atual
 * @param frame
 * @return
 */
int anda_pacman(int fases_cenario[QTDE_FASES][2][TILES_X][TILES_Y], int direcao, int fase_atual, int *frame);


#endif	/* NAMCAP_H */
