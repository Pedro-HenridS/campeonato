#include "../include/time.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


Time* Create_Time(
    int id,
    char *nome)
{
    Time* novo_time = (Time* ) malloc(sizeof(Time));
    if (novo_time == NULL) {
        perror("Erro ao alocar memoria para Time");
        exit(EXIT_FAILURE);
    }
    
    novo_time->id = id;
    
    strncpy(novo_time->nome, nome, MAX_NOME_TIME - 1);
    novo_time->nome[MAX_NOME_TIME - 1] = '\0';
    
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