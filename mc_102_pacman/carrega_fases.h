/*
 * File:   carrega_fases.h
 * Author: User
 *
 * Created on 4 de Junho de 2010, 23:34
 */

#ifndef _CARREGA_FASES_H
#define	_CARREGA_FASES_H

#include "carrega_jogo.h"

/**
 * 
 * @param pacman
 * @param pacman2
 * @param texturas
 * @param numeros
 */
void carrega_texturas(BITMAP *pacman, BITMAP *pacman2, BITMAP *texturas[], BITMAP *numeros);

/**
 *
 * @param fases_cenario
 */
void carrega_matriz_jogo(int fases_cenario[QTDE_FASES][2][TILES_X][TILES_Y]);

/**
 *
 * @param buffer
 * @param fase_atual
 * @param fases_cenario
 * @param pacman
 * @param texturas
 * @param ultima_movimentacao
 * @param sheet
 */
void atualiza_tela(BITMAP *buffer, int fase_atual, int fases_cenario[QTDE_FASES][2][TILES_X][TILES_Y], BITMAP *pacman, BITMAP *texturas[], int ultima_movimentacao, BITMAP *sheet);

/**
 *
 * @param mat
 * @param fase
 */
void fase_funcao(int mat[], int fase);

/**
 *
 * @param mat
 * @param fase
 */
void fase_numeros_errados(int mat[], int fase);

/**
 *
 * @param numero_fase
 * @return
 */
char *nome_funcao(int numero_fase);

#endif	/* _CARREGA_FASES_H */
