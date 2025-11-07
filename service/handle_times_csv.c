#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINHA_MAX 256
#define MAX_LINHAS 1000  // limite máximo de linhas

char **ler(const char *path, int *qtd_linhas) {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    char **linhas = malloc(MAX_LINHAS * sizeof(char *));
    if (linhas == NULL) {
        perror("Erro ao alocar memória");
        fclose(file);
        return NULL;
    }

    char linha[LINHA_MAX];
    int count = 0;

    while (fgets(linha, LINHA_MAX, file)) {
        linha[strcspn(linha, "\n")] = '\0'; // remove quebra de linha

        linhas[count] = malloc(strlen(linha) + 1);
        if (linhas[count] == NULL) {
            perror("Erro ao alocar linha");
            break;
        }

        strcpy(linhas[count], linha);
        count++;

        if (count >= MAX_LINHAS) break; // evita ultrapassar limite
    }

    fclose(file);
    *qtd_linhas = count;
    return linhas;
}