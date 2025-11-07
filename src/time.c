#include "time.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Time* Create_Time(int id, const char nome){

    Time* novo_time = (Time* ) malloc(sizeof(Time));
    if (novo_time == NULL) {
        perror("Erro ao alocar memoria para Time");
        exit(EXIT_FAILURE);
    }
    novo_time->id = id;
    novo_time->vitorias = 0;
    novo_time->empates = 0;
    novo_time->derrotas = 0;
    novo_time->gols_marcados = 0;
    novo_time->gols_sofridos = 0;
    strncpy(novo_time->nome, nome, MAX_NOME_TIME - 1);
    novo_time->nome[MAX_NOME_TIME - 1] = '\0';

}

void time_libera(Time* t) {
    free(t);
}

void time_atualiza_tabela(Time* t, int gols_pro, int gols_contra);{

    if (gols_pro > gols_contra) {
        t->vitorias = t->vitorias + 1;
    } else if (gols_pro == gols_contra) {
        t->empates = t->empates + 1;
    } else {
        t->derrotas = t->derrotas +1;
    }
    t->gols_marcados =gols_marcados + gols_pro;
    t->gols_sofridos = gols_sofridos + gols_contra;

}

int time_calcula_pontos(const Time* t) {
    int pontos = (3*t->vitorias) + t->empates
    return pontos;
}

int time_calcula_saldo_gols(const Time* t) {
    int saldo_gols = t->gols_marcados - t->gols_sofridos
    return saldo_gols;
}

void time_imprime_topo(const Time* t){
    printf("ID Time         V  E  D  GM GS  S PG\n");
    printf("-------------------------------------\n")

}
void time_imprime_conteudo(const Time* t){
    printf("%-2d %-12s %-2d %-2d %-2d %-2d %-2d %-2d %-2d\n",t->id, t->nome, t->vitorias, t->empates,
           t->derrotas, t->gols_marcados, t->gols_sofridos, time_calcula_saldo_gols(t), time_calcula_pontos(t));
}