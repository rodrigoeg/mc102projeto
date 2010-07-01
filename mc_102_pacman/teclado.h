/* 
 * File:   teclado.h
 * Author: User
 *
 * Created on 30 de Junho de 2010, 22:10
 */

#ifndef TECLADO_H
#define	TECLADO_H

#include "carrega_jogo.h"

/**
 * 
 * @param fases_cenario
 * @param fase_atual
 * @param full_screen
 * @param ultima_movimentacao
 * @param frame
 * @param estado_jogo
 * @param score
 * @param scores
 * @param sequencia
 * @param buffer
 * @param pacman
 * @param texturas
 * @param sheet
 * @param score_back
 * @param intro
 * @param fase2
 * @param fase3
 * @param come
 */
void teclado(int fases_cenario[QTDE_FASES][2][TILES_X][TILES_Y], int *fase_atual, int *full_screen, int *ultima_movimentacao, int *frame, int *estado_jogo, int *score, int scores[10],  int *sequencia, BITMAP *buffer, BITMAP *pacman, BITMAP *texturas[], BITMAP *sheet, BITMAP *score_back, SAMPLE *intro, MIDI *fase2, MIDI *fase3, SAMPLE *come);

#endif	/* TECLADO_H */