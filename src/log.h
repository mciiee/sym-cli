#ifndef LOG_H
#define LOG_H

#ifndef ERROR_PREFIX
#define ERROR_PREFIX "[Error] "
#endif

#ifndef ERROR_PREFIX
#define ERROR_PREFIX "[ERROR] "
#endif

#ifndef LOG_PREFIX
#define LOG_PREFIX "[LOG] "
#endif

// clang-format off
#ifndef LOG_PRINT
#define LOG_PRINT(templ, ...) printf(LOG_PREFIX templ __VA_OPT__(,) __VA_ARGS__)
#endif
// clang-format on

// clang-format off
#ifndef LOG_ERROR
#define LOG_ERROR(templ, ...) fprintf(stderr, ERROR_PREFIX templ __VA_OPT__(,) __VA_ARGS__)
#endif
// clang-format on

#endif
