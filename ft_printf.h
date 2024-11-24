#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include "libft/libft.h"
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>
#define HEX_BASE "0123456789ABCDEF"
#define hex_base "0123456789abcdef"
#define dec_base "0123456789"

typedef struct format_flags    {
    int space;
    int hash;
    int plus;
    int left_justify;
    int zero;
    int precision;
    int total_width;
} flags;

int ft_printf(const char *, ...);
#endif