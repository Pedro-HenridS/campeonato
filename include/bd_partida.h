#ifndef BD_PARTIDAS_H
#define BD_PARTIDAS_H

#include <bd_time.h>
#include "partida.h"

#define MAX_PARTIDAS 90

typedef struct BDPartidas{

    Partida * partidas;

}BDPartidas;

BDPartidas* bd_partidas_cria();

void bd_partidas_libera(BDPartidas* bd);

void bd_partidas_consulta(
    const BDPartidas* bd, 
    const BDTimes* bd_times, 
    const char* prefixo, 
    int modo);

#endif