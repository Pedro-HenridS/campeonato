#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/bd_time.h"

#define LINHA_MAX 256
#define INITIAL_CAP 64

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

BDTimes* bd_times_cria(const char* nome_arquivo) {
    int num_linhas = 0;
    char **linhas = lerCsv(nome_arquivo, &num_linhas);
    if (!linhas || num_linhas == 0) {
        fprintf(stderr, "Arquivo vazio ou inexistente: %s\n", nome_arquivo);
        return NULL;
    }

    BDTimes *bd = malloc(sizeof(BDTimes));
    bd->times = malloc(INITIAL_CAP * sizeof(Time));
    bd->qtd = 0;
    bd->cap = INITIAL_CAP;

    for (int i = 0; i < num_linhas; i++) {
        Time t;
        char nome[MAX_NOME_TIME];

        // Lê cada linha do CSV:
        // id,nome,vitorias,empates,derrotas,gols_marcados,gols_sofridos
        int ok = sscanf(linhas[i], "%d,%49[^,],%d,%d,%d,%d,%d",
                        &t.id,
                        nome,
                        &t.vitorias,
                        &t.empates,
                        &t.derrotas,
                        &t.gols_marcados,
                        &t.gols_sofridos);

        if (ok == 7) {
            strncpy(t.nome, nome, MAX_NOME_TIME - 1);
            t.nome[MAX_NOME_TIME - 1] = '\0';

            if (bd->qtd >= bd->cap) {
                bd->cap *= 2;
                bd->times = realloc(bd->times, bd->cap * sizeof(Time));
            }
            bd->times[bd->qtd++] = t;
        }

        free(linhas[i]);
    }

    free(linhas);
    return bd;
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
            return &((Time*)bd->times)[i];
    }
    return NULL;
}

void bd_times_imprime_tabela(const BDTimes* bd) {
    if (!bd) return;

    printf("=== TABELA DE TIMES ===\n");
    for (int i = 0; i < bd->qtd; i++) {
        Time *t = &bd->times[i];
        printf("[%d] %-15s  V:%d  E:%d  D:%d  GM:%d  GS:%d\n",
               t->id,
               t->nome,
               t->vitorias,
               t->empates,
               t->derrotas,
               t->gols_marcados,
               t->gols_sofridos);
    }
}
