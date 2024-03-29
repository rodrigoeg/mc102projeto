#include "carrega_jogo.h"

//A função abaixo serve para carregar os valores que estão dentro do arquivo de fase para a matriz.

void carrega_matriz_jogo(int fases_cenario[QTDE_FASES][2][QTDE_TILES_X][QTDE_TILES_Y]) {
    //A variável abaixo guarda o local onde estão as fases em arquivo texto.
    char *arq_fases[] = {"fases/fase1.txt", "fases/fase2.txt", "fases/fase3.txt"};
    int x = 0;
    int y = 0;
    int fases = 0;


    char char_count_linha[ QTDE_TILES_X ]; // Qtde de caracteres por linha


    //O for abaixo é para preencher todas as fases.
    for (fases = 0; fases < QTDE_FASES; fases++) {
        int mat[5];
        int mat_erradas[5];
        fase_funcao(mat, fases);
        fase_numeros_errados(mat_erradas, fases);
        char tile = ' ';

        // Abre o arquivo de fases para leitura com base no fases_cenario e o vetor de fases
        FILE *fp = fopen(arq_fases[fases], "r");

        //Preenche a matriz na horizontal e vertical
        for (y = 0; y < QTDE_TILES_Y; y++) {

            fgets(char_count_linha, TAMANHO_TILES_X, fp);


            /*
               Já com o char_count_linha preenchido, agora, o FOR abaixo varre todas as
               posições dessa linha e acrescenta na linha da matriz. Após terminar
               de varrer o char_count_linha sai do for e espera próxima linha, se houver.
             */


            for (x = 0; x < QTDE_TILES_X; x++) {
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

}

/*
Esta função é responsável por desenhar as texturas do cenário. O cenário a ser
carregado é informado através de um parâmetro. Essa função usa como base a matriz
carregada anteriormente para desenhar as texturas.
 */
void atualiza_tela(BITMAP *buffer, int fase_atual, int fases_cenario[QTDE_FASES][2][QTDE_TILES_X][QTDE_TILES_Y], BITMAP *namcap, BITMAP *texturas[], int ultima_movimentacao, BITMAP *sheet) {
    int x = 0;
    int y = 0;
    char tile = ' ';

    for (y = 0; y < QTDE_TILES_Y; y++) {
        for (x = 0; x < QTDE_TILES_X; x++) {
            if ((char) fases_cenario[fase_atual][FUNDO][x][y] == '#') { // Parede
                draw_sprite(buffer, texturas[0], x * TAMANHO_TILES_X, y * TAMANHO_TILES_Y);
            } else {
                if ((char) fases_cenario[fase_atual][FUNDO][x][y] == '-') { // Grama
                    tile = '-';
                    draw_sprite(buffer, texturas[1], x * TAMANHO_TILES_X, y * TAMANHO_TILES_Y);
                } else {
                    if ((char) fases_cenario[fase_atual][FUNDO][x][y] == '.') { // Chão
                        tile = '.';
                        draw_sprite(buffer, texturas[2], x * TAMANHO_TILES_X, y * TAMANHO_TILES_Y);
                    } else {
                        if ((char) fases_cenario[fase_atual][FUNDO][x][y] == 'P') { // namcap
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
                                draw_sprite(buffer, texturas[1], x * TAMANHO_TILES_X, y * TAMANHO_TILES_Y);
                            } else {
                                if (tile == '.') { // Chão
                                    draw_sprite(buffer, texturas[2], x * TAMANHO_TILES_X, y * TAMANHO_TILES_Y);
                                }
                            }

                            switch (ultima_movimentacao) {
                                case DIR_UP:
                                    rotate_sprite(buffer, namcap, x * TAMANHO_TILES_X, y * TAMANHO_TILES_Y, itofix(-64));
                                    break;
                                case DIR_DOWN:
                                    rotate_sprite(buffer, namcap, x * TAMANHO_TILES_X, y * TAMANHO_TILES_Y, itofix(64));
                                    break;
                                case DIR_LEFT:
                                    draw_sprite_h_flip(buffer, namcap, x * TAMANHO_TILES_X, y * TAMANHO_TILES_Y);
                                    break;
                                case DIR_RIGHT:
                                    draw_sprite(buffer, namcap, x * TAMANHO_TILES_X, y * TAMANHO_TILES_Y);
                                    break;
                            }
                        } else {
                            if (tile == '-') { // Grama
                                draw_sprite(buffer, texturas[1], x * TAMANHO_TILES_X, y * TAMANHO_TILES_Y);
                            } else {
                                if (tile == '.') { // Chão
                                    draw_sprite(buffer, texturas[2], x * TAMANHO_TILES_X, y * TAMANHO_TILES_Y);
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
                        masked_blit(sheet, buffer, 0, (int) (num / pow(10, digitos - 1))*30, (digitos_inicial - digitos)*15 + x * TAMANHO_TILES_X, y * TAMANHO_TILES_Y, sheet->w, 27);
                        num -= ((int) (num / pow(10, digitos - 1))) * pow(10, digitos - 1);
                    } else {
                        masked_blit(sheet, buffer, 0, num * 30, (digitos_inicial - digitos)*15 + x * TAMANHO_TILES_X, y * TAMANHO_TILES_Y, sheet->w, 30);
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
    }

}

char *nome_funcao(int numero_fase) {
    switch (numero_fase) {
        case 0:
            return "Pares";
        case 1:
            return "Ímpares";
        case 2:
            return "f(x)=3x+2";
    }
    return "Fase Desconhecida";
}
