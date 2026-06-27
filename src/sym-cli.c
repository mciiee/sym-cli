#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "sym-table.h"
#include "log.h"
#include "opts.h"

struct CliOpts opts = {
  .sep = "\n",
};

int parseCliArgs(int argc, char *argv[], struct CliOpts *opts) {
  for (int c = getopt(argc, argv, "::s:"); c != -1; c = getopt(argc, argv, "::s:")) {
    switch (c) {
      case 's':
        opts->sep = optarg;
        break;
      case '?':
        LOG_ERROR("Unknown option: %c\n", c);
        break;
    }
  }
  return optind;
}

int main(int argc, char **argv) {
  if (argc <= 0) {
    LOG_ERROR("No symbols given");
    return -1;
  }

  int start = parseCliArgs(argc, argv, &opts);

  const char *sym = nullptr;
  for (size_t i = (size_t)start; i < (size_t)argc; i++) {
    sym = lookupSymbol(argv[i]);
    if (sym == nullptr) {
      fprintf(stderr, ERROR_PREFIX "\"%s\" is not a valid symbol\n", argv[i]);
      continue;
    }
    if (i != (size_t)start) {
      fputs(opts.sep, stdout);
    }
    printf("%s", sym);
  }

  return 0;
}
