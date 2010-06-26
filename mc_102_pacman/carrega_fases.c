#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "carrega_fases.h"

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
void carrega_matriz_jogo(int fases_cenario[QTDE_FASES][2][TILES_X][TILES_Y]) {
    //A variável abaixo guarda o local onde estão as fases em arquivo texto.
    char *arq_fases[] = {"fases/fase1.txt", "fases/fase2.txt", "fases/fase3.txt"};
    int x = 0;
    int y = 0;
    int fases = 0;


    char char_count_linha[ TILES_X ]; // Qtde de caracteres por linha


    //O FOR abaixo é para preencher todas as fases.
    for (fases = 0; fases < QTDE_FASES; fases++) {
        int mat[5];
        int mat_erradas[5];
        fase_funcao(mat, fases);
        fase_numeros_errados(mat_erradas, fases);
        char tile;

        // Abre o arquivo de fases para leitura com base no iFase e o Array de fases
        FILE *fp = fopen(arq_fases[fases], "r");

        //Preenche a matriz na horizontal e vertical
        for (y = 0; y < TILES_Y; y++) {
            /*
            Atribui na variável sLinha a linha atual do arquivo texto.
            Toda vez que essa rotina for chamada ele pula para a proxima linha e
            joga o valor para sLinha, até finalizar as 15 linhas.
             */

            fgets(char_count_linha, TAM_TILES_X, fp);

            /*
               Já com o sLinha preenchido, agora, o FOR abaixo varre todas as
               posições dessa linha e acrescenta na linha da matriz. Após terminar
               de varrer o sLinha sai do for e espera próxima linha, se houver.
             */


            for (x = 0; x < TILES_X; x++) {
                //printf("%c ", (int)char_count_linha[x]);
                fases_cenario[fases][FRENTE][x][y] = -1;

                fases_cenario[fases][FUNDO][x][y] = char_count_linha[x];


                if ((char) fases_cenario[fases][FUNDO][x + 1][y + 1] == '.') {
                    tile = (char) fases_cenario[fases][FUNDO][x + 1][y + 1];
                } else {
                    if ((char) fases_cenario[fases][FUNDO][x][y + 1] == '.') {
                        tile = (char) fases_cenario[fases][FUNDO][x][y + 1];
                    } else {
                        if ((char) fases_cenario[fases][FUNDO][x + 1][y] == '.') {
                            tile = (char) fases_cenario[fases][FUNDO][x + 1][y];
                        }
                    }
                }

                if ((char) fases_cenario[fases][FUNDO][x + 1][y + 1] == '-') {
                    tile = (char) fases_cenario[fases][FUNDO][x + 1][y + 1];
                } else {
                    if ((char) fases_cenario[fases][FUNDO][x][y + 1] == '-') {
                        tile = (char) fases_cenario[fases][FUNDO][x][y + 1];
                    } else {
                        if ((char) fases_cenario[fases][FUNDO][x + 1][y] == '-') {
                            tile = (char) fases_cenario[fases][FUNDO][x + 1][y];
                        }
                    }
                }

                switch(char_count_linha[x]) {
                    case '0':
                        fases_cenario[fases][FRENTE][x][y] = mat[0];
                        fases_cenario[fases][FUNDO][x][y] = tile;
                        break;
                    case '1':
                        fases_cenario[fases][FRENTE][x][y] = mat[1];
                        fases_cenario[fases][FUNDO][x][y] = tile;
                        break;
                    case '2':
                        fases_cenario[fases][FRENTE][x][y] = mat[2];
                        fases_cenario[fases][FUNDO][x][y] = tile;
                        break;
                    case '3':
                        fases_cenario[fases][FRENTE][x][y] = mat[3];
                        fases_cenario[fases][FUNDO][x][y] = tile;
                        break;
                    case '4':
                        fases_cenario[fases][FRENTE][x][y] = mat[4];
                        fases_cenario[fases][FUNDO][x][y] = tile;
                        break;
                    case 'a':
                        fases_cenario[fases][FRENTE][x][y] = mat_erradas[0];
                        fases_cenario[fases][FUNDO][x][y] = tile;
                        break;
                    case 'b':
                        fases_cenario[fases][FRENTE][x][y] = mat_erradas[1];
                        fases_cenario[fases][FUNDO][x][y] = tile;
                        break;
                    case 'c':
                        fases_cenario[fases][FRENTE][x][y] = mat_erradas[2];
                        fases_cenario[fases][FUNDO][x][y] = tile;
                        break;
                    case 'd':
                        fases_cenario[fases][FRENTE][x][y] = mat_erradas[3];
                        fases_cenario[fases][FUNDO][x][y] = tile;
                        break;
                    case 'e':
                        fases_cenario[fases][FRENTE][x][y] = mat_erradas[4];
                        fases_cenario[fases][FUNDO][x][y] = tile;
                        break;
                }

            }
            printf("\n");
        }

        fclose(fp);
    }
}

/*
A função abaixo é responsável por declarar e definir as imagens que iremos
utilizar no Array Textura. Essa imagens devem estar dentro da pasta imagens no
nosso projeto,caso contrário o programa irá apresentar a mensagem de erro fatal.
 */
