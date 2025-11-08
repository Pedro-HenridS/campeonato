#include "..\include\bd_partida.h"
#include "..\include\handle_partidas_csv.h"
#include "..\include\handle_times_csv.h"
#include "..\include\time.h"
#include "..\include\find_index.h"

#include <stdlib.h>
#define MAX_TIMES 10

BDPartidas* criar_bd_partidas(){

    BDPartidas * buffer = (BDPartidas *) malloc(sizeof(BDPartidas));

    if(buffer == NULL) return NULL;

    buffer->partidas = pegar_partidas();

    return buffer;
};

void bd_partidas_consulta(const BDPartidas* bd, const char* prefixo, int modo) {
    int encontrou = 0;
    Time *allTimes = get_times(); 

    printf("\n");
    for (int i = 0; i < MAX_PARTIDAS; i++) {
        int id1 = bd->partidas[i].time1_id;
        int id2 = bd->partidas[i].time2_id;

        char *name1 = NULL, *name2 = NULL;

        for (int j = 0; j < MAX_TIMES; j++) {
            if (allTimes[j].id == id1) name1 = allTimes[j].nome;
            if (allTimes[j].id == id2) name2 = allTimes[j].nome;
        }

        if (!name1 || !name2) continue;

        int match1 = (findIndex(prefixo, name1) == 0);
        int match2 = (findIndex(prefixo, name2) == 0);

        if ((modo == 1 && match1) || 
            (modo == 2 && match2) || 
            (modo == 3 && (match1 || match2))) {

            printf("Partida (%d) - %s X %s (%d x %d)\n",
                bd->partidas[i].id, name1, name2,
                bd->partidas[i].gols_time1, bd->partidas[i].gols_time2);

            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("========================================\n");
        printf("Nenhum registro de partida encontrado!\n");
        printf("========================================\n\n");
    }
}


