#include "carrega_jogo.h"

/*
A função abaixo é responsável por controlar as entradas do teclado (qualquer
tecla pressionada durante a execução do jogo).
 */
void teclado(int fases_cenario[QTDE_FASES][2][TILES_X][TILES_Y], int *fase_atual, int *full_screen, int *ultima_movimentacao, int *frame, int *estado_jogo, int *score, int scores[10], int *sequencia, BITMAP *buffer, BITMAP *pacman, BITMAP *texturas[], BITMAP *sheet, BITMAP *score_back, SAMPLE *intro, MIDI *fase2, MIDI *fase3, SAMPLE *come) {
    /*
    Quando declaramos uma variável como sendo static quer dizer que mesmo saindo
    da função ela não vai perder o valor dela. Dessa forma, utilizamos a variável
    abaixo para controlar o tempo de uma tecla a outra.
     */

    static int buffer_teclado = FALSE;

    install_param_int(contador_teclado, (void *)&buffer_teclado, BUFFER_TECLADO);   

    //Tudo que estiver dentro o IF abaixo será executado a cada 30 ciclos de CPU
    if (buffer_teclado == TRUE) {
        //fullscreen mode
        if (key[KEY_ALT] && key[KEY_ENTER]) {

            if (*full_screen == TRUE) {
                set_windowed();
                show_mouse(screen);
            } else {
                set_full_screen();
            }

            *full_screen = (*full_screen == TRUE) ? FALSE : TRUE;
        }

        if ((*estado_jogo == JOGO) || (*estado_jogo == PAUSADO)) {
            // Muda o Cenário caso aperte a tecla espaço
            /*if (key[KEY_SPACE]) {
                if (*fase_atual < (QTDE_FASES - 1)) {
             *fase_atual = *fase_atual + 1;
                } else {
             *fase_atual = 0;
                }

                novo_contador(TEMPO_FASE);
             *score = 0;

                buffer_teclado = BUFFER_TECLADO;
            }*/

            if (key[KEY_P]) {
                if (*estado_jogo == JOGO) {
                    *estado_jogo = PAUSADO;
                    remove_int(contador);
                } else {
                    if (*estado_jogo == PAUSADO) {
                        *estado_jogo = JOGO;
                        install_int(contador, 1000);
                    }
                }
                buffer_teclado = FALSE;
            }

            while (keypressed()) {
                if (key[KEY_UP]) {
                    buffer_teclado = FALSE;
                    *ultima_movimentacao = DIR_UP;
                    if (anda_pacman(fases_cenario, DIR_UP, *fase_atual, frame)) break;
                }
                if (key[KEY_LEFT]) {
                    buffer_teclado = FALSE;
                    *ultima_movimentacao = DIR_LEFT;
                    if (anda_pacman(fases_cenario, DIR_LEFT, *fase_atual, frame)) break;
                }
                if (key[KEY_RIGHT]) {
                    buffer_teclado = FALSE;
                    *ultima_movimentacao = DIR_RIGHT;
                    if (anda_pacman(fases_cenario, DIR_RIGHT, *fase_atual, frame)) break;
                }
                if (key[KEY_DOWN]) {
                    buffer_teclado = FALSE;
                    *ultima_movimentacao = DIR_DOWN;
                    if (anda_pacman(fases_cenario, DIR_DOWN, *fase_atual, frame)) break;
                }
                break;
            }
        }

    }

    //Retorna para o menu principal caso a tecla V seja pressionada
    if (key[KEY_V]) {
        *estado_jogo = MENU;
    }

    if (key[KEY_ALT]) {
        come_numero(fases_cenario, fase_atual, estado_jogo, score, scores, sequencia, buffer, pacman, texturas, *ultima_movimentacao, sheet, score_back, intro, fase2, fase3, come);
    }
}
