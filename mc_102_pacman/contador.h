/*
 * File:   contador.h
 * Author: User
 *
 * Created on 30 de Junho de 2010, 22:10
 */

#ifndef CONTADOR_H_INCLUDED
#define CONTADOR_H_INCLUDED

#include "carrega_jogo.h"

//funções que controlam o tempo do jogo

/**
 * Coloca o um valor (em segundos) para o contador
 * @param novo int valor do novo contador
 */
void novo_contador(int novo);

/**
 * Funcao que é chamada para contagem de tempo
 */
void contador();

/**
 * Exibe o contador de tempo na tela do jogo
 * @param buffer BITMAP* contendo o bitmap a ser usado como destino
 * @param sheet BITMAP* contendo as imagens dos numeros
 * @return int se for TRUE é porque ainda não acabou o tempo. Se o tempo acabou então é retornado FALSE
 */
int atualizar_contador(BITMAP *buffer, BITMAP *sheet);

/**
 * Executado para deixar o jogador se movimentar
 * @param buffer_teclado void* estado atual de movimentação
 */
void contador_teclado(void *buffer_teclado);

#endif //CONTADOR_H_INCLUDED
