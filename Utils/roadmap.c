#include "../include/roadmap.h"

void roadmap2(char *nome, int *modo){
    divider();
    printf("Escreva o nome do time: ");
    scanf("%99s", nome);
    divider();
    printf("Escolha uma das opções: \n");
    printf("1. Como mandante \n");
    printf("2. Como visitante \n");
    printf("3. Como mandante e visitante \n");
    scanf("%d", modo);
    divider();            
};
