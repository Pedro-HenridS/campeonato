#ifndef BD_PARTIDAS_H
#define BD_PARTIDAS_H

#include "partida.h"
#include "bd_times.h"
#define MAX_PARTIDAS 90

typedef struct bd_partidas {
    Partida* partidas[MAX_PARTIDAS]; 
    int num_partidas;
} BDPartidas;   
