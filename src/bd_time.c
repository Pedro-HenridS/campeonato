#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/bd_time.h"
#include "../include/handle_partidas_csv.h"
#include "../include/handle_times_csv.h" 
#include "../include/find_index.h"
#include "../include/time.h"
#include "../include/partida.h"            

#define LINHA_MAX 256

static char** lerCsv(const char *path, int *num_linhas) {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        *num_linhas = 0;
        return NULL;
    }

    char **linhas = NULL;
    char buffer[LINHA_MAX];
    int capacidade = 0;
    *num_linhas = 0;

    while (fgets(buffer, LINHA_MAX, file)) {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strlen(buffer) == 0) continue;

        if (*num_linhas >= capacidade) {
            capacidade = (capacidade == 0) ? 16 : capacidade * 2;
            linhas = realloc(linhas, capacidade * sizeof(char*));
            if (!linhas) {
                perror("Erro de memória ao ler CSV");
                fclose(file);
                return NULL;
            }
        }

        linhas[*num_linhas] = strdup(buffer);
        (*num_linhas)++;
    }

    fclose(file);
    return linhas;
}

BDTimes* criar_bd_times() {
    BDTimes *buffer = malloc(sizeof(BDTimes));
    if (!buffer) return NULL;

    buffer->times = get_times();
    buffer->qtd = MAX_TIMES;
    buffer->cap = MAX_TIMES;

    return buffer;
}

void bd_times_libera(BDTimes* bd) {
    if (!bd) return;
    free(bd->times);
    free(bd);
}

Time* bd_times_busca_por_id(const BDTimes* bd, int id) {
    if (!bd) return NULL;
    for (int i = 0; i < bd->qtd; i++) {
        if (bd->times[i].id == id)
            return &bd->times[i];
    }
    return NULL;
}

void get_result(BDTimes* bd) {
    Partida* partidas = pegar_partidas();

    for (int i = 0; i < bd->qtd; i++) {
        bd->times[i].vitorias = 0;
        bd->times[i].empates = 0;
        bd->times[i].derrotas = 0;
        bd->times[i].gols_marcados = 0;
        bd->times[i].gols_sofridos = 0;
    }

    for (int i = 0; i < bd->qtd; i++) {
        Time *currentTime = &bd->times[i];

        for (int t = 0; t < MAX_PARTIDAS; t++) {
            if (currentTime->id == partidas[t].time1_id) {
                currentTime->gols_marcados += partidas[t].gols_time1;
                currentTime->gols_sofridos += partidas[t].gols_time2;

                if (partidas[t].gols_time1 == partidas[t].gols_time2)
                    currentTime->empates++;
                else if (partidas[t].gols_time1 > partidas[t].gols_time2)
                    currentTime->vitorias++;
                else
                    currentTime->derrotas++;
            }

            if (currentTime->id == partidas[t].time2_id) {
                currentTime->gols_marcados += partidas[t].gols_time2;
                currentTime->gols_sofridos += partidas[t].gols_time1;

                if (partidas[t].gols_time2 == partidas[t].gols_time1)
                    currentTime->empates++;
                else if (partidas[t].gols_time2 > partidas[t].gols_time1)
                    currentTime->vitorias++;
                else
                    currentTime->derrotas++;
            }
        }
    }
}

void bd_times_imprime_tabela(const BDTimes* bd) {
    if (!bd) return;

    printf("=== TABELA DE TIMES ===\n");
    for (int i = 0; i < bd->qtd; i++) {
        Time *t = &bd->times[i];
        int saldo = t->gols_marcados - t->gols_sofridos;

        printf("[%d] %-15s  V:%d  E:%d  D:%d  GM:%d  GS:%d  SG:%d\n",
               t->id,
               t->nome,
               t->vitorias,
               t->empates,
               t->derrotas,
               t->gols_marcados,
               t->gols_sofridos,
               saldo);
    }
}