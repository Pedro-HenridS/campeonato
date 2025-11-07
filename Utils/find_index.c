#include <string.h>
#include "../include/find_index.h"

int findIndex(const char *index, const char *base){

    char *resultado = strstr(base, index);

    if(resultado == NULL)
        return 1;

    return 0;
}