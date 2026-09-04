#ifndef OPTS_H
#define OPTS_H

#include <stdint.h>

enum CliFlags : uint8_t {
  CLI_FLAG_NO_FLAGS = 0,
};

enum CliMode {
  CLI_MODE_CHAR = 0,
  CLI_MODE_TEXT
};

struct CliOpts {
  // enum CliFlags flags;
  char *sep;
  enum CliMode mode;
};

#endif
