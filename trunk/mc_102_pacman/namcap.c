#include "carrega_jogo.h"

//apaga o numero da matriz e verifica se a numero é da sequencia da funcao
void come_numero(int fases_cenario[QTDE_FASES][2][QTDE_TILES_X][QTDE_TILES_Y], int *fase_atual, int *estado_jogo, int *score, int scores[10], int *sequencia, BITMAP *buffer, BITMAP *namcap, BITMAP *texturas[], int ultima_movimentacao, BITMAP *sheet, BITMAP *score_back, SAMPLE *intro, MIDI *fase2, MIDI *fase3, SAMPLE *come) {
    int y, x;
    int i;
    int mat[5];
    int parar = FALSE;
    fase_funcao(mat, *fase_atual);

    for (y = 0; ((y < QTDE_TILES_Y) && (parar != TRUE)); y++) {
        for (x = 0; ((x < QTDE_TILES_X) && (parar != TRUE)); x++) {
            if ((char) fases_cenario[*fase_atual][FUNDO][x][y] == 'P') { // namcap
                parar = TRUE;
            }
        }
    }

    if (fases_cenario[*fase_atual][FRENTE][x - 1][y - 1] == mat[*sequencia]) {
        fases_cenario[*fase_atual][FRENTE][x - 1][y - 1] = -1;
        *score = calcula_score(mat[*sequencia], *score);
        *sequencia = *sequencia + 1;
        play_sample(come, 500, 50, 1000, 0);
    } else {
        if (fases_cenario[*fase_atual][FRENTE][x - 1][y - 1] != -1) {
            for (i = 0; i < 5; i++) {
                if (fases_cenario[*fase_atual][FRENTE][x - 1][y - 1] == mat[i]) {
                    *sequencia = *sequencia + 1;
                    break;
                }
            }
            *score = calcula_score(-(fases_cenario[*fase_atual][FRENTE][x - 1][y - 1]), *score);
            fases_cenario[*fase_atual][FRENTE][x - 1][y - 1] = -1;
            play_sample(come, 500, 50, 1000, 0);
        }
    }

    if (*sequencia == QTDE_SEQUENCIA) {
        if (*fase_atual < QTDE_FASES - 1) {
            *fase_atual = *fase_atual + 1;
            *sequencia = 0;
            novo_contador(TEMPO_FASE);
            clear_bitmap(buffer);
            atualiza_tela(buffer, *fase_atual, fases_cenario, namcap, texturas, ultima_movimentacao, sheet);
            draw_sprite(buffer, score_back, 0, 0);
            blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            stop_midi();
            play_sample(intro, 500, 50, 1000, 0);
            rest(4000);
            switch(*fase_atual) {
                case 1: {
                    play_midi(fase2, TRUE);
                    break;
                }
                case 2: {
                    play_midi(fase3, TRUE);
                    break;
                }
            }
            novo_contador(TEMPO_FASE);
        } else {            
            *estado_jogo = FINAL;
            le_score(scores);
            salva_score(scores, *score);
        }
    }
}

int anda_namcap(int fases_cenario[QTDE_FASES][2][QTDE_TILES_X][QTDE_TILES_Y], int direcao, int fase_atual, int *frame) {
    int x = 0;
    int y = 0;
    int posicao_x = 0;
    int posicao_y = 0;

    for (y = 0; y < QTDE_TILES_Y; y++) {
        for (x = 0; x < QTDE_TILES_X; x++) {
            if ((char) fases_cenario[fase_atual][FUNDO][x][y] == 'P') { // namcap
                posicao_x = x;
                posicao_y = y;
                x = QTDE_TILES_X;
                y = QTDE_TILES_Y;
            }
        }
    }

    switch (direcao) {
        case DIR_UP:
            if (fases_cenario[fase_atual][FUNDO][posicao_x][posicao_y - 1] != '#') {
                fases_cenario[fase_atual][FUNDO][posicao_x][posicao_y] = fases_cenario[fase_atual][FUNDO][posicao_x][posicao_y - 1];
                fases_cenario[fase_atual][FUNDO][posicao_x][posicao_y - 1] = 'P';
                *frame = (*frame + 1) % 2;
                return 1;
            }
            break;
        case DIR_DOWN:
            if (fases_cenario[fase_atual][FUNDO][posicao_x][posicao_y + 1] != '#') {
                fases_cenario[fase_atual][FUNDO][posicao_x][posicao_y] = fases_cenario[fase_atual][FUNDO][posicao_x][posicao_y + 1];
                fases_cenario[fase_atual][FUNDO][posicao_x][posicao_y + 1] = 'P';
                *frame = (*frame + 1) % 2;
                return 1;
            }
            break;
        case DIR_LEFT:
            if (fases_cenario[fase_atual][FUNDO][posicao_x - 1][posicao_y] != '#') {
                fases_cenario[fase_atual][FUNDO][posicao_x][posicao_y] = fases_cenario[fase_atual][FUNDO][posicao_x - 1][posicao_y];
                fases_cenario[fase_atual][FUNDO][posicao_x - 1][posicao_y] = 'P';
                *frame = (*frame + 1) % 2;
                return 1;
            }
            break;
        case DIR_RIGHT:
            if (fases_cenario[fase_atual][FUNDO][posicao_x + 1][posicao_y] != '#') {
                fases_cenario[fase_atual][FUNDO][posicao_x][posicao_y] = fases_cenario[fase_atual][FUNDO][posicao_x + 1][posicao_y];
                fases_cenario[fase_atual][FUNDO][posicao_x + 1][posicao_y] = 'P';
                *frame = (*frame + 1) % 2;
                return 1;
            }
            break;
    }
    return 0;
}

