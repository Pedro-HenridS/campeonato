#ifndef PARTIDAS_H
#define PARTIDAS_H

#include <bd_time.h>

typedef struct Partida{
    int id;
    int time1_id;
    int time2_id;
    int gols_time1;
    int gols_time2;

} Partida;

Partida* partida_criar(int id, int time1_id, int time2_id, int gols_time1, int gols_time2);

void partida_libera(Partida* p);

void partida_processa_resultado(const Partida* p, BDTimes* bd_times);

void partida_imprime_detalhes(const Partida* p, const BDTimes* bd_times);

#endif