#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>
#include <math.h>
#include "carrega_fases.h"
#include "timer.h"
#include "score.h"

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

#define TEMPO_FASE 20

#define BUFFER_TECLADO 130

//global que define o estado do "X" da janela do programa, usado para fechá-lo.
volatile int close_button_pressed = FALSE;

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

void menu_inicial_jogo(BITMAP *buffer, BITMAP *menu, int *botao_mouse_pressionado, int *estado_jogo, int fases_cenario[QTDE_FASES][2][TILES_X][TILES_Y], int *fase_atual, int *score, SAMPLE *som_menu, MIDI *menu1, MIDI *menu2, MIDI *menu3, BITMAP *pacman, BITMAP *texturas[], int ultima_movimentacao, BITMAP *sheet, BITMAP *score_back, SAMPLE *intro, MIDI *fase1) {

    if (*botao_mouse_pressionado == FALSE) {
        if (mouse_b & 1) {
            *botao_mouse_pressionado = TRUE;
        }
    } else {
        if (!(mouse_b & 1)) {
            *botao_mouse_pressionado = FALSE;
            if ((mouse_x > 230 && mouse_x < 390) && (mouse_y > 280 && mouse_y < 305)) {
                play_sample(som_menu, 500, 500, 2000, 0);
                *estado_jogo = JOGO;
                carrega_matriz_jogo(fases_cenario);
                // Contador
                install_int(contador, 1000);
                novo_contador(TEMPO_FASE);
                clear_bitmap(buffer);
                *fase_atual = 0;
                *score = 0;
                atualiza_tela(buffer, 0, fases_cenario, pacman, texturas, ultima_movimentacao, sheet);
                draw_sprite(buffer, score_back, 0, 0);
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                stop_midi();
                play_sample(intro, 500, 500, 1000, 0);
                rest(4000);
                play_midi(fase1, TRUE);
            }

            if ((mouse_x > 195 && mouse_x < 430) && (mouse_y > 320 && mouse_y < 340)) {
                play_sample(som_menu, 500, 500, 2000, 0);
                stop_midi();
                play_midi(menu1, TRUE);
                *estado_jogo = MENU_SELECIONAR_FASE;
            }

            if ((mouse_x > 265 && mouse_x < 350) && (mouse_y > 355 && mouse_y < 375)) {
                play_sample(som_menu, 500, 500, 2000, 0);
                stop_midi();
                play_midi(menu2, TRUE);
                *estado_jogo = MENU_SCORES;
            }


            if ((mouse_x > 240 && mouse_x < 386) && (mouse_y > 390 && mouse_y < 410)) {
                play_sample(som_menu, 500, 500, 2000, 0);
                stop_midi();
                play_midi(menu3, TRUE);
                *estado_jogo = MENU_INSTRUCOES;
            }

            if ((mouse_x > 280 && mouse_x < 340) && (mouse_y > 420 && mouse_y < 445)) {
                play_sample(som_menu, 500, 500, 2000, 0);
                *estado_jogo = SAIR;
            }


        }
    }
    draw_sprite(buffer, menu, 0, 0);
}

