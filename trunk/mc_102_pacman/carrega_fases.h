#ifndef _CARREGA_FASES_H
#define	_CARREGA_FASES_H

#include "carrega_jogo.h"

/**
 * Faz o carregamento das fases na matriz
 * @param fases_cenario int[][][][]
 */
void carrega_matriz_jogo(int fases_cenario[QTDE_FASES][2][QTDE_TILES_X][QTDE_TILES_Y]);

/**
 * Função que atualiza a tela do jogo
 * @param buffer BITMAP*
 * @param fase_atual int
 * @param fases_cenario int[][][][]
 * @param namcap BITMAP*
 * @param texturas BITMAP*[]
 * @param ultima_movimentacao int
 * @param sheet BITMAP*
 */
void atualiza_tela(BITMAP *buffer, int fase_atual, int fases_cenario[QTDE_FASES][2][QTDE_TILES_X][QTDE_TILES_Y], BITMAP *namcap, BITMAP *texturas[], int ultima_movimentacao, BITMAP *sheet);

/**
 * Retorna os numeros de uma determinada função
 * @param mat int[]
 * @param fase int
 */
void fase_funcao(int mat[], int fase);

/**
 * Retorna um array com os numeros que não pertencem a função correta
 * @param mat int[]
 * @param fase int
 */
void fase_numeros_errados(int mat[], int fase);

/**
 * Retorna o nome da funcao para escrever na fase atual
 * @param numero_fase int
 * @return char
 */
char *nome_funcao(int numero_fase);

#endif	/* _CARREGA_FASES_H */
