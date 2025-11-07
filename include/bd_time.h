#ifndef BD_TIME_H
#define BD_TIME_H

#include "../include/time.h"
#define NUM_TIMES 10

typedef struct BDTimes{
    Time* times[NUM_TIMES];
}BDTimes;

BDTimes* bd_times_cria(const char* nome_arquivo);

void bd_times_libera(BDTimes* bd);

Time* bd_times_busca_por_id(const BDTimes* bd, int id);

int bd_times_busca_por_prefixo(const BDTimes* bd, const char* prefixo, Time* resultados[]);

void bd_times_imprime_tabela(const BDTimes* bd);

#endif