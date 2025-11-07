#ifndef BD_PARTIDAS_H
#define BD_PARTIDAS_H

#include <bd_time.h>

typedef struct BDPartidas{

}BDPartidas;

BDPartidas* bd_partidas_cria(const char* nome_arquivo, BDTimes* bd_times);

void bd_partidas_libera(BDPartidas* bd);

void bd_partidas_consulta(
    const BDPartidas* bd, 
    const BDTimes* bd_times, 
    const char* prefixo, 
    int modo);

#endif