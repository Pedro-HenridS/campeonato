#include "bd_time.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/bd_time.h"
#include "../include/bd_time.h"

#define LINHA_MAX 256
#define INITIAL_CAP 64

/*static char** lerCsv(const char *path, int *num_linhas) {
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
}*/

static int strncasecmp_c99(const char *s1, const char *s2, size_t n) {
    if (n == 0) return 0;
    while (n-- != 0 && *s1 != '\0' && tolower((unsigned char)*s1) == tolower((unsigned char)*s2)) {
        s1++;
        s2++;
    }
    return (n == (size_t)-1) ? 0 : tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}


BDTimes* bd_times_cria(const char* nome_arquivo) {
    BDTimes* bd = (BDTimes*) malloc(sizeof(BDTimes));
    if (bd == NULL) {
        perror("Erro ao alocar memoria para BDTimes");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(nome_arquivo, "r");
    if (fp == NULL) {
        perror("Erro ao abrir times.csv");
        bd_times_libera(bd);
        exit(EXIT_FAILURE);
    }

    char line[LINHA_MAX];
    int count = 0;

    // Ignora o cabeçalho
    if (fgets(line, LINHA_MAX, fp) == NULL) {
        fprintf(stderr, "Erro ao ler cabeçalho de times.csv\n");
        fclose(fp);
        bd_times_libera(bd);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, LINHA_MAX, fp) != NULL && count < NUM_TIMES) {
        int id;
        char nome[MAX_NOME_TIME];
        
        // Formato esperado: ID,Nome
        if (sscanf(line, "%d,%49[^\n]", &id, nome) == 2) {
            bd->times[count] = Create_Time(id, nome);
            count++;
        } else {
            fprintf(stderr, "Aviso: Linha mal formatada em times.csv: %s", line);
        }
    }

    fclose(fp);
    
    // Inicializa os ponteiros restantes como NULL, caso o arquivo tenha menos de NUM_TIMES
    for (int i = count; i < NUM_TIMES; i++) {
        bd->times[i] = NULL;
    }

    if (count != NUM_TIMES) {
        fprintf(stderr, "Aviso: Esperado %d times, encontrado %d em times.csv\n", NUM_TIMES, count);
    }

    return bd;
}

void bd_times_libera(BDTimes* bd) {
    if (!bd) return;
    free(bd->times);
    free(bd);
}

/*Time* bd_times_busca_por_id(const BDTimes* bd, int id) {
    if (!bd) return NULL;
    for (int i = 0; i < bd->qtd; i++) {
        if (bd->times[i]->id == id)
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
}*/
int bd_times_busca_por_prefixo(const BDTimes* bd, const char* prefixo, Time* resultados[]) {
    int count = 0;
    size_t len_prefixo = strlen(prefixo);

    for (int i = 0; i < NUM_TIMES; i++) {
        if (bd->times[i] && strncasecmp_c99(bd->times[i]->nome, prefixo, len_prefixo) == 0) {
            resultados[count++] = bd->times[i];
        }
    }
    return count;
}
