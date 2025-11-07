#include <partida.h>

Partida* partida_criar(int id, int time1_id, int time2_id, int gols_time1, int gols_time2){

    Partida* buffer = (Partida*)malloc(sizeof(Partida));

    buffer -> id;
    buffer -> time1_id;
    buffer -> time2_id;
    buffer -> gols_time1;
    buffer -> gols_time2;

    return buffer;
};

void partida_libera(Partida* p){
    free(p);
};

void partida_processa_resultado(const Partida* p, BDTimes* bd_times){
    
};

void partida_imprime_detalhes(const Partida* p, const BDTimes* bd_times);
