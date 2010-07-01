/* 
 * File:   carrega_jogo.h
 * Author: User
 *
 * Created on 30 de Junho de 2010, 22:08
 */

#ifndef CARREGA_JOGO_H
#define	CARREGA_JOGO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>
#include <math.h>

#define LARGURA_TELA 640
#define ALTURA_TELA 480

//Estados do jogo

#define MENU 0
#define MENU_SELECIONAR_FASE 1
#define MENU_INSTRUCOES 2
#define JOGO 3
#define FINAL 4
#define SAIR 5
#define PAUSADO 6
#define MENU_SCORES 7

#define TEMPO_FASE 60

/*
 * File:   carrega_jogo.h
 * Author: User
 *
 * Created on 30 de Junho de 2010, 22:10
 */

#define BUFFER_TECLADO 150

#define QTDE_FASES 3 // Jogo com 3 fases
#define TAM_TILES_X 32 // Largura do Tile
#define TAM_TILES_Y 32 // Altura do Tile
#define TILES_X 20 // Qtde de Tiles na horizontal - 32*20 = 640;
#define TILES_Y 15 // Qtde de Tiles na vertical   - 32*15 = 480;
#define FUNDO 0
#define FRENTE 1
#define DIR_UP 0
#define DIR_DOWN 1
#define DIR_LEFT 2
#define DIR_RIGHT 3
#define QTDE_SEQUENCIA 5

#include "carrega_fases.h"
#include "contador.h"
#include "score.h"



#endif	/* CARREGA_JOGO_H */

