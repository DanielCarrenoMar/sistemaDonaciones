#ifndef _COLORAMA_H_
#define _COLORAMA_H_

#ifdef _WIN32
void just_fix_windows_console();
#include "Colorama.c"
#endif

#define s_RESET_ALL "\x1b[0m"
#define s_BRIGHT    "\x1b[1m"
#define s_DIM       "\x1b[2m"
#define s_NORMAL    "\x1b[22m"

#define f_BLACK "\x1b[30m"
#define f_RED "\x1b[31m"
#define f_GREEN "\x1b[32m"
#define f_YELLOW "\x1b[33m"
#define f_BLUE "\x1b[34m"
#define f_MAGENTA "\x1b[35m"
#define f_CYAN "\x1b[36m"
#define f_WHITE "\x1b[37m"
#define f_LBLACK "\x1b[90m"
#define f_LRED "\x1b[91m"
#define f_LGREEN "\x1b[92m"
#define f_LYELLOW "\x1b[93m"
#define f_LBLUE "\x1b[94m"
#define f_LMAGENTA "\x1b[95m"
#define f_LCYAN "\x1b[96m"
#define f_LWHITE "\x1b[97m"

#define b_BLACK "\x1b[40m"
#define b_RED "\x1b[41m"
#define b_GREEN "\x1b[42m"
#define b_YELLOW "\x1b[43m"
#define b_BLUE "\x1b[44m"
#define b_MAGENTA "\x1b[45m"
#define b_CYAN "\x1b[46m"
#define b_WHITE "\x1b[47m"
#define b_LBLACK "\x1b[100m"
#define b_LRED "\x1b[101m"
#define b_LGREEN "\x1b[102m"
#define b_LYELLOW "\x1b[103m"
#define b_LBLUE "\x1b[104m"
#define b_LMAGENTA "\x1b[105m"
#define b_LCYAN "\x1b[106m"
#define b_LWHITE "\x1b[107m"

#endif