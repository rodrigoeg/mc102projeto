#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "carrega_fases.h"
#include <string.h>

void le_score(int scores[10]) {
    int i = 0;

    char char_count_linha[50];


    FILE *fp = fopen("fases/scores.txt", "r");


    char *result = NULL;
    for (i = 0; i < 10; i++) {
        fgets(char_count_linha, 100, fp);

        char delims[] = "|";

        strtok(char_count_linha, delims);
        result = strtok(NULL, delims);
        scores[i] = atoi(result);
    }

    fclose(fp);

}

void salva_score(int scores[10], int score) {
    int i = 0;
    char char_count_linha[50];
    char numeracao[100];
    int score_salvo = FALSE;

    FILE *fp = fopen("fases/scores.txt", "w");

    for (i = 0; i < 10; i++) {
        if ((score >= scores[i]) && (score_salvo == FALSE) || ((i == 9) && (score_salvo == FALSE))) {
            itoa(score, char_count_linha, 10);
            itoa(i, numeracao, 10);
            strcat(numeracao, "|");
            strcat(numeracao, char_count_linha);
            fputs(numeracao, fp);
            fputs("\n", fp);
            score_salvo = TRUE;
        }

        if ((score_salvo == TRUE)) {
            if ((i < 9)) {
                itoa(scores[i], char_count_linha, 10);
                itoa(i, numeracao, 10);
                strcat(numeracao, "|");
                strcat(numeracao, char_count_linha);
                fputs(numeracao, fp);
                fputs("\n", fp);
            }

        } else {
            itoa(scores[i], char_count_linha, 10);
            itoa(i, numeracao, 10);
            strcat(numeracao, "|");
            strcat(numeracao, char_count_linha);
            fputs(numeracao, fp);
            fputs("\n", fp);
        }



    }

    fclose(fp);
}

void update_score(BITMAP *buffer, BITMAP *numeros, BITMAP *score_bmp, int score) {
    int num;
    int digitos = 1;
    int digitos_inicial = 1;

    if (score < 0) {
        //colocar sinal de menos
        masked_blit(numeros, buffer, 0, (10)*30, 380, 0, numeros->w, 27);
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
            masked_blit(numeros, buffer, 0, (int) (score / ((digitos - 1)*10))*30, (digitos_inicial - digitos)*20 + 400, 0, numeros->w, 27);
            score -= ((digitos - 1) * 10 * ((int) (score / ((digitos - 1)*10))));
        } else {

            masked_blit(numeros, buffer, 0, score * 30, (digitos_inicial - digitos)*20 + 400, 0, numeros->w, 27);
        }

        digitos--;
    }

    draw_sprite(buffer, score_bmp, 280, 0);
}

int calcula_score(int pontos, int total) {
    return pontos + total;
}

void mostrar_scores(BITMAP *buffer, int scores[10]) {
    int i;
    for (i = 0; i < 10; i++) {
        textprintf_ex(buffer, font, 150, 70 + 30 * (i + 1), makecol(255, 255, 255), -1, "%d°: %d", i + 1, scores[i]);
    }
}
