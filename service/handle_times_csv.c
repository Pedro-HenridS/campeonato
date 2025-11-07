#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/time.h"

#define LINHA_MAX 256
#define MAX_PARTIDAS 90
#define DELIMITADOR ","

Time* get_times() {
    FILE *file = fopen("Database/times.csv", "r");
    if (!file) return NULL;

    char linha[256];
    int count = 0;
    Time* times = malloc(MAX_PARTIDAS * sizeof(Time));
    if (!times) { fclose(file); return NULL; }

    fgets(linha, sizeof(linha), file); // pula cabeçalho

    while (fgets(linha, sizeof(linha), file) != NULL && count < MAX_PARTIDAS) {
        linha[strcspn(linha, "\n")] = '\0';

        char *token = strtok(linha, ",");
        if (token != NULL) times[count].id = atoi(token);

        token = strtok(NULL, ",");
        if (token != NULL) times[count].nome = strdup(token);

        count++;
    }

    fclose(file);
    return times;
}

