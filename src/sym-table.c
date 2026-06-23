#include <stddef.h>
#include <string.h>

#include "sym-table.h"


const char * lookupSymbol(const char *name) {
    for (size_t i = 0; i < sizeof(symbolTableEntries)/sizeof(symbolTableEntries[0]); i++) {
        if (strncmp(name, symbolTableEntries[i].name, 16) == 0) {
            return symbolTableEntries[i].symbol;
        }
    }
    return nullptr; // not found
}
