#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "../include/bd_partida.h"
#include "../include/handle_partidas_csv.h"
#include "../include/divider.h"
#include "../include/roadmap.h"

//Algumas funções foram implementadas já esperando a parte II

void _Menu_Principal() {
    char escolha = ' ';

    BDPartidas* partidas = criar_bd_partidas();
    BDTimes* times = criar_bd_times();

    char nome[100];
    int modo;

    char *csv_time = "Database/times.csv";

    while (escolha != 'Q') {
        printf("Escolha uma opção\n");
        printf("1 - Consultar Time\n");
        printf("2 - Consultar Partida\n");
        printf("3 - Atualizar Partida\n");
        printf("4 - Remover Partida\n");
        printf("5 - Atualizar Partida\n");
        printf("6 - Imprimir tabela de classificação\n");
        printf("Q - Sair \n");
        scanf(" %c", &escolha);

        switch (escolha) {
            case '1':
                break;

            case '2':

                roadmap2(&nome, &modo);

                bd_partidas_consulta(partidas, nome, modo);

                break;

            case '6':
                get_result(times);
                bd_times_imprime_tabela(times);

                break;

            case 'Q':
                printf("Tchauzin\n");
                break;
        }
    }
}

int main() {
    _Menu_Principal();
    return 0;
}


/*
    Pegar cada time preenchido
    
*/