#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>

//A variável abaixo guarda o local onde estão as fases em arquivo texto.
const char *ArqFases[] = {"fases/fase1.txt", "fases/fase2.txt", "fases/fase3.txt"};

const int iQtdeFases = 3; // Jogo com 3 fases
const int iTamTilesX = 32; // Largura do Tile
const int iTamTilesY = 32; // Altura do Tile
const int iTilesX = 20; // Qtde de Tiles na horizontal - 32*20 = 640;
const int iTilesY = 15; // Qtde de Tiles na vertical   - 32*15 = 480;


int fps = 0;
int fps_antigo = 0;
int fps_speed = 0;

// prototipo do contador de frames
void frame_rate();

// prototipo do contador de velocidade
void incrementa_speed();

void Teclado();
void CarregaMatriz(int [iQtdeFases][iTilesX][iTilesY]);


void CarregaTexturas();
void DesenhaCenario(BITMAP *, int, int [iQtdeFases][iTilesX][iTilesY]);

/*
Com base nas variáveis acima temos o tamanho da tela 640x480, conforme abaixo:
   (iTamTilesX * iTilesX) = SCREEN_W;
   (iTamTilesY * iTilesY) = SCREEN_H;
   (32 * 20) = 640;
   (32 * 15) = 480;
 */

int iFaseAtual = 0; // Guarda o index da fase atual.

//Variável do tipo BITMAP responsável por guardar as texturas
BITMAP *Textura[3] = {NULL, NULL, NULL};
BITMAP *Pacman;

/*
A função abaixo é a mais importante com relação ao arquivo de fases. Ela serve
para carregar os valores que estão dentro do arquivo de fase para a matriz.
Com base na matriz iremos montar o cenário de cada fase e posicionar suas
respectivas texturas ou objetos, dependendo de como você modificar o código.
 */
void CarregaMatriz(int Mapa[iQtdeFases][iTilesX][iTilesY]) {
    int x = 0;
    int y = 0;
    int iFase = 0;

    char sLinha[ iTilesX ]; // Qtde de caracteres por linha

    //O FOR abaixo é para preencher todas as fases.
    for (iFase = 0; iFase < iQtdeFases; iFase++) {
        // Abre o arquivo de fases para leitura com base no iFase e o Array de fases
        FILE *fp = fopen(ArqFases[iFase], "r");


        //Preenche a matriz na horizontal e vertical
        for (y = 0; y < iTilesY; y++) {
            /*
            Atribui na variável sLinha a linha atual do arquivo texto.
            Toda vez que essa rotina for chamada ele pula para a proxima linha e
            joga o valor para sLinha, até finalizar as 15 linhas.
             */

            fgets(sLinha, iTamTilesX , fp);

            /*
               Já com o sLinha preenchido, agora, o FOR abaixo varre todas as
               posições dessa linha e acrescenta na linha da matriz. Após terminar
               de varrer o sLinha sai do for e espera próxima linha, se houver.
             */
            for (x = 0; x < iTilesX; x++) {
                printf("%c", sLinha[x]);
                Mapa[iFase][x][y] = sLinha[x];
            }
            printf("\n");
        }

        printf("\n");
        printf("\n");
        printf("\n");
        fclose(fp);
    }
}

/*
A função abaixo é responsável por declarar e definir as imagens que iremos
utilizar no Array Textura. Essa imagens devem estar dentro da pasta imagens no
nosso projeto,caso contrário o programa irá apresentar a mensagem de erro fatal.
 */
void CarregaTexturas() {
    // Define o índice 0 da textura como sendo parede
    Textura[0] = load_bitmap("tiles/parede.bmp", NULL);

    // Define o índice 1 da textura como sendo grama
    Textura[1] = load_bitmap("tiles/grama.bmp", NULL);

    // Define o índice 2 da textura como sendo chão
    Textura[2] = load_bitmap("tiles/chao.bmp", NULL);

    Pacman = load_bitmap("imagens/pac-man.bmp", NULL);
}

/*
Essa função é responsável por desenhar as texturas do cenário. O cenário a ser
carregado é informado através de um argumento. Essa função usa como base a matriz
carregada anteriormente para desenhar as texturas.
 */
void DesenhaCenario(BITMAP *Cenario, int iFase, int Mapa[iQtdeFases][iTilesX][iTilesY]) {
    int x = 0;
    int y = 0;


    for (y = 0; y < iTilesY; y++) {
        for (x = 0; x < iTilesX; x++) {
            if ((char) Mapa[iFase][x][y] == '#') // Parede
                draw_sprite(Cenario, Textura[0], x * iTamTilesX, y * iTamTilesY);
            else
                if ((char) Mapa[iFase][x][y] == '-') // Grama
                draw_sprite(Cenario, Textura[1], x * iTamTilesX, y * iTamTilesY);
            else
                if ((char) Mapa[iFase][x][y] == '.') // Chão
                draw_sprite(Cenario, Textura[2], x * iTamTilesX, y * iTamTilesY);
                else
                    if((char) Mapa[iFase][x][y] == 'P') // Pacman
                        draw_sprite(Cenario, Pacman, x * iTamTilesX, y * iTamTilesY);
        }
    }
}

/*
A função abaixo é responsável por controlar as entradas do teclado, qualquer
tecla pressionada durante a execução do jogo.
 */
void Teclado() {
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
            if (iFaseAtual < (iQtdeFases - 1))
                iFaseAtual++;
            else
                iFaseAtual = 0;

            Buffer_Teclado = 30;
        }
    } else Buffer_Teclado--;
}

void frame_rate() {
    fps_antigo = fps;
    fps = 0;
}

void incrementa_speed() {
    fps_speed++;
}

int main() {

    /*
         Variáveis Mapa tridimensional sendo o primeiro ecrãn a Fase e os
        outros dois correspondem a quantidade de Tiles na horizontal e vertical.
     */
    allegro_init();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
    set_window_title("Fases em arquivos textos");

    int Mapa[iQtdeFases][iTilesX][iTilesY];
    install_timer();
    install_int(frame_rate, 1000);
    install_int_ex(incrementa_speed, BPS_TO_TIMER(60));

    //Habilita Acentuação
    set_uformat(U_ASCII);

    BITMAP *Buffer = NULL;
    Buffer = create_bitmap(SCREEN_W, SCREEN_H);

    CarregaMatriz(Mapa);
    CarregaTexturas();

    while (!key[KEY_ESC]) {
        while (fps_speed > 0) {
            clear_bitmap(Buffer);
            DesenhaCenario(Buffer, iFaseAtual, Mapa);
            Teclado();

            textprintf_ex(Buffer, font, 8, 10, makecol(255, 255, 0), -1, "FPS: %d", fps_antigo);
            textprintf_centre_ex(Buffer, font, SCREEN_W / 2, (SCREEN_H / 2) - 10, makecol(255, 255, 0),
                    -1, "FASE: %d", iFaseAtual + 1);
            textprintf_centre_ex(Buffer, font, SCREEN_W / 2, SCREEN_H / 2, makecol(255, 255, 0), -1,
                    "Pressione espaço para mudar de fase.");

            fps_speed--;
            fps++;
        }
        blit(Buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        vsync();
    }

    //Desaloca as imagens da memória
    destroy_bitmap(Buffer);
    destroy_bitmap(Textura[0]);
    destroy_bitmap(Textura[1]);
    destroy_bitmap(Textura[2]);
    allegro_exit();

    return 0;
}
END_OF_MAIN();
