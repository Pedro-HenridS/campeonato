#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/bd_partida.h"
#include "../include/partida.h"

#define LINHA_MAX 256
#define MAX_PARTIDAS 90
#define DELIMITADOR ","

Partida* pegar_partidas() {
    FILE *file = fopen("Database/partidas_completo.csv", "r");
    if (file == NULL) return NULL;

    char linha[LINHA_MAX];
    int count = 0;

    Partida* bd = (Partida*) malloc(MAX_PARTIDAS * sizeof(Partida));
    if (bd == NULL) {
        fclose(file);
        return NULL;
    }

    fgets(linha, LINHA_MAX, file);

    while (fgets(linha, LINHA_MAX, file) != NULL && count < MAX_PARTIDAS) {
        linha[strcspn(linha, "\n")] = '\0';

        char *token;
        int campo_atual = 0;
        int id = 0, time1_id = 0, time2_id = 0, gols_time1 = 0, gols_time2 = 0;

        token = strtok(linha, DELIMITADOR);
        while (token != NULL) {
            int valor = atoi(token);
            switch (campo_atual) {
                case 0: id = valor; break;
                case 1: time1_id = valor; break;
                case 2: time2_id = valor; break;
                case 3: gols_time1 = valor; break;
                case 4: gols_time2 = valor; break;
            }
            token = strtok(NULL, DELIMITADOR);
            campo_atual++;
        }

        if (campo_atual == 5) {
            bd[count].id = id;
            bd[count].time1_id = time1_id;
            bd[count].time2_id = time2_id;
            bd[count].gols_time1 = gols_time1;
            bd[count].gols_time2 = gols_time2;
            count++;
        }
    }

    fclose(file);
    return bd;
}
