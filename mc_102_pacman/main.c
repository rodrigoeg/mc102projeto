#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>
#include "carrega_fases.h"

#define LARGURA_TELA 640
#define ALTURA_TELA 480

int anda_pacman(int fases_cenario[QTDE_FASES][2][TILES_X][TILES_Y], int direcao, int fase_atual, int *frame) {
    int x = 0;
    int y = 0;
    int posicao_x, posicao_y;


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
                *frame = (*frame+1)%2;
                return 1;
            }
            break;
        case DIR_DOWN:
            if (fases_cenario[fase_atual][FUNDO][posicao_x][posicao_y + 1] != '#') {
                fases_cenario[fase_atual][FUNDO][posicao_x][posicao_y] = fases_cenario[fase_atual][FUNDO][posicao_x][posicao_y + 1];
                fases_cenario[fase_atual][FUNDO][posicao_x][posicao_y + 1] = 'P';
                *frame = (*frame+1)%2;
                return 1;
            }
            break;
        case DIR_LEFT:
            if (fases_cenario[fase_atual][FUNDO][posicao_x - 1][posicao_y] != '#') {
                fases_cenario[fase_atual][FUNDO][posicao_x][posicao_y] = fases_cenario[fase_atual][FUNDO][posicao_x - 1][posicao_y];
                fases_cenario[fase_atual][FUNDO][posicao_x - 1][posicao_y] = 'P';
                *frame = (*frame+1)%2;
                return 1;
            }
            break;
        case DIR_RIGHT:
            if (fases_cenario[fase_atual][FUNDO][posicao_x + 1][posicao_y] != '#') {
                fases_cenario[fase_atual][FUNDO][posicao_x][posicao_y] = fases_cenario[fase_atual][FUNDO][posicao_x + 1][posicao_y];
                fases_cenario[fase_atual][FUNDO][posicao_x + 1][posicao_y] = 'P';
                *frame = (*frame+1)%2;
                return 1;
            }
            break;
    }
    return 0;
}

/*
A função abaixo é responsável por controlar as entradas do teclado, qualquer
tecla pressionada durante a execução do jogo.
 */
void teclado(int fases_cenario[QTDE_FASES][2][TILES_X][TILES_Y], int *fase_atual, int *full_screen, int *ultima_movimentacao, int *frame) {
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
            } else {
                set_full_screen();
            }
            *full_screen = (*full_screen == TRUE) ? FALSE : TRUE;
        }

        // Muda o Cenário caso aperte a tecla espaço
        if (key[KEY_SPACE]) {
            if (*fase_atual < (QTDE_FASES - 1))
                *fase_atual = *fase_atual + 1;
            else
                *fase_atual = 0;

            buffer_teclado = 15;
        }
        while (keypressed()) {
            if (key[KEY_UP]) {
                buffer_teclado = 15;
                *ultima_movimentacao = DIR_UP;
                if (anda_pacman(fases_cenario, DIR_UP, *fase_atual, frame)) break;
            }
            if (key[KEY_LEFT]) {
                buffer_teclado = 15;
                *ultima_movimentacao = DIR_LEFT;
                if (anda_pacman(fases_cenario, DIR_LEFT, *fase_atual, frame)) break;
            }
            if (key[KEY_RIGHT]) {
                buffer_teclado = 15;
                *ultima_movimentacao = DIR_RIGHT;
                if (anda_pacman(fases_cenario, DIR_RIGHT, *fase_atual, frame)) break;
            }
            if (key[KEY_DOWN]) {
                buffer_teclado = 15;
                *ultima_movimentacao = DIR_DOWN;
                if (anda_pacman(fases_cenario, DIR_DOWN, *fase_atual, frame)) break;
            }
            break;
        }
    } else buffer_teclado--;
}

int inicia_allegro() {

    // inicialize o sistema do Allegro
    allegro_init();

    // inicialize o controlador do teclado
    install_keyboard();
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);

    install_timer();

    //Habilita Acentuação
    set_uformat(U_UTF8);

    // definição da profundidade de cor
    // http://pt.wikipedia.org/wiki/Profundidade_de_cor
    set_color_depth(desktop_color_depth());

    srand((unsigned) time(NULL));


    // inicialize o modo gráfico com uma resolução de tela
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, LARGURA_TELA, ALTURA_TELA, 0, 0)) {
        allegro_message(allegro_error);
        return FALSE;
    }

    set_window_title("Pacman");

    return TRUE;
}

int set_full_screen() {
    // inicialize o modo gráfico com uma resolução de tela
    if (set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, LARGURA_TELA, ALTURA_TELA, 0, 0)) {
        allegro_message(allegro_error);
        return FALSE;
    }
}

int set_windowed() {
    // inicialize o modo gráfico com uma resolução de tela
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, LARGURA_TELA, ALTURA_TELA, 0, 0)) {
        allegro_message(allegro_error);
        return FALSE;
    }
}

int main() {

    /*
         Variáveis Mapa tridimensional sendo o primeiro ecrãn a Fase e os
        outros dois correspondem a quantidade de Tiles na horizontal e vertical.
     */

    if (!inicia_allegro()) {
        return EXIT_FAILURE;
    }

    int fases_cenario[QTDE_FASES][2][TILES_X][TILES_Y];
    int fase_atual = 0; // Guarda o index da fase atual.
    int full_screen = FALSE;
    int ultima_movimentacao = DIR_RIGHT;
    int frame;

    //Variável do tipo BITMAP responsável por guardar as texturas
    BITMAP *pacman, *pacman2, *numeros;
    BITMAP * texturas[3];

    BITMAP *buffer = NULL;
    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    carrega_matriz_jogo(fases_cenario);
    //carrega_texturas(pacman, texturas);


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

    // Contador
    install_int(contador, 1000);
    novo_contador(120);

    while (!key[KEY_ESC]) {
        clear_bitmap(buffer);
        atualiza_tela(buffer, fase_atual, fases_cenario, frame == 0 ? pacman : pacman2, texturas, ultima_movimentacao, numeros);
        teclado(fases_cenario, &fase_atual, &full_screen, &ultima_movimentacao, &frame);
        update_timer(buffer, numeros);

        textprintf_centre_ex(buffer, font, SCREEN_W / 2, (SCREEN_H / 2) - 10, makecol(255, 255, 0),
                -1, "FASE: %d", fase_atual + 1);
        textprintf_centre_ex(buffer, font, SCREEN_W / 2, SCREEN_H / 2, makecol(255, 255, 0), -1,
                "Pressione espaço para mudar de fase.");

        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        vsync();
    }

    //Desaloca as imagens da memória
    destroy_bitmap(buffer);
    destroy_bitmap(texturas[0]);
    destroy_bitmap(texturas[1]);
    destroy_bitmap(texturas[2]);
    allegro_exit();

    return EXIT_SUCCESS;
}
END_OF_MAIN();
