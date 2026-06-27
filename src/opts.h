#ifndef OPTS_H
#define OPTS_H

#include <stdint.h>

enum CliFlags : uint8_t {
  CLI_FLAG_NO_FLAGS = 0,
};

struct CliOpts {
  // enum CliFlags flags;
  char *sep;
};

#endif
