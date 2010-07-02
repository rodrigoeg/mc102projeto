#ifndef CARREGA_JOGO_H
#define	CARREGA_JOGO_H

//Carregamento de todas as bibliotecas necessarias no jogo e suas principais constantes

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


//Define a duração de cada fase
#define TEMPO_FASE 90

#define BUFFER_TECLADO 50

#define TEMPO_TECLADO 5

#define QTDE_FASES 3 // Jogo com 3 fases
#define TAMANHO_TILES_X 32 // Largura do Tile
#define TAMANHO_TILES_Y 32 // Altura do Tile
#define QTDE_TILES_X 20 // Qtde de Tiles na horizontal - 32*20 = 640;
#define QTDE_TILES_Y 15 // Qtde de Tiles na vertical   - 32*15 = 480;

//Dimenções do mapa
#define FUNDO 0
#define FRENTE 1

//Direções do Namcap
#define DIR_UP 0
#define DIR_DOWN 1
#define DIR_LEFT 2
#define DIR_RIGHT 3
#define QTDE_SEQUENCIA 5

#include "carrega_fases.h"
#include "contador.h"
#include "score.h"
#include "menu.h"
#include "namcap.h"
#include "teclado.h"


#endif	/* CARREGA_JOGO_H */
