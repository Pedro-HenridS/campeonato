#include "../include/handle_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINHA_MAX 101

void lerCsv(const char *path){
    FILE *file = fopen(path, "r");

    if(file == NULL){
        perror("Erro ao abrir o arquivo");
        return;
    }

    char linha[LINHA_MAX];
    
    while (fgets(linha, LINHA_MAX, file)){
        linha[strcspn(linha, "\n")] = '\0';

        char *token = strtok(linha, ",");

        while (token != NULL) {
            printf("%s\t", token);
            token = strtok(NULL, ",");
        }

        printf("\n");
    }
    fclose(file);
}