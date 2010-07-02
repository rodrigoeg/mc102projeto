#ifndef TECLADO_H
#define	TECLADO_H

#include "carrega_jogo.h"

/**
 * Faz todas as funcionalidades do teclado
 * @param fases_cenario int[][][][]
 * @param fase_atual int*
 * @param full_screen int*
 * @param ultima_movimentacao int*
 * @param frame int*
 * @param estado_jogo int*
 * @param score int*
 * @param scores int[]
 * @param sequencia int*
 * @param buffer BITMAP*
 * @param namcap BITMAP*
 * @param texturas BITMAP*[]
 * @param sheet BITMAP*
 * @param score_back BITMAP*
 * @param intro SAMPLE*
 * @param fase2 MIDI*
 * @param fase3 MIDI*
 * @param come SAMPLE*
 */
void teclado(int fases_cenario[QTDE_FASES][2][QTDE_TILES_X][QTDE_TILES_Y], int *fase_atual, int *full_screen, int *ultima_movimentacao, int *frame, int *estado_jogo, int *score, int scores[10],  int *sequencia, BITMAP *buffer, BITMAP *namcap, BITMAP *texturas[], BITMAP *sheet, BITMAP *score_back, SAMPLE *intro, MIDI *fase2, MIDI *fase3, SAMPLE *come);

#endif	/* TECLADO_H */
