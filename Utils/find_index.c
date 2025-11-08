#include <string.h>
#include "../include/find_index.h"

int findIndex(const char *index, const char *base) {
    size_t len = strlen(index);

    if (strncmp(base, index, len) == 0)
        return 0;

    return 1;
}
