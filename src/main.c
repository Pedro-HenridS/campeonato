#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "../include/handle_file.h"

void _Menu_Principal(){
    char escolha;
    while (escolha != 'Q'){
        printf("Escolha uma opção\n");
        printf("1 - Consultar Time\n");
        printf("2 - Consultar Partida\n");
        printf("3 - Atualizar Partida\n");
        printf("4 - Remover Partida\n");
        printf("5 - Atualizar Partida\n");
        printf("6 - Imprimir tabela de classificação\n");
        printf("Q - Sair \n");
        scanf(" %c", &escolha);

        char * csv_time = "Database/times.csv";

        switch(escolha){
            case '1': lerCsv(csv_time);
            break;
            case '2': 
            break;
            case '6': 
            break;       
            case 'Q': printf("Tchauzin");
            break;
}
}
}
int main(){
    _Menu_Principal();
    
    return 0;
    
}