void menu_sel_fase(BITMAP *buffer, BITMAP *menu, int *botao_mouse_pressionado, int *estado_jogo, int fases_cenario[QTDE_FASES][2][TILES_X][TILES_Y], int *fase_atual, int *score, SAMPLE *som_menu, MIDI *fase1, MIDI *fase2, MIDI *fase3, BITMAP *pacman, BITMAP *texturas[], int ultima_movimentacao, BITMAP *sheet, BITMAP *score_back, SAMPLE *intro, MIDI *menu_m) {

    if (*botao_mouse_pressionado == FALSE) {
        if (mouse_b & 1) {
            *botao_mouse_pressionado = TRUE;
        }
    } else {
        if (!(mouse_b & 1)) {
            *botao_mouse_pressionado = FALSE;
            if ((mouse_x > 70 && mouse_x < 400) && (mouse_y > 125 && mouse_y < 165)) {
                play_sample(som_menu, 500, 500, 2000, 0);
                *estado_jogo = JOGO;
                carrega_matriz_jogo(fases_cenario);
                // Contador
                install_int(contador, 1000);
                novo_contador(TEMPO_FASE);
                clear_bitmap(buffer);
                *fase_atual = 0;
                *score = 0;
                atualiza_tela(buffer, 0, fases_cenario, pacman, texturas, ultima_movimentacao, sheet);
                draw_sprite(buffer, score_back, 0, 0);
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                stop_midi();
                play_sample(intro, 500, 500, 1000, 0);
                rest(4000);
                play_midi(fase1, TRUE);
            }

            if ((mouse_x > 70 && mouse_x < 440) && (mouse_y > 195 && mouse_y < 240)) {
                play_sample(som_menu, 500, 500, 2000, 0);
                *estado_jogo = JOGO;
                carrega_matriz_jogo(fases_cenario);
                // Contador
                install_int(contador, 1000);
                novo_contador(TEMPO_FASE);
                clear_bitmap(buffer);
                *fase_atual = 1;
                *score = 0;
                atualiza_tela(buffer, 1, fases_cenario, pacman, texturas, ultima_movimentacao, sheet);
                draw_sprite(buffer, score_back, 0, 0);
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                stop_midi();
                play_sample(intro, 500, 500, 1000, 0);
                rest(4000);
                play_midi(fase2, TRUE);
            }

            if ((mouse_x > 70 && mouse_x < 390) && (mouse_y > 270 && mouse_y < 315)) {
                play_sample(som_menu, 500, 500, 2000, 0);
                *estado_jogo = JOGO;
                carrega_matriz_jogo(fases_cenario);
                // Contador
                install_int(contador, 1000);
                novo_contador(TEMPO_FASE);
                clear_bitmap(buffer);
                *fase_atual = 2;
                *score = 0;
                atualiza_tela(buffer, 2, fases_cenario, pacman, texturas, ultima_movimentacao, sheet);
                draw_sprite(buffer, score_back, 0, 0);
                blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                stop_midi();
                play_sample(intro, 500, 500, 1000, 0);
                rest(4000);
                play_midi(fase3, TRUE);
            }

            if ((mouse_x > 20 && mouse_x < 100) && (mouse_y > 440 && mouse_y < 460)) {
                play_sample(som_menu, 500, 500, 2000, 0);
                stop_midi();
                play_midi(menu_m, TRUE);
                *estado_jogo = MENU;
            }
        }

    }
     draw_sprite(buffer, menu, 0, 0);
}

void menu_jogo(BITMAP *buffer, BITMAP *menu, int *botao_mouse_pressionado, int *estado_jogo, SAMPLE *som_menu, MIDI *menu_m) {
    if (*botao_mouse_pressionado == FALSE) {
        if (mouse_b & 1) {
            *botao_mouse_pressionado = TRUE;
        }
    } else {
        if (!(mouse_b & 1)) {
            *botao_mouse_pressionado = FALSE;

            if ((mouse_x > 20 && mouse_x < 100) && (mouse_y > 440 && mouse_y < 460)) {
                play_sample(som_menu, 500, 500, 2000, 0);
                stop_midi();
                play_midi(menu_m, TRUE);
                *estado_jogo = MENU;
            }
        }
    }
    draw_sprite(buffer, menu, 0, 0);
}

