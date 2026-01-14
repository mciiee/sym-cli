#include <stdio.h>

#include <string.h>

#include "sym.h"

typedef struct SymbolEntry {
    const char *name;
    const char *symbol;
} SymbolEntry;

// A table of O(n) lookup time, but it's small enough, so...
static const SymbolEntry symbolTable[] = {
    { "alpha",   SYM_ALPHA_LOWERCASE },
    { "beta",    SYM_BETA_LOWERCASE },
    { "gamma",   SYM_GAMMA_LOWERCASE },
    { "delta",   SYM_DELTA_LOWERCASE },
    { "epsilon", SYM_EPSILON_LOWERCASE },
    { "zeta",    SYM_ZETA_LOWERCASE },
    { "eta",     SYM_ETA_LOWERCASE },
    { "theta",   SYM_THETA_LOWERCASE },
    { "iota",    SYM_IOTA_LOWERCASE },
    { "kappa",   SYM_KAPPA_LOWERCASE },
    { "lambda",  SYM_LAMBDA_LOWERCASE },
    { "mu",      SYM_MU_LOWERCASE },
    { "nu",      SYM_NU_LOWERCASE },
    { "xi",      SYM_XI_LOWERCASE },
    { "omicron", SYM_OMICRON_LOWERCASE },
    { "pi",      SYM_PI_LOWERCASE },
    { "rho",     SYM_RHO_LOWERCASE },
    { "sigma",   SYM_SIGMA_LOWERCASE },
    { "sigma_final", SYM_SIGMA_FINAL },
    { "tau",     SYM_TAU_LOWERCASE },
    { "upsilon", SYM_UPSILON_LOWERCASE },
    { "phi",     SYM_PHI_LOWERCASE },
    { "chi",     SYM_CHI_LOWERCASE },
    { "psi",     SYM_PSI_LOWERCASE },
    { "omega",   SYM_OMEGA_LOWERCASE },

    { "Alpha",   SYM_ALPHA_UPPERCASE },
    { "Beta",    SYM_BETA_UPPERCASE },
    { "Gamma",   SYM_GAMMA_UPPERCASE },
    { "Delta",   SYM_DELTA_UPPERCASE },
    { "Epsilon", SYM_EPSILON_UPPERCASE },
    { "Zeta",    SYM_ZETA_UPPERCASE },
    { "Eta",     SYM_ETA_UPPERCASE },
    { "Theta",   SYM_THETA_UPPERCASE },
    { "Iota",    SYM_IOTA_UPPERCASE },
    { "Kappa",   SYM_KAPPA_UPPERCASE },
    { "Lambda",  SYM_LAMBDA_UPPERCASE },
    { "Mu",      SYM_MU_UPPERCASE },
    { "Nu",      SYM_NU_UPPERCASE },
    { "Xi",      SYM_XI_UPPERCASE },
    { "Omicron", SYM_OMICRON_UPPERCASE },
    { "Pi",      SYM_PI_UPPERCASE },
    { "Rho",     SYM_RHO_UPPERCASE },
    { "Sigma",   SYM_SIGMA_UPPERCASE },
    { "Tau",     SYM_TAU_UPPERCASE },
    { "Upsilon", SYM_UPSILON_UPPERCASE },
    { "Phi",     SYM_PHI_UPPERCASE },
    { "Chi",     SYM_CHI_UPPERCASE },
    { "Psi",     SYM_PSI_UPPERCASE },
    { "Omega",   SYM_OMEGA_UPPERCASE },

    { "forall", SYM_FORALL },
    { "exists", SYM_EXISTS },
    { "not", SYM_NEGATION },

    { "and", SYM_CONJUNCTION },
    { "or", SYM_DISJUNCTION },
};

const char * lookupSymbol(const char *name) {
    for (size_t i = 0; i < sizeof(symbolTable)/sizeof(symbolTable[0]); i++) {
        if (strncmp(name, symbolTable[i].name, 16) == 0) {
            return symbolTable[i].symbol;
        }
    }
    return nullptr; // not found
}


int main(int argc, char **argv) {
    if (argc <= 0) {
        fprintf(stderr, "[Error] No symbols given");
        return -1;
    }
    (void)argc;
    (void)argv;
    const char *sym = nullptr;
    for (size_t i = 1; i < (size_t)argc ; i++) {
        sym = lookupSymbol(argv[i]);
        if (sym == nullptr) {
            fprintf(stderr, "[Error] \"%s\" is not a valid symbol\n", argv[i]);
            continue;
        }
        printf("%s\n", sym);
    }

    return 0;
}
