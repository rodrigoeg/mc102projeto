#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>
#include "carrega_fases.h"

int iFaseAtual = 0; // Guarda o index da fase atual.

void anda_pacman(int Mapa[QTDE_FASES][2][TILES_X][TILES_Y], int direcao) {
    int x = 0;
    int y = 0;
    int posicao_x, posicao_y;

    for (y = 0; y < TILES_Y; y++) {
        for (x = 0; x < TILES_X; x++) {
            if ((char) Mapa[iFaseAtual][FUNDO][x][y] == 'P') { // Pacman
                posicao_x = x;
                posicao_y = y;
                x = TILES_X;
                y = TILES_Y;
            }
        }
    }

    switch (direcao) {
        case DIR_UP:
            if (Mapa[iFaseAtual][FUNDO][posicao_x][posicao_y - 1] != '#') {
                Mapa[iFaseAtual][FUNDO][posicao_x][posicao_y] = Mapa[iFaseAtual][FUNDO][posicao_x][posicao_y - 1];
                Mapa[iFaseAtual][FUNDO][posicao_x][posicao_y - 1] = 'P';
            }
            break;
        case DIR_DOWN:
            if (Mapa[iFaseAtual][FUNDO][posicao_x][posicao_y + 1] != '#') {
                Mapa[iFaseAtual][FUNDO][posicao_x][posicao_y] = Mapa[iFaseAtual][FUNDO][posicao_x][posicao_y + 1];
                Mapa[iFaseAtual][FUNDO][posicao_x][posicao_y + 1] = 'P';
            }
            break;
        case DIR_LEFT:
            if (Mapa[iFaseAtual][FUNDO][posicao_x - 1][posicao_y] != '#') {
                Mapa[iFaseAtual][FUNDO][posicao_x][posicao_y] = Mapa[iFaseAtual][FUNDO][posicao_x - 1][posicao_y];
                Mapa[iFaseAtual][FUNDO][posicao_x - 1][posicao_y] = 'P';
            }
            break;
        case DIR_RIGHT:
            if (Mapa[iFaseAtual][FUNDO][posicao_x + 1][posicao_y] != '#') {
                Mapa[iFaseAtual][FUNDO][posicao_x][posicao_y] = Mapa[iFaseAtual][FUNDO][posicao_x + 1][posicao_y];
                Mapa[iFaseAtual][FUNDO][posicao_x + 1][posicao_y] = 'P';
            }
            break;
    }
}

/*
A função abaixo é responsável por controlar as entradas do teclado, qualquer
tecla pressionada durante a execução do jogo.
 */
void Teclado(int Mapa[QTDE_FASES][2][TILES_X][TILES_Y]) {
    /*
    Quando declaramos uma variável como sendo static quer dizer que mesmo saindo
    da função ela não vai perder o valor dela. Dessa forma, utilizamos a variável
    abaixo para controlar o tempo de uma tecla a outra.
     */
    static int Buffer_Teclado = 0;

    //Tudo que estiver dentro o IF abaixo será executado a cada 30 ciclos de CPU
    if (Buffer_Teclado == 0) {
        // Muda o Cenário caso aperte a tecla espaço
        if (key[KEY_SPACE]) {
            if (iFaseAtual < (QTDE_FASES - 1))
                iFaseAtual++;
            else
                iFaseAtual = 0;

            Buffer_Teclado = 30;
        }

        if (key[KEY_UP]) {
            Buffer_Teclado = 15;
            anda_pacman(Mapa, DIR_UP);
            printf("up \n");
        }
        if (key[KEY_DOWN]) {
            Buffer_Teclado = 15;
            anda_pacman(Mapa, DIR_DOWN);
            printf("down \n");
        }
        if (key[KEY_LEFT]) {
            Buffer_Teclado = 15;
            anda_pacman(Mapa, DIR_LEFT);
            printf("left \n");
        }
        if (key[KEY_RIGHT]) {
            Buffer_Teclado = 15;
            anda_pacman(Mapa, DIR_RIGHT);
            printf("right \n");
        }

    } else Buffer_Teclado--;
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
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0)) {
        allegro_message(allegro_error);
        return FALSE;
    }

    set_window_title("Pacman");

    return TRUE;
}

int main() {

    /*
         Variáveis Mapa tridimensional sendo o primeiro ecrãn a Fase e os
        outros dois correspondem a quantidade de Tiles na horizontal e vertical.
     */

    if (!inicia_allegro()) {
        return EXIT_FAILURE;
    }

    int Mapa[QTDE_FASES][2][TILES_X][TILES_Y];

    BITMAP *Buffer = NULL;
    Buffer = create_bitmap(SCREEN_W, SCREEN_H);

    CarregaMatriz(Mapa);
    CarregaTexturas();

    while (!key[KEY_ESC]) {
        clear_bitmap(Buffer);
        DesenhaCenario(Buffer, iFaseAtual, Mapa);
        Teclado(Mapa);

        textprintf_centre_ex(Buffer, font, SCREEN_W / 2, (SCREEN_H / 2) - 10, makecol(255, 255, 0),
                -1, "FASE: %d", iFaseAtual + 1);
        textprintf_centre_ex(Buffer, font, SCREEN_W / 2, SCREEN_H / 2, makecol(255, 255, 0), -1,
                "Pressione espaço para mudar de fase.");

        blit(Buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        vsync();
    }

    //Desaloca as imagens da memória
    destroy_bitmap(Buffer);
    destroy_bitmap(Textura[0]);
    destroy_bitmap(Textura[1]);
    destroy_bitmap(Textura[2]);
    allegro_exit();

    return EXIT_SUCCESS;
}
END_OF_MAIN();