void final_jogo(BITMAP *buffer, BITMAP *final, BITMAP *numeros, int score) {
    int num;
    int digitos = 1;
    int digitos_inicial = 1;

    draw_sprite(buffer, final, 0, 0);

    if (score < 0) {
        //colocar sinal de menos
        masked_blit(numeros, buffer, 0, (10)*30, 265, 185, numeros->w, 27);
        score = -score;
    }

    num = score;
    while (num / 10 > 0) {
        num /= 10;
        digitos++;
    }

    digitos_inicial = digitos;

    while (digitos > 0) {
        if (digitos > 1) {
            masked_blit(numeros, buffer, 0, (int) (score / ((digitos - 1)*10))*30, (digitos_inicial - digitos)*20 + 285, 185, numeros->w, 27);
            score -= ((digitos - 1) * 10 * ((int) (score / ((digitos - 1)*10))));
        } else {

            masked_blit(numeros, buffer, 0, score * 30, (digitos_inicial - digitos)*20 + 285, 185, numeros->w, 27);
        }

        digitos--;
    }
}

//apaga o numero da matriz e verifica se a numero é da sequencia da funcao
void come_numero(int fases_cenario[QTDE_FASES][2][TILES_X][TILES_Y], int *fase_atual, int *estado_jogo, int *score, int scores[10], int *sequencia, BITMAP *buffer, BITMAP *pacman, BITMAP *texturas[], int ultima_movimentacao, BITMAP *sheet, BITMAP *score_back, SAMPLE *intro, MIDI *fase2, MIDI *fase3, SAMPLE *come) {
    int y, x;
    int i;
    int mat[5];
    int parar = FALSE;
    fase_funcao(mat, *fase_atual);

    for (y = 0; ((y < TILES_Y) && (parar != TRUE)); y++) {
        for (x = 0; ((x < TILES_X) && (parar != TRUE)); x++) {
            if ((char) fases_cenario[*fase_atual][FUNDO][x][y] == 'P') { // Pacman
                parar = TRUE;
            }
        }
    }

    if (fases_cenario[*fase_atual][FRENTE][x - 1][y - 1] == mat[*sequencia]) {
        fases_cenario[*fase_atual][FRENTE][x - 1][y - 1] = -1;
        *score = calcula_score(mat[*sequencia], *score);
        *sequencia = *sequencia + 1;
        play_sample(come, 500, 500, 1000, 0);
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
            play_sample(come, 500, 500, 1000, 0);
        }
    }

    if (*sequencia == QTDE_SEQUENCIA) {
        if (*fase_atual < QTDE_FASES - 1) {
            *fase_atual = *fase_atual + 1;
            *sequencia = 0;
            novo_contador(TEMPO_FASE);
            clear_bitmap(buffer);
            atualiza_tela(buffer, *fase_atual, fases_cenario, pacman, texturas, ultima_movimentacao, sheet);
            draw_sprite(buffer, score_back, 0, 0);
            blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            stop_midi();
            play_sample(intro, 500, 500, 1000, 0);
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
            //TODO final do jogo
            //allegro_message("Final do jogo");
            *estado_jogo = FINAL;
            le_score(scores);
            salva_score(scores, *score);
        }
    }
}

