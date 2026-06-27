#ifndef SYM_TABLE_H
#define SYM_TABLE_H

#include <stddef.h>
#include "sym.h"

typedef struct SymbolEntry {
  const char *name;
  const char *symbol;
} SymbolEntry;

typedef struct SymbolTable {
  const size_t size;
  const SymbolEntry *const entries;
} SymbolTable;

static const SymbolEntry symbolTableEntries[] = {
  {"alpha", SYM_ALPHA_LOWERCASE},
  {"beta", SYM_BETA_LOWERCASE},
  {"gamma", SYM_GAMMA_LOWERCASE},
  {"delta", SYM_DELTA_LOWERCASE},
  {"epsilon", SYM_EPSILON_LOWERCASE},
  {"zeta", SYM_ZETA_LOWERCASE},
  {"eta", SYM_ETA_LOWERCASE},
  {"theta", SYM_THETA_LOWERCASE},
  {"iota", SYM_IOTA_LOWERCASE},
  {"kappa", SYM_KAPPA_LOWERCASE},
  {"lambda", SYM_LAMBDA_LOWERCASE},
  {"mu", SYM_MU_LOWERCASE},
  {"nu", SYM_NU_LOWERCASE},
  {"xi", SYM_XI_LOWERCASE},
  {"omicron", SYM_OMICRON_LOWERCASE},
  {"pi", SYM_PI_LOWERCASE},
  {"rho", SYM_RHO_LOWERCASE},
  {"sigma", SYM_SIGMA_LOWERCASE},
  {"sigma_final", SYM_SIGMA_FINAL},
  {"tau", SYM_TAU_LOWERCASE},
  {"upsilon", SYM_UPSILON_LOWERCASE},
  {"phi", SYM_PHI_LOWERCASE},
  {"chi", SYM_CHI_LOWERCASE},
  {"psi", SYM_PSI_LOWERCASE},
  {"omega", SYM_OMEGA_LOWERCASE},

  {"Alpha", SYM_ALPHA_UPPERCASE},
  {"Beta", SYM_BETA_UPPERCASE},
  {"Gamma", SYM_GAMMA_UPPERCASE},
  {"Delta", SYM_DELTA_UPPERCASE},
  {"Epsilon", SYM_EPSILON_UPPERCASE},
  {"Zeta", SYM_ZETA_UPPERCASE},
  {"Eta", SYM_ETA_UPPERCASE},
  {"Theta", SYM_THETA_UPPERCASE},
  {"Iota", SYM_IOTA_UPPERCASE},
  {"Kappa", SYM_KAPPA_UPPERCASE},
  {"Lambda", SYM_LAMBDA_UPPERCASE},
  {"Mu", SYM_MU_UPPERCASE},
  {"Nu", SYM_NU_UPPERCASE},
  {"Xi", SYM_XI_UPPERCASE},
  {"Omicron", SYM_OMICRON_UPPERCASE},
  {"Pi", SYM_PI_UPPERCASE},
  {"Rho", SYM_RHO_UPPERCASE},
  {"Sigma", SYM_SIGMA_UPPERCASE},
  {"Tau", SYM_TAU_UPPERCASE},
  {"Upsilon", SYM_UPSILON_UPPERCASE},
  {"Phi", SYM_PHI_UPPERCASE},
  {"Chi", SYM_CHI_UPPERCASE},
  {"Psi", SYM_PSI_UPPERCASE},
  {"Omega", SYM_OMEGA_UPPERCASE},

  {"in", SYM_ELEMENT_OF},

  {"forall", SYM_FORALL},
  {"exists", SYM_EXISTS},
  {"not", SYM_NEGATION},
  {"implies", SYM_ARROW_DOUBLE_RIGHT},

  {"and", SYM_CONJUNCTION},
  {"or", SYM_DISJUNCTION},

  {"And", SYM_CONJUNCTION_BIG},
  {"Or", SYM_DISJUNCTION_BIG},

  {"rarrow", SYM_ARROW_RIGHT},
  {"uarrow", SYM_ARROW_UP},
  {"larrow", SYM_ARROW_LEFT},
  {"darrow", SYM_ARROW_DOWN},

  {"rdarrow", SYM_ARROW_DOUBLE_RIGHT},
  {"udarrow", SYM_ARROW_DOUBLE_UP},
  {"ldarrow", SYM_ARROW_DOUBLE_LEFT},
  {"ddarrow", SYM_ARROW_DOUBLE_DOWN},

  {"->", SYM_ARROW_RIGHT},
  {"<-", SYM_ARROW_LEFT},

  {"=>", SYM_ARROW_DOUBLE_RIGHT},
  {"<=", SYM_ARROW_DOUBLE_LEFT},
};

const static SymbolTable table = {
  .size = sizeof(symbolTableEntries) / sizeof(symbolTableEntries[0]),
  .entries = (const SymbolEntry *const)symbolTableEntries,
};

const char *lookupSymbol(const char *name);

#endif
