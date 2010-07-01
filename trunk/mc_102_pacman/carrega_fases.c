#include "carrega_jogo.h"

//A função abaixo serve para carregar os valores que estão dentro do arquivo de fase para a matriz.
void carrega_matriz_jogo(int fases_cenario[QTDE_FASES][2][TILES_X][TILES_Y]) {
    //A variável abaixo guarda o local onde estão as fases em arquivo texto.
    char *arq_fases[] = {"fases/fase1.txt", "fases/fase2.txt", "fases/fase3.txt", "fases/fase4.txt"};
    int x = 0;
    int y = 0;
    int fases = 0;


    char char_count_linha[ TILES_X ]; // Qtde de caracteres por linha


    //O for abaixo é para preencher todas as fases.
    for (fases = 0; fases < QTDE_FASES; fases++) {
        int mat[5];
        int mat_erradas[5];
        fase_funcao(mat, fases);
        fase_numeros_errados(mat_erradas, fases);
        char tile = ' ';

        // Abre o arquivo de fases para leitura com base no iFase e o vetor de fases
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
               Já com o char_count_linha preenchido, agora, o FOR abaixo varre todas as
               posições dessa linha e acrescenta na linha da matriz. Após terminar
               de varrer o char_count_linha sai do for e espera próxima linha, se houver.
             */


            for (x = 0; x < TILES_X; x++) {
                //printf("%c ", (int)char_count_linha[x]);
                fases_cenario[fases][FRENTE][x][y] = -1;

                fases_cenario[fases][FUNDO][x][y] = char_count_linha[x];


                if (tile != ' ') {
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
                        tile = fases_cenario[fases][FUNDO][x + 1][y + 1];
                    } else {
                        if ((char) fases_cenario[fases][FUNDO][x][y + 1] == '-') {
                            tile = fases_cenario[fases][FUNDO][x][y + 1];
                        } else {
                            if ((char) fases_cenario[fases][FUNDO][x + 1][y] == '-') {
                                tile = fases_cenario[fases][FUNDO][x + 1][y];
                            }
                        }
                    }
                }

                switch (char_count_linha[x]) {
                    case '0':
                        fases_cenario[fases][FRENTE][x][y] = mat[0];
                        fases_cenario[fases][FUNDO][x][y] = (int) tile;
                        break;
                    case '1':
                        fases_cenario[fases][FRENTE][x][y] = mat[1];
                        fases_cenario[fases][FUNDO][x][y] = (int) tile;
                        break;
                    case '2':
                        fases_cenario[fases][FRENTE][x][y] = mat[2];
                        fases_cenario[fases][FUNDO][x][y] = (int) tile;
                        break;
                    case '3':
                        fases_cenario[fases][FRENTE][x][y] = mat[3];
                        fases_cenario[fases][FUNDO][x][y] = (int) tile;
                        break;
                    case '4':
                        fases_cenario[fases][FRENTE][x][y] = mat[4];
                        fases_cenario[fases][FUNDO][x][y] = (int) tile;
                        break;
                    case 'a':
                        fases_cenario[fases][FRENTE][x][y] = mat_erradas[0];
                        fases_cenario[fases][FUNDO][x][y] = (int) tile;
                        break;
                    case 'b':
                        fases_cenario[fases][FRENTE][x][y] = mat_erradas[1];
                        fases_cenario[fases][FUNDO][x][y] = (int) tile;
                        break;
                    case 'c':
                        fases_cenario[fases][FRENTE][x][y] = mat_erradas[2];
                        fases_cenario[fases][FUNDO][x][y] = (int) tile;
                        break;
                    case 'd':
                        fases_cenario[fases][FRENTE][x][y] = mat_erradas[3];
                        fases_cenario[fases][FUNDO][x][y] = (int) tile;
                        break;
                    case 'e':
                        fases_cenario[fases][FRENTE][x][y] = mat_erradas[4];
                        fases_cenario[fases][FUNDO][x][y] = (int) tile;
                        break;
                }

            }
        }

        fclose(fp);
    }

    /*for (y = 0; y < TILES_Y; y++) {
         for (x = 0; x < TILES_X; x++) {
             printf("%d " ,fases_cenario[2][FRENTE][x][y]);
         }
         printf("\n");
    }*/
}

/*
A função abaixo é responsável por declarar e definir as imagens que iremos
utilizar no vetor de texturas. Essas imagens estão dentro da pasta "imagens"
 */
void carrega_texturas(BITMAP *pacman, BITMAP *pacman2, BITMAP *texturas[], BITMAP *numeros) {

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

}

/*
Esta função é responsável por desenhar as texturas do cenário. O cenário a ser
carregado é informado através de um parâmetro. Essa função usa como base a matriz
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
                int num = fases_cenario[fase_atual][FRENTE][x][y];
                int digitos = 1;
                int digitos_inicial = 1;
                while (num / 10 > 0) {
                    num /= 10;
                    digitos++;
                }

                num = fases_cenario[fase_atual][FRENTE][x][y];

                digitos_inicial = digitos;

                while (digitos > 0) {
                    if (digitos > 1) {
                        masked_blit(sheet, buffer, 0, (int) (num / ((digitos - 1)*10))*30, (digitos_inicial - digitos)*15 + x * TAM_TILES_X, y * TAM_TILES_Y, sheet->w, 30);
                        num -= ((digitos - 1) * 10 * ((int) (num / ((digitos - 1)*10))));
                    } else {
                        masked_blit(sheet, buffer, 0, num * 30, (digitos_inicial - digitos)*15 + x * TAM_TILES_X, y * TAM_TILES_Y, sheet->w, 30);
                    }

                    digitos--;
                }
            }
        }
    }
}

//retorna a sequencia de numeros da fase

void fase_funcao(int mat[], int fase) {
    int i;
    switch (fase) {
        case 0:
            //2x
            for (i = 0; i < QTDE_SEQUENCIA; i++) {
                mat[i] = 2 * i;
            }
            break;
        case 1:
            //2x + 1
            for (i = 0; i < QTDE_SEQUENCIA; i++) {
                mat[i] = 2 * i + 1;
            }
            break;
        case 2:
            //3x + 7
            for (i = 0; i < QTDE_SEQUENCIA; i++) {
                mat[i] = 3 * i + 2;
            }

            break;
        case 3:
            //8 - 2x
            for (i = 0; i < QTDE_SEQUENCIA; i++) {
                mat[i] = 10 - (2 * i);
            }

            break;
    }

}

//retorna a sequencia de numeros errados na fase

void fase_numeros_errados(int mat[], int fase) {
    int i;
    switch (fase) {
        case 0:
            //2x + 1
            for (i = 0; i < QTDE_SEQUENCIA; i++) {
                mat[i] = 2 * i + 1;
            }
            break;
        case 1:
            //2x
            for (i = 0; i < QTDE_SEQUENCIA; i++) {
                mat[i] = 2 * i;
            }
            break;
        case 2:
            //3x + 3
            for (i = 0; i < QTDE_SEQUENCIA; i++) {
                mat[i] = 3 * i + 3;
            }

            break;
        case 3:
            //2x + 1
            for (i = 0; i < QTDE_SEQUENCIA; i++) {
                mat[i] = 9 - (2*i);
            }

            break;
    }

}

char *nome_funcao(int numero_fase) {
    switch(numero_fase){
        case 0:
            return "Pares";
        case 1:
            return "Ímpares";
        case 2:
            return "f(x)=3x+2";
        case 3:
            return "f(x)=10-2x";

    }
    return "Fase Desconhecida";
}
