#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "../include/handle_file.h"
#include "time.h"
#include "bd_time.h"
#include "bd_partida.h"

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

void _Consultar_Time(){
    char nome[50];
    Time* resultados[10];
    printf("Digite o nome do time: ");
    scanf("%c", &nome);
    nome[strcspn(nome, "\n")] = 0;
    int quanti_encontrados = bd_times_busca_por_prefixo(lista_times, nome, resultados);

    if(quanti_encontrados > 0){
        time_imprime_topo();
        for(int i = 0, i < quanti_encontrados, i++ ){
            ptime_imprime_linha(resultados[i]);
        }
    }
    else{
        printf("Não há nenhum time com esse nome");
    }

}


int main(){
    _Menu_Principal();
    
    return 0;
    
}
