/*
 * File:   carrega_fases.h
 * Author: User
 *
 * Created on 4 de Junho de 2010, 23:34
 */

#ifndef _CARREGA_FASES_H
#define	_CARREGA_FASES_H

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

void carrega_texturas(BITMAP *, BITMAP *[]);
void carrega_matriz_jogo(int [QTDE_FASES][2][TILES_X][TILES_Y]);
void atualiza_tela(BITMAP *, int, int [QTDE_FASES][2][TILES_X][TILES_Y], BITMAP *, BITMAP *[], int);
void novo_contador(int);
void contador();
void update_timer(BITMAP *, BITMAP *);

#endif	/* _CARREGA_FASES_H */

