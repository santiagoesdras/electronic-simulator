// backend.c
#include "names.h"

const char* names[] = {
    "Keneth",
    "Ulysses",
    "Esdras",
    "Herobrine"  // Marcador de fin
};

const char** getNames() {
    return names;
}

