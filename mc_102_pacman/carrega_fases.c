#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "carrega_fases.h"

//A variável abaixo guarda o local onde estão as fases em arquivo texto.
const char *ArqFases[] = {"fases/fase1.txt", "fases/fase2.txt", "fases/fase3.txt"};

/*
 struct dirent **namelist;
int n;

n = scandir(".", &namelist, 0, alphasort);
if (n < 0)
perror("scandir");
else {
while(n--) {
printf("%s\n", namelist[n]->d_name);
free(namelist[n]);
}
free(namelist);
}
 */

/*
Com base nas variáveis acima temos o tamanho da tela 640x480, conforme abaixo:
   (iTamTilesX * iTilesX) = SCREEN_W;
   (iTamTilesY * iTilesY) = SCREEN_H;
   (32 * 20) = 640;
   (32 * 15) = 480;
 */

/*
A função abaixo é a mais importante com relação ao arquivo de fases. Ela serve
para carregar os valores que estão dentro do arquivo de fase para a matriz.
Com base na matriz iremos montar o cenário de cada fase e posicionar suas
respectivas texturas ou objetos, dependendo de como você modificar o código.
 */
void CarregaMatriz(int Mapa[QTDE_FASES][2][TILES_X][TILES_Y]) {
    int x = 0;
    int y = 0;
    int iFase = 0;

    char sLinha[ TILES_X ]; // Qtde de caracteres por linha

    //O FOR abaixo é para preencher todas as fases.
    for (iFase = 0; iFase < QTDE_FASES; iFase++) {
        // Abre o arquivo de fases para leitura com base no iFase e o Array de fases
        FILE *fp = fopen(ArqFases[iFase], "r");


        //Preenche a matriz na horizontal e vertical
        for (y = 0; y < TILES_Y; y++) {
            /*
            Atribui na variável sLinha a linha atual do arquivo texto.
            Toda vez que essa rotina for chamada ele pula para a proxima linha e
            joga o valor para sLinha, até finalizar as 15 linhas.
             */

            fgets(sLinha, TAM_TILES_X, fp);

            /*
               Já com o sLinha preenchido, agora, o FOR abaixo varre todas as
               posições dessa linha e acrescenta na linha da matriz. Após terminar
               de varrer o sLinha sai do for e espera próxima linha, se houver.
             */
            for (x = 0; x < TILES_X; x++) {
                Mapa[iFase][FUNDO][x][y] = sLinha[x];
            }
        }

        fclose(fp);
    }
}

/*
A função abaixo é responsável por declarar e definir as imagens que iremos
utilizar no Array Textura. Essa imagens devem estar dentro da pasta imagens no
nosso projeto,caso contrário o programa irá apresentar a mensagem de erro fatal.
 */
void CarregaTexturas() {

    Pacman = load_bitmap("imagens/pac-man.bmp", NULL);

    // Define o índice 0 da textura como sendo parede
    Textura[0] = load_bitmap("tiles/parede.bmp", NULL);

    // Define o índice 1 da textura como sendo grama
    Textura[1] = load_bitmap("tiles/grama.bmp", NULL);

    // Define o índice 2 da textura como sendo chão
    Textura[2] = load_bitmap("tiles/chao.bmp", NULL);

}

/*
Essa função é responsável por desenhar as texturas do cenário. O cenário a ser
carregado é informado através de um argumento. Essa função usa como base a matriz
carregada anteriormente para desenhar as texturas.
 */
void DesenhaCenario(BITMAP *Cenario, int iFase, int Mapa[QTDE_FASES][2][TILES_X][TILES_Y]) {
    int x = 0;
    int y = 0;
    char tile;

    for (y = 0; y < TILES_Y; y++) {
        for (x = 0; x < TILES_X; x++) {
            if ((char) Mapa[iFase][FUNDO][x][y] == '#') { // Parede
                draw_sprite(Cenario, Textura[0], x * TAM_TILES_X, y * TAM_TILES_Y);
            } else {
                if ((char) Mapa[iFase][FUNDO][x][y] == '-') { // Grama
                    tile = '-';
                    draw_sprite(Cenario, Textura[1], x * TAM_TILES_X, y * TAM_TILES_Y);
                } else {
                    if ((char) Mapa[iFase][FUNDO][x][y] == '.') { // Chão
                        tile = '.';
                        draw_sprite(Cenario, Textura[2], x * TAM_TILES_X, y * TAM_TILES_Y);
                    } else {
                        if ((char) Mapa[iFase][FUNDO][x][y] == 'P') { // Pacman
                            if (tile == '-') { // Grama
                                draw_sprite(Cenario, Textura[1], x * TAM_TILES_X, y * TAM_TILES_Y);
                            } else {
                                if (tile == '.') { // Chão
                                    draw_sprite(Cenario, Textura[2], x * TAM_TILES_X, y * TAM_TILES_Y);
                                }
                            }
                            draw_sprite(Cenario, Pacman, x * TAM_TILES_X, y * TAM_TILES_Y);
                        }
                    }
                }
            }
        }
    }
}