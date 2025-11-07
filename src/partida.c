#include <partida.h>
#include "../include/handle_partidas_csv.h"

Partida* partida_criar(int id, int time1_id, int time2_id, int gols_time1, int gols_time2){

    
};

void partida_libera(Partida* p){
    free(p);
};

void partida_processa_resultado(const Partida* p, BDTimes* bd_times){
    
};

void partida_imprime_detalhes(const Partida* p, const BDTimes* bd_times){
    
};