void carrega_texturas(BITMAP *pacman, BITMAP *texturas[]) {

    //carrega a imagem do pacman
    pacman = load_bitmap("imagens/pac-man.bmp", NULL);

    // Define o índice 0 da textura como sendo parede
    texturas[0] = load_bitmap("tiles/parede.bmp", NULL);

    // Define o índice 1 da textura como sendo grama
    texturas[1] = load_bitmap("tiles/grama.bmp", NULL);

    // Define o índice 2 da textura como sendo chão
    texturas[2] = load_bitmap("tiles/chao.bmp", NULL);

}

/*
Essa função é responsável por desenhar as texturas do cenário. O cenário a ser
carregado é informado através de um argumento. Essa função usa como base a matriz
carregada anteriormente para desenhar as texturas.
 */
void atualiza_tela(BITMAP *buffer, int fase_atual, int fases_cenario[QTDE_FASES][2][TILES_X][TILES_Y], BITMAP *pacman, BITMAP *texturas[], int ultima_movimentacao, BITMAP *sheet) {
    int x = 0;
    int y = 0;
    char tile = ' ';

    for (y = 0; y < TILES_Y; y++) {
        for (x = 0; x < TILES_X; x++) {
            if ((char) fases_cenario[fase_atual][FUNDO][x][y] == '#') { // Parede
                draw_sprite(buffer, texturas[0], x * TAM_TILES_X, y * TAM_TILES_Y);
            } else {
                if ((char) fases_cenario[fase_atual][FUNDO][x][y] == '-') { // Grama
                    tile = '-';
                    draw_sprite(buffer, texturas[1], x * TAM_TILES_X, y * TAM_TILES_Y);
                } else {
                    if ((char) fases_cenario[fase_atual][FUNDO][x][y] == '.') { // Chão
                        tile = '.';
                        draw_sprite(buffer, texturas[2], x * TAM_TILES_X, y * TAM_TILES_Y);
                    } else {
                        if ((char) fases_cenario[fase_atual][FUNDO][x][y] == 'P') { // Pacman
                            if (tile == ' ') {
                                if ((char) fases_cenario[fase_atual][FUNDO][x + 1][y + 1] != '#') {
                                    tile = (char) fases_cenario[fase_atual][FUNDO][x + 1][y + 1];
                                } else {
                                    if ((char) fases_cenario[fase_atual][FUNDO][x][y + 1] != '#') {
                                        tile = (char) fases_cenario[fase_atual][FUNDO][x][y + 1];
                                    } else {
                                        if ((char) fases_cenario[fase_atual][FUNDO][x + 1][y] != '#') {
                                            tile = (char) fases_cenario[fase_atual][FUNDO][x + 1][y];
                                        }
                                    }
                                }
                            }
                            if (tile == '-') { // Grama
                                draw_sprite(buffer, texturas[1], x * TAM_TILES_X, y * TAM_TILES_Y);
                            } else {
                                if (tile == '.') { // Chão
                                    draw_sprite(buffer, texturas[2], x * TAM_TILES_X, y * TAM_TILES_Y);
                                }
                            }

                            switch (ultima_movimentacao) {
                                case DIR_UP:
                                    rotate_sprite(buffer, pacman, x * TAM_TILES_X, y * TAM_TILES_Y, itofix(-64));
                                    break;
                                case DIR_DOWN:
                                    rotate_sprite(buffer, pacman, x * TAM_TILES_X, y * TAM_TILES_Y, itofix(64));
                                    break;
                                case DIR_LEFT:
                                    draw_sprite_h_flip(buffer, pacman, x * TAM_TILES_X, y * TAM_TILES_Y);
                                    break;
                                case DIR_RIGHT:
                                    draw_sprite(buffer, pacman, x * TAM_TILES_X, y * TAM_TILES_Y);
                                    break;
                            }
                        } else {
                            if (tile == '-') { // Grama
                                draw_sprite(buffer, texturas[1], x * TAM_TILES_X, y * TAM_TILES_Y);
                            } else {
                                if (tile == '.') { // Chão
                                    draw_sprite(buffer, texturas[2], x * TAM_TILES_X, y * TAM_TILES_Y);
                                }
                            }
                        }
                    }
                }
            }
            if ((fases_cenario[fase_atual][FRENTE][x][y] != -1) && (fases_cenario[fase_atual][FUNDO][x][y] != 'P')) {
                 masked_blit(sheet, buffer, 0, (fases_cenario[fase_atual][FRENTE][x][y])*30, x * TAM_TILES_X, y * TAM_TILES_Y, sheet->w, 30);
            }
        }
    }
}

void fase_funcao(int mat[], int fase) {
    int i;
    switch (fase){
        case 0:
            //2x
            for(i=0;i<5;i++) {
                mat[i] = 2*i;
            }
            break;
        case 1:
            //2x + 1
            for(i=0;i<5;i++) {
                mat[i] = 2*i +1;
            }
            break;
        case 2:
            //3x + 7
            for(i=0;i<5;i++) {
                mat[i] = 3*i + 7;
            }

            break;
    }

    return mat;
}

void fase_numeros_errados(int mat[], int fase) {
    int i;
    switch (fase){
        case 0:
            //2x + 1
            for(i=0;i<5;i++) {
                mat[i] = 2*i + 1;
            }
            break;
        case 1:
            //2x
            for(i=0;i<5;i++) {
                mat[i] = 2*i;
            }
            break;
        case 2:
            //3x + 3
            for(i=0;i<5;i++) {
                mat[i] = 3*i + 3;
            }

            break;
    }

    return mat;
}