int anda_pacman(int fases_cenario[QTDE_FASES][2][TILES_X][TILES_Y], int direcao, int fase_atual, int *frame) {
    int x = 0;
    int y = 0;
    int posicao_x = 0;
    int posicao_y = 0;

    for (y = 0; y < TILES_Y; y++) {
        for (x = 0; x < TILES_X; x++) {
            if ((char) fases_cenario[fase_atual][FUNDO][x][y] == 'P') { // Pacman
                posicao_x = x;
                posicao_y = y;
                x = TILES_X;
                y = TILES_Y;
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

/*
A função abaixo é responsável por controlar as entradas do teclado (qualquer
tecla pressionada durante a execução do jogo).
 */
void teclado(int fases_cenario[QTDE_FASES][2][TILES_X][TILES_Y], int *fase_atual, int *full_screen, int *ultima_movimentacao, int *frame, int *estado_jogo, int *score, int scores[10],  int *sequencia, BITMAP *buffer, BITMAP *pacman, BITMAP *texturas[], BITMAP *sheet, BITMAP *score_back, SAMPLE *intro, MIDI *fase2, MIDI *fase3, SAMPLE *come) {
    /*
    Quando declaramos uma variável como sendo static quer dizer que mesmo saindo
    da função ela não vai perder o valor dela. Dessa forma, utilizamos a variável
    abaixo para controlar o tempo de uma tecla a outra.
     */
    static int buffer_teclado = 0;

    //Tudo que estiver dentro o IF abaixo será executado a cada 30 ciclos de CPU
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
                buffer_teclado = BUFFER_TECLADO;
            }

            //Retorna para o menu principal caso a tecla V seja pressionada
            if (key[KEY_V]) {
                *estado_jogo = MENU;
            }

            while (keypressed()) {
                if (key[KEY_UP]) {
                    buffer_teclado = BUFFER_TECLADO;
                    *ultima_movimentacao = DIR_UP;
                    if (anda_pacman(fases_cenario, DIR_UP, *fase_atual, frame)) break;
                }
                if (key[KEY_LEFT]) {
                    buffer_teclado = BUFFER_TECLADO;
                    *ultima_movimentacao = DIR_LEFT;
                    if (anda_pacman(fases_cenario, DIR_LEFT, *fase_atual, frame)) break;
                }
                if (key[KEY_RIGHT]) {
                    buffer_teclado = BUFFER_TECLADO;
                    *ultima_movimentacao = DIR_RIGHT;
                    if (anda_pacman(fases_cenario, DIR_RIGHT, *fase_atual, frame)) break;
                }
                if (key[KEY_DOWN]) {
                    buffer_teclado = BUFFER_TECLADO;
                    *ultima_movimentacao = DIR_DOWN;
                    if (anda_pacman(fases_cenario, DIR_DOWN, *fase_atual, frame)) break;
                }
                break;
            }

            if (key[KEY_ALT]) {
                come_numero(fases_cenario, fase_atual, estado_jogo, score, scores, sequencia, buffer, pacman, texturas, *ultima_movimentacao, sheet, score_back, intro, fase2, fase3, come);
            }
        }

    } else buffer_teclado--;
}

int inicia_allegro() {
    // inicialize o sistema do Allegro
    allegro_init();

    // inicialize o controlador do teclado
    install_keyboard();
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL)) {
        allegro_message(allegro_error);
        return FALSE;
    }

    install_timer();

    install_mouse();

    enable_hardware_cursor();

    // Set normal arrow pointer
    select_mouse_cursor(MOUSE_CURSOR_ARROW);

    //Habilita Acentuação
    set_uformat(U_UTF8);

    // definição da profundidade de cor
    set_color_depth(desktop_color_depth());

    srand((unsigned) time(NULL));


    // inicialize o modo gráfico
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, LARGURA_TELA, ALTURA_TELA, 0, 0)) {
        allegro_message(allegro_error);
        return FALSE;
    }

    set_window_title("Namcap");

    return TRUE;
}

void close_button_handler(void) //Permite a utilização do botão "Fechar" para fechar o aplicativo
{
    close_button_pressed = TRUE;
}

END_OF_FUNCTION(close_button_handler)

