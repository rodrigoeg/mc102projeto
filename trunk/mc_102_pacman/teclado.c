#include "carrega_jogo.h"


int set_full_screen() {
    // inicializa o modo gráfico com a resolução definida em modo tela cheia
    if (set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, LARGURA_TELA, ALTURA_TELA, 0, 0)) {
        allegro_message(allegro_error);
        return FALSE;
    }

    return TRUE;
}

int set_windowed() {
    // inicializa o modo gráfico com a resolução definida em modo janela
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, LARGURA_TELA, ALTURA_TELA, 0, 0)) {
        allegro_message(allegro_error);
        return FALSE;
    }
    return TRUE;
}

/*
A função abaixo é responsável por controlar as entradas do teclado (qualquer
tecla pressionada durante a execução do jogo).
 */
void teclado(int fases_cenario[QTDE_FASES][2][QTDE_TILES_X][QTDE_TILES_Y], int *fase_atual, int *full_screen, int *ultima_movimentacao, int *frame, int *estado_jogo, int *score, int scores[10], int *sequencia, BITMAP *buffer, BITMAP *namcap, BITMAP *texturas[], BITMAP *sheet, BITMAP *score_back, SAMPLE *intro, MIDI *fase2, MIDI *fase3, SAMPLE *come) {

    static int buffer_teclado = 10;

    install_param_int(contador_teclado, (void *)&buffer_teclado, BUFFER_TECLADO);   

    if (buffer_teclado == 0) {
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
                buffer_teclado = TEMPO_TECLADO;
            }

            while (keypressed()) {
                if (key[KEY_UP]) {
                    buffer_teclado = TEMPO_TECLADO;
                    *ultima_movimentacao = DIR_UP;
                    if (anda_namcap(fases_cenario, DIR_UP, *fase_atual, frame)) break;
                }
                if (key[KEY_LEFT]) {
                    buffer_teclado = TEMPO_TECLADO;
                    *ultima_movimentacao = DIR_LEFT;
                    if (anda_namcap(fases_cenario, DIR_LEFT, *fase_atual, frame)) break;
                }
                if (key[KEY_RIGHT]) {
                    buffer_teclado = TEMPO_TECLADO;
                    *ultima_movimentacao = DIR_RIGHT;
                    if (anda_namcap(fases_cenario, DIR_RIGHT, *fase_atual, frame)) break;
                }
                if (key[KEY_DOWN]) {
                    buffer_teclado = TEMPO_TECLADO;
                    *ultima_movimentacao = DIR_DOWN;
                    if (anda_namcap(fases_cenario, DIR_DOWN, *fase_atual, frame)) break;
                }
                break;
            }
        }

    } else {
        if(buffer_teclado < 0) {
            buffer_teclado = 0;
        }
    }

    //Retorna para o menu principal caso a tecla V seja pressionada
    if (key[KEY_V]) {
        *estado_jogo = MENU;
    }

    if (key[KEY_ALT]) {
        come_numero(fases_cenario, fase_atual, estado_jogo, score, scores, sequencia, buffer, namcap, texturas, *ultima_movimentacao, sheet, score_back, intro, fase2, fase3, come);
    }
}
