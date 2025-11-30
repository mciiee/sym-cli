#include <stdio.h>

#include <string.h>
#include <uchar.h>
#include <wchar.h>


constexpr char SYM_ALPHA_LOWERCASE[]      = "\u03B1";
constexpr char SYM_BETA_LOWERCASE[]       = "\u03B2";
constexpr char SYM_GAMMA_LOWERCASE[]      = "\u03B3";
constexpr char SYM_DELTA_LOWERCASE[]      = "\u03B4";
constexpr char SYM_EPSILON_LOWERCASE[]    = "\u03B5";
constexpr char SYM_ZETA_LOWERCASE[]       = "\u03B6";
constexpr char SYM_ETA_LOWERCASE[]        = "\u03B7";
constexpr char SYM_THETA_LOWERCASE[]      = "\u03B8";
constexpr char SYM_IOTA_LOWERCASE[]       = "\u03B9";
constexpr char SYM_KAPPA_LOWERCASE[]      = "\u03BA";
constexpr char SYM_LAMBDA_LOWERCASE[]     = "\u03BB";
constexpr char SYM_MU_LOWERCASE[]         = "\u03BC";
constexpr char SYM_NU_LOWERCASE[]         = "\u03BD";
constexpr char SYM_XI_LOWERCASE[]         = "\u03BE";
constexpr char SYM_OMICRON_LOWERCASE[]    = "\u03BF";
constexpr char SYM_PI_LOWERCASE[]         = "\u03C0";
constexpr char SYM_RHO_LOWERCASE[]        = "\u03C1";
constexpr char SYM_SIGMA_FINAL[]          = "\u03C2";
constexpr char SYM_SIGMA_LOWERCASE[]      = "\u03C3";
constexpr char SYM_TAU_LOWERCASE[]        = "\u03C4";
constexpr char SYM_UPSILON_LOWERCASE[]    = "\u03C5";
constexpr char SYM_PHI_LOWERCASE[]        = "\u03C6";
constexpr char SYM_CHI_LOWERCASE[]        = "\u03C7";
constexpr char SYM_PSI_LOWERCASE[]        = "\u03C8";
constexpr char SYM_OMEGA_LOWERCASE[]      = "\u03C9";

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
    for (size_t i = 0; i < (size_t)argc ; i++) {
        sym = lookupSymbol(argv[i]);
        if (sym == nullptr) {
            fprintf(stderr, "[Error] \"%s\" is not a valid symbol\n", argv[i]);
            continue;
        }
        printf("%s\n", sym);
    }

    return 0;
}
