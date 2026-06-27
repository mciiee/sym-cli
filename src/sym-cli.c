#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "sym-table.h"

#include "log.h"




int main(int argc, char **argv) {
  if (argc <= 0) {
    LOG_ERROR("No symbols given");
    return -1;
  }
  const char *sym = nullptr;
  for (size_t i = 1; i < (size_t)argc; i++) {
    sym = lookupSymbol(argv[i]);
    if (sym == nullptr) {
      fprintf(stderr, ERROR_PREFIX "\"%s\" is not a valid symbol\n", argv[i]);
      continue;
    }
    printf("%s\n", sym);
  }

  return 0;
}
