#ifndef BD_TIME_H
#define BD_TIME_H

#include "../include/time.h"

#define MAX_PARTIDAS 90
#define MAX_TIMES 10

typedef struct BDTimes {
    Time *times;
    int qtd;
    int cap;
} BDTimes;

BDTimes* criar_bd_times();

void bd_times_libera(BDTimes* bd);

Time* bd_times_busca_por_id(const BDTimes* bd, int id);

void get_result(BDTimes* bd);

void bd_times_imprime_tabela(const BDTimes* bd);

#endif