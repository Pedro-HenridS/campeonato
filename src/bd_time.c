#include "bd_time.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

BDTimes* bd_times_cria(const char* nome_arquivo);



int bd_times_busca_por_prefixo(const BDTimes* bd, const char* prefixo, Time* resultados[]) {
    int count = 0;
    size_t len_prefixo = strlen(prefixo);

    for (int i = 0; i < NUM_TIMES; i++) {
        if (bd->times[i] && strncasecmp_c99(bd->times[i]->nome, prefixo, len_prefixo) == 0) {
            resultados[count++] = bd->times[i];
        }
    }
    return count;
}