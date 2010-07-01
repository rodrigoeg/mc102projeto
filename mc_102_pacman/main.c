#include "carrega_jogo.h"

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

                if (atualizar_contador(buffer, numeros) == FALSE) {
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
                        play_sample(intro, 500, 0, 1000, 0);
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
                        -1, "FASE: %d %s", fase_atual + 1, nome_funcao(fase_atual));

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
                        -1, "FASE: %d %s", fase_atual + 1, nome_funcao(fase_atual));
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
