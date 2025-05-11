// backend.c
#include "names.h"

const char* names[] = {
    "Ana",
    "Bruno",
    "Carlos",
    "Diana"  // Marcador de fin
};

const char** get_names() {
    return names;
}

