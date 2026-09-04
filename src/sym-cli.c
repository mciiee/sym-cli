#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "sym-table.h"
#include "log.h"
#include "opts.h"

struct CliOpts opts = {
  .sep = "\n",
  .mode = CLI_MODE_CHAR
};

int parseCliArgs(int argc, char *argv[], struct CliOpts *opts) {
  for (int c = getopt(argc, argv, "::ms:"); c != -1; c = getopt(argc, argv, "::ms:")) {
    switch (c) {
      case 's':
        opts->sep = optarg;
        break;
      case 'm':
        printf("Option 'm' with optarg: \"%s\"\n", optarg);
        if (strcmp(optarg, "text") == 0) {
          opts->mode = CLI_MODE_TEXT;
        }
        else if (strcmp(optarg, "char") == 0) {
          opts->mode = CLI_MODE_CHAR;
        }
        else {
          LOG_ERROR("Invalid mode: \"%s\", valid options are: \"text\", \"char\"\n", optarg);
        }
        break;
      case '?':
        LOG_ERROR("Unknown option: %c\n", c);
        break;
      default:
        printf("?? getopt returned character code 0%o ??\n", c);
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
      printf("%s", argv[i]);
      continue;
    }
    if (i != (size_t)start) {
      fputs(opts.sep, stdout);
    }
    printf("%s", sym);
  }

  return 0;
}
