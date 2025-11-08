#include "partida.h"
#include "bd_time.h"
#define MAX_PARTIDAS 90
#include "..\include\bd_partida.h"
#include "..\include\handle_partidas_csv.h"
#include "..\include\handle_times_csv.h"
#include "..\include\time.h"
#include "..\include\find_index.h"

#include <stdlib.h>
#include <bd_partida.h>
#define MAX_TIMES 10

BDPartidas* criar_bd_partidas(){

    BDPartidas * buffer = (BDPartidas *) malloc(sizeof(BDPartidas));

    if(buffer == NULL) return NULL;

    buffer->partidas = pegar_partidas();

    return buffer;
};



void bd_partidas_consulta(
    const BDPartidas* bd, 
    const char* prefixo, 
    int modo){

    Time *allTimes = get_times(); 
    int moddooo = modo;

    for (int i = 0; i < MAX_PARTIDAS; i++) {

        char *name1 = NULL, *name2 = NULL;

        int timeId1 = bd->partidas[i].time1_id;
        int timeId2 = bd->partidas[i].time2_id;

        for (int j = 0; j < MAX_TIMES; j++) {
            if (timeId1 == allTimes[j].id)
                name1 = allTimes[j].nome;
            if (timeId2 == allTimes[j].id)
                name2 = allTimes[j].nome;
        }

        if(name1 && findIndex(prefixo, name1) == 0){
            printf("Partida (%d) - %s X %s (%d x %d)\n",
                bd->partidas[i].id, name1, name2,
                bd->partidas[i].gols_time1, bd->partidas[i].gols_time2);
        } 
    }

};

