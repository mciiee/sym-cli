#include <stddef.h>
#include <string.h>

#include "sym-table.h"

const char * lookupSymbol(const char *name) {
    for (size_t i = 0; i < sizeof(symbolTable)/sizeof(symbolTable[0]); i++) {
        if (strncmp(name, symbolTable[i].name, 16) == 0) {
            return symbolTable[i].symbol;
        }
    }
    return nullptr; // not found
}
