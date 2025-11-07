#ifndef TIME_H
#define TIME_H

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

typedef struct time {
    int id;
    char nome[20];
    int vitorias;
    int empates;
    int derrotas;
    int gols_marcados;
    int gols_sofridos;
} Time;

Time* Create_Time(
    char nome, 
    int vitorias, 
    int empates, 
    int derrotas,
    int gols_marcados,
    int gols_sofridos);

void time_free(Time* t);

void time_atualiza_tabela(Time* t, int gols_pro, int gols_contra);

int time_calcula_pontos(const Time* t);

int time_calcula_saldo_gols(const Time* t);

void time_imprime(const Time* t);

#endif