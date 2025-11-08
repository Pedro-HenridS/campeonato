#include "../include/time.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "..\include\handle_partidas_csv.h"
#include "..\include\handle_times_csv.h"
#include "..\include\time.h"
#include "..\include\find_index.h"
#include "time.h"
#include "bd_time.h"
#include "../include/find_index.h"
#include <bd_partida.h>



Time* Create_Time(
    int id,
    char *nome)
{
    Time* novo_time = (Time*) malloc(sizeof(Time));
    if (novo_time == NULL) {
        perror("Erro ao alocar memoria para Time");
        exit(EXIT_FAILURE);
    }
    
    novo_time->id = id;
    
    strncpy(novo_time->nome, nome, MAX_NOME_TIME - 1);
    novo_time->nome[MAX_NOME_TIME - 1] = '\0';
    novo_time->vitorias = 0;
    novo_time->empates = 0;
    novo_time->derrotas = 0;
    novo_time->gols_marcados = 0;
    novo_time->gols_sofridos = 0;
    
    return novo_time;
}

void time_libera(Time* t) {
    free(t);
}

void time_atualiza_tabela(Time* t, int gols_pro, int gols_contra){
    if (gols_pro > gols_contra) {
        t->vitorias = t->vitorias + 1;
    } else if (gols_pro == gols_contra) {
        t->empates = t->empates + 1;
    } else {
        t->derrotas = t->derrotas +1;
    }
    t->gols_marcados += gols_pro;
    t->gols_sofridos += gols_contra;
}

int time_calcula_pontos(const Time* t) {
    int pontos = (3*t->vitorias) + t->empates;
    return pontos;
}

int time_calcula_saldo_gols(const Time* t) {
    int saldo_gols = t->gols_marcados - t->gols_sofridos;
    return saldo_gols;
}

void time_imprime(const Time* t){
    if (t == NULL) {
        printf("Erro: Ponteiro para Time e' NULL.\n");
        return;
    }
    
    printf("--- Dados do Time ---\n");
    printf("ID: %d\n", t->id);
    printf("Nome: %s\n", t->nome);
    printf("Vitorias: %d, Empates: %d, Derrotas: %d\n", t->vitorias, t->empates, t->derrotas);
    printf("Gols Marcados: %d, Gols Sofridos: %d\n", t->gols_marcados, t->gols_sofridos);
    printf("Pontos: %d | Saldo de Gols: %d\n", time_calcula_pontos(t), time_calcula_saldo_gols(t));
}

void time_imprime_topo() {
    printf("ID Time         V  E  D  GM GS  S PG\n");
    printf("-------------------------------------\n");
}

void time_imprime_linha(const Time* t) {
    printf("%-2d %-12s %-2d %-2d %-2d %-2d %-2d %-2d %-2d\n",
           t->id,
           t->nome,
           t->vitorias,
           t->empates,
           t->derrotas,
           t->gols_marcados,
           t->gols_sofridos,
           time_calcula_saldo_gols(t),
           time_calcula_pontos(t));
}

void _Consultar_Time(){
    char *nome;
    Time* bd_times = get_times();
    Time* resultados[NUM_TIMES];
    int cont = 0;

    printf("Digite o nome do time: ");
    scanf("%s", nome);

    

    // while (getchar() != '\n');
    // if (fgets(nome, MAX_NOME_TIME, stdin) == NULL) {
    //     return;
    // }

    // nome[strcspn(nome, "\n")] = 0;
    // int control = 0;
    
    // for(int i = 0; i < NUM_TIMES; i++){
    //     if(findIndex(nome, bd_times[i].nome)== 0){
    //         if (control == 0){
    //             time_imprime_topo();
    //             control = 1;
    //         }
    //         for()

    //         cont++;
            
    //     }
    // }

    void atualizar_time(){
        
        Time* times = get_times();
        BDPartidas* partidas = pegar_partidas();
        
        for(int i = 0; i<NUM_TIMES; i++){
            for (int j = 0, j < MAX_PARTIDAS ; i++){
                if (partidas[j].time1_id == i){
                    time_atualiza_tabela(Times[i], partid[j].gols_time1, partid[j].gols_time2);
            }
                
                else if (partidas[j].time2_id == i){
                    time_atualiza_tabela(Times[i], partid[j].gols_time2, partid[j].gols_time1);}
            }
            time_calcula_saldo_gols(times[i])
        }
    }
   
}
 