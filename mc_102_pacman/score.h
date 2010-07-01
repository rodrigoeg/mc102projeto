/*
 * File:   score.h
 * Author: User
 *
 * Created on 30 de Junho de 2010, 22:10
 */

#ifndef SCORE_H
#define	SCORE_H

/**
 * Carrega os scores do arquivo texto no array
 * @param scores  int array de scores em ordem decrescente
 */
void le_score(int scores[10]);

/**
 * Salva no arquivo o score atual
 * @param scores int array contendo os scores antigos
 * @param score int score atual
 */
void salva_score(int scores[10], int score);

/**
 * Mostra o score do jogador no jogo
 * @param buffer BITMAP* buffer onde o score será escrito
 * @param numeros BITMAP* de numeros
 * @param score_bmp BITMAP* imagem do score
 * @param score int score do jogador
 */
void update_score(BITMAP *buffer, BITMAP *numeros, BITMAP *score_bmp, int score);

/**
 * Calcula o novo score do jogador
 * @param pontos int pontação a ser adicionada
 * @param total int score total
 * @return int nova pontuação
 */
int calcula_score(int pontos, int total);

/**
 * Mostra os maiores scores do jogo
 * @param buffer BITMAP* com o buffer onde os scores serão escritos
 * @param scores int array contendo os scores
 */
void mostrar_scores(BITMAP *buffer, int scores[10]);

#endif	/* SCORE_H */
