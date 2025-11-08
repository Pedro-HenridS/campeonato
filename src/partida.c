#include "partida.h"
#include <stdlib.h>
#include <stdio.h>
#include <partida.h>
#include "../include/handle_partidas_csv.h"

Partida* partida_cria(int id, int time1_id, int time2_id, int gols_time1, int gols_time2) {
    Partida* nova_partida = (Partida*) malloc(sizeof(Partida));
    if (nova_partida == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }
    nova_partida->id = id;
    nova_partida->time1_id = time1_id;
    nova_partida->time2_id = time2_id;
    nova_partida->gols_time1 = gols_time1;
    nova_partida->gols_time2 = gols_time2;
    return nova_partida;

    
};

void partida_libera(Partida* p){
    free(p);
};

void partida_processa_resultado(const Partida* p, BDTimes* bd_times){
    
};

void partida_imprime_detalhes(const Partida* p, const BDTimes* bd_times){
  return p;  
};
