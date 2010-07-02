#ifndef NAMCAP_H
#define	NAMCAP_H

#include "carrega_jogo.h"

/**
 * Apaga o numero comido da matriz
 * @param fases_cenario int[][][][]
 * @param fase_atual int*
 * @param estado_jogo int*
 * @param score int*
 * @param scores int[]
 * @param sequencia int*
 * @param buffer BITMAP*
 * @param namcap BITMAP*
 * @param texturas BITMAP*[]
 * @param ultima_movimentacao int
 * @param sheet BITMAP*
 * @param score_back BITMAP*
 * @param intro SAMPLE*
 * @param fase2 MIDI*
 * @param fase3 MIDI*
 * @param come SAMPLE*
 */
void come_numero(int fases_cenario[QTDE_FASES][2][QTDE_TILES_X][QTDE_TILES_Y], int *fase_atual, int *estado_jogo, int *score, int scores[10], int *sequencia, BITMAP *buffer, BITMAP *namcap, BITMAP *texturas[], int ultima_movimentacao, BITMAP *sheet, BITMAP *score_back, SAMPLE *intro, MIDI *fase2, MIDI *fase3, SAMPLE *come);

/**
 * Faz com que o Namcap ande de acordo com a uma direção
 * @param fases_cenario int[][][][]
 * @param direcao int
 * @param fase_atual int
 * @param frame int*
 * @return int 
 */
int anda_namcap(int fases_cenario[QTDE_FASES][2][QTDE_TILES_X][QTDE_TILES_Y], int direcao, int fase_atual, int *frame);


#endif	/* NAMCAP_H */