void inicia_jogo() {

    /*
         Variáveis Mapa tridimensional sendo o primeiro ecrãn a Fase e os
        outros dois correspondem a quantidade de Tiles na horizontal e vertical.
     */


    int fases_cenario[QTDE_FASES][2][TILES_X][TILES_Y];
    int fase_atual = 0; // Guarda o index da fase atual.
    int full_screen = FALSE;
    int ultima_movimentacao = DIR_RIGHT;
    int frame;
    int estado_jogo = MENU;
    int score = 0;
    int botao_mouse_pressionado = FALSE;
    int scores[10];
    int sequencia = 0;

    LOCK_FUNCTION(close_button_handler);
    set_close_button_callback(close_button_handler);


    //Variável do tipo BITMAP responsável por guardar as texturas
    BITMAP *pacman, *pacman2, *numeros, *score_bmp, *score_back, *final, *menu, *menu_instrucoes, *menu_selecionar_fase, *jogo_pausado, *scores_bmp;
    BITMAP * texturas[3];

    BITMAP *buffer = NULL;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    //carrega a imagem do pacman
    pacman = load_bitmap("imagens/pac-man.bmp", NULL);
    pacman2 = load_bitmap("imagens/pac-man2.bmp", NULL);

    // Define o índice 0 da textura como sendo parede
    texturas[0] = load_bitmap("tiles/parede.bmp", NULL);

    // Define o índice 1 da textura como sendo grama
    texturas[1] = load_bitmap("tiles/grama.bmp", NULL);

    // Define o índice 2 da textura como sendo chão
    texturas[2] = load_bitmap("tiles/chao.bmp", NULL);

    // Números
    numeros = load_bitmap("imagens/numeros.bmp", NULL);

    //Sprite dos números usados na pontuação
    score_bmp = load_bitmap("imagens/score.bmp", NULL);
    score_back = load_bitmap("imagens/score-back.bmp", NULL);

    final = load_bitmap("imagens/final.bmp", NULL);
    menu = load_bitmap("imagens/menu.bmp", NULL);
    menu_instrucoes = load_bitmap("imagens/instrucoes.bmp", NULL);
    menu_selecionar_fase = load_bitmap("imagens/selecionar-fase.bmp", NULL);
    jogo_pausado = load_bitmap("imagens/jogo-pausado.bmp", NULL);
    scores_bmp = load_bitmap("imagens/scores.bmp", NULL);

    //Sons
    SAMPLE *come = load_sample("sons/come.wav"), *intro = load_sample("sons/intro.wav");
    MIDI *menu_m, *menu1, *menu2, *menu3, *fase1, *fase2, *fase3;
    menu_m = load_midi("sons/menu principal.mid");
    menu1 = load_midi("sons/extra1.mid");
    menu2 = load_midi("sons/extra2.mid");
    menu3 = load_midi("sons/extra3.mid");
    fase1 = load_midi("sons/fase1.mid");
    fase2 = load_midi("sons/fase2.mid");
    fase3 = load_midi("sons/fase3.mid");

    show_mouse(screen);

    play_midi(menu_m, TRUE);

    while (!key[KEY_ESC] && !close_button_pressed) {
        switch (estado_jogo) {
            case MENU:
                clear_bitmap(buffer);
                menu_inicial_jogo(buffer, menu, &botao_mouse_pressionado, &estado_jogo, fases_cenario, &fase_atual, &score, come, menu1, menu2, menu3, pacman, texturas, ultima_movimentacao, numeros, score_back, intro, fase1);
                teclado(fases_cenario, &fase_atual, &full_screen, &ultima_movimentacao, &frame, &estado_jogo, &score, scores,&sequencia, buffer, pacman, texturas, numeros, score_back, intro, fase2, fase3, come);
                break;
            case MENU_SELECIONAR_FASE:
                clear_bitmap(buffer);
                menu_sel_fase(buffer, menu_selecionar_fase, &botao_mouse_pressionado, &estado_jogo, fases_cenario, &fase_atual, &score, come, fase1, fase2, fase3, pacman, texturas, ultima_movimentacao, numeros, score_back, intro, menu_m);
                //menu_jogo(buffer, menu_selecionar_fase, &botao_mouse_pressionado, &estado_jogo, come, menu_m);
                break;
            case MENU_INSTRUCOES:
                clear_bitmap(buffer);
                menu_jogo(buffer, menu_instrucoes, &botao_mouse_pressionado, &estado_jogo, come, menu_m);
                break;
            case MENU_SCORES:
                clear_bitmap(buffer);
                menu_jogo(buffer, scores_bmp, &botao_mouse_pressionado, &estado_jogo, come, menu_m);
                le_score(scores);
                mostrar_scores(buffer, scores);
                break;
            case JOGO:
                clear_bitmap(buffer);
                teclado(fases_cenario, &fase_atual, &full_screen, &ultima_movimentacao, &frame, &estado_jogo, &score, scores,&sequencia, buffer, pacman, texturas, numeros, score_back, intro, fase2, fase3, come);
                atualiza_tela(buffer, fase_atual, fases_cenario, frame == 0 ? pacman : pacman2, texturas, ultima_movimentacao, numeros);
                draw_sprite(buffer, score_back, 0, 0);

                update_score(buffer, numeros, score_bmp, score);

                if (update_timer(buffer, numeros) == FALSE) {
                    if (fase_atual >= QTDE_FASES - 1) {
                        estado_jogo = FINAL;
                        le_score(scores);
                        salva_score(scores, score);
                    } else {
                        fase_atual++;
                        novo_contador(TEMPO_FASE);
                        clear_bitmap(buffer);
                        atualiza_tela(buffer, fase_atual, fases_cenario, frame == 0 ? pacman : pacman2, texturas, ultima_movimentacao, numeros);
                        draw_sprite(buffer, score_back, 0, 0);
                        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                        stop_midi();
                        play_sample(intro, 500, 500, 1000, 0);
                        rest(4000);
                        switch(fase_atual) {
                            case 1: {
                                play_midi(fase2, TRUE);
                                break;
                            }
                            case 2: {
                                play_midi(fase3, TRUE);
                                break;
                            }
                        }
                    }
                }

                textprintf_ex(buffer, font, 10, 10, makecol(255, 255, 255),
                        -1, "FASE: %d", fase_atual + 1);

                //salva_score(scores, score);
                break;
            case FINAL:
                clear_bitmap(buffer);
                menu_jogo(buffer, menu, &botao_mouse_pressionado, &estado_jogo, come, menu_m);
                final_jogo(buffer, final, numeros, score);
                fase_atual = 0;
                sequencia = 0;
                break;
            case SAIR:
                close_button_pressed = TRUE;
                break;
            case PAUSADO:
                clear_bitmap(buffer);
                clear_bitmap(buffer);
                teclado(fases_cenario, &fase_atual, &full_screen, &ultima_movimentacao, &frame, &estado_jogo, &score, scores,&sequencia, buffer, pacman, texturas, numeros, score_back, intro, fase2, fase3, come);
                atualiza_tela(buffer, fase_atual, fases_cenario, frame == 0 ? pacman : pacman2, texturas, ultima_movimentacao, numeros);
                draw_sprite(buffer, score_back, 0, 0);

                update_score(buffer, numeros, score_bmp, score);

                textprintf_ex(buffer, font, 10, 10, makecol(255, 255, 255),
                        -1, "FASE: %d", fase_atual + 1);
                draw_sprite(buffer, jogo_pausado, 0, 0);
                break;
        }

        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        //show_mouse(screen);
    }

    //Desaloca as imagens da memória
    destroy_bitmap(buffer);
    destroy_bitmap(texturas[0]);
    destroy_bitmap(texturas[1]);
    destroy_bitmap(texturas[2]);
    destroy_bitmap(pacman);
    destroy_bitmap(pacman2);
    destroy_bitmap(numeros);
    destroy_bitmap(score_bmp);
    destroy_bitmap(score_back);
    destroy_bitmap(final);
    destroy_bitmap(menu);
    destroy_bitmap(menu_instrucoes);
    destroy_bitmap(menu_selecionar_fase);
    destroy_bitmap(jogo_pausado);
    destroy_midi(menu_m);
    destroy_midi(menu1);
    destroy_midi(menu2);
    destroy_midi(menu3);
    destroy_midi(fase1);
    destroy_midi(fase2);
    destroy_midi(fase3);
    destroy_sample(come);
    destroy_sample(intro);
    //destroy_bitmap(mouse_sprite);
}

int main() {

    if (!inicia_allegro()) {
        return EXIT_FAILURE;
    }
    inicia_jogo();
    allegro_exit();

    return EXIT_SUCCESS;
}
END_OF_MAIN();

