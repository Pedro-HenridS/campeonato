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
    int vitorias = 0, 
    int empates = 0, 
    int derrotas = 0,
    int gols_marcados = 0,
    int gols_sofridos = 0){

    Time* buffer = (Time*)malloc(sizeof(Time));

    if(buffer == NULL){
        printf("Erro ao alocar Time");
        return 1;
    }

    buffer->nome;
    buffer->vitorias;
    buffer->empates;
    buffer->derrotas;
    buffer->gols_marcados;
    buffer->gols_sofridos;


}

#endif