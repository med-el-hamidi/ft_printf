#include "ft_printf.h"

static int _ft_output_length_cntl(int flag);
static int _is_in_set(char c, char *set);
static void _skip_flags_and_digits(char **str, flags *flag);
static int _ft_printf_fd(va_list args, const char *str, const int fd);

int ft_printf(const char *str, ...)
{
    va_list args;

    va_start(args, str);
    _ft_output_length_cntl(0);
    _ft_printf_fd(args, str, 1);
    va_end(args);
    return (_ft_output_length_cntl(-2));
}

static int _ft_output_length_cntl(int flag)
{
    static int   output_length;

    if (!flag)
        output_length = 0;
    else if (flag > 0)
        output_length += flag;
    else if (flag == -1)
        output_length = -1;
    return(output_length);
}

static int _is_in_set(char c, char *set)
{
    while (*set)
    {
        if (c == *set)
            return (1);
        set++;
    }
    return (0);
}

static void _skip_flags_and_digits(char **str, flags *flag)
{
    while (++(*str) && (_is_in_set(**str, " #+-0.") || ft_isdigit(**str)))
    {
        if (ft_isdigit(**str) && !_is_in_set(**str, " #+-0."))
        {
            if (flag->precision && (!flag->space || flag->space == -1))
            {
                flag->precision = ft_atoi(*str);
                *str += (ft_nbrlen_base(flag->precision, 10) - 1);
                if (flag->space)
                    flag->space = 1;
            }
            else
            {
                flag->total_width = ft_atoi(*str);
                *str += (ft_nbrlen_base(flag->total_width, 10) - 1);
            }
            if (flag->precision >= 2147483646 || flag->total_width  >= 2147483647)
                break;
            continue;
        }
        if (**str == ' ')
            flag->space = 1;
        else if (**str == '#')
            flag->hash = 2;
        else if (**str == '+')
            flag->plus = 1;
        else if (**str == '-')
        {
            flag->left_justify = 1;
            flag->precision = 0;
            flag->zero = 0;
        }
        else if (**str == '0' && *(*str - 1) != '.')
            flag->zero = 1;
        else if (**str == '.')
        {
            flag->precision = 1;
            flag->zero = 0;
            if (ft_isdigit(*(*str + 1)) && !_is_in_set(*(*str + 1), " #+-0."))
            {
                if (flag->space)
                    flag->space = -1;
            }
            while (*(*str + 1) == '0')
                (*str)++;
            if ((!ft_isdigit(*(*str + 1)) && !_is_in_set(*(*str + 1), " #+-0.")))
                flag->precision = -1;
        }
    }
}

static void _ft_print_char_fd(char c, flags *flag, int fd)
{
     _ft_output_length_cntl(1);
    if (flag->total_width > 1)
    {
        _ft_output_length_cntl(--flag->total_width);
        if (flag->left_justify)
            ft_putchar_fd(c, fd);
        while(flag->total_width--)
            ft_putchar_fd(' ', fd);
        if (!flag->left_justify)
            ft_putchar_fd(c, fd);
    }
    else
        ft_putchar_fd(c, fd);
}

static void _ft_putlstr_fd(char *str, int length, int fd)
{
    if (length <= 0)
        return ;
    while (*str && length--)
        ft_putchar_fd(*str++, fd);
}

static void _ft_putlchar_fd(char c, int length, int fd)
{
    if (length <= 0)
        return ;
    while (length--)
        ft_putchar_fd(c, fd);
}

static void _ft_putl_zero_or_space_fd(int zero, int length, int fd)
{
    if (zero)
        _ft_putlchar_fd('0', length, fd);
    else
        _ft_putlchar_fd(' ', length, fd);
}

static void _ft_print_str_fd(flags *flag, char *str, int length, int fd)
{
    if (length > 0)
        _ft_output_length_cntl(length);
    if (flag->total_width > length)
    {
        flag->total_width -= length;
        _ft_output_length_cntl(flag->total_width);
        if (flag->left_justify)
        {
            _ft_putlstr_fd(str, length, fd);
            _ft_putlchar_fd(' ', flag->total_width, fd);
        }
        else
        {
            _ft_putl_zero_or_space_fd(flag->zero, flag->total_width, fd);
            _ft_putlstr_fd(str, length, fd);
        }
    }
    else
        _ft_putlstr_fd(str, length, fd);
}

static void _ft_print_string_fd(flags *flag, char *str, int fd)
{
    int length;

    length = 6;
    if(str)
        length = (int)ft_strlen(str);
    if (flag->precision && (flag->precision < length || flag->space))
    {
        if (flag->precision == -1)
            length = 0;
        else
            length = flag->precision;
    }
    if (str)
        _ft_print_str_fd(flag, str, length, fd);
    else
        _ft_print_str_fd(flag, "(null)", length, fd);
}

static void _update_output_length_by_precision(int *length, flags *flag)
{
    if (flag->precision > *length)
    {
        flag->precision -= *length;
        *length += flag->precision;
    }
    else if(flag->precision)
        flag->precision = -1;
}

static void _ft_print_ptr_precision_fd(int precision, uintptr_t format_address, int fd)
{
    ft_putstr_fd("0x", fd);
    if (precision > 1)
        _ft_putlchar_fd('0', precision, fd);
    ft_putptr_fd(format_address, fd);
}

static void _ft_print_ptr_fd(flags *flag, uintptr_t format_address, int fd)
{
    int length;

    length = ft_ptrlen(format_address);
    _update_output_length_by_precision(&length, flag);
    length += 2;// for 0x
    _ft_output_length_cntl(length);
    if (flag->total_width > length)
    {
        flag->total_width -= length;
        _ft_output_length_cntl(flag->total_width);
        if (flag->left_justify)
            _ft_print_ptr_precision_fd(flag->precision, format_address, fd);
        _ft_putlchar_fd(' ', flag->total_width, fd);
        if (!flag->left_justify)
            _ft_print_ptr_precision_fd(flag->precision, format_address, fd);
    }
    else
        _ft_print_ptr_precision_fd(flag->precision, format_address, fd);
}

static void _print_decimal_plus_fd(flags *flag, ssize_t nbr, int fd)
{
    // TODO: need to be fixed
    if(flag->plus && nbr >= 0)
        ft_putchar_fd('+', fd);
    else if (nbr < 0)
        ft_putchar_fd('-', fd);
}

static void _print_decimal_precision_fd(flags *flag, ssize_t nbr, int fd)
{
    if (flag->precision > 0)
        _ft_putlchar_fd('0', flag->precision, fd);
    if (nbr > 0 || (nbr == 0 && !flag->precision && flag->precision != -1))
        ft_putnbr_base_fd(nbr, dec_base, fd);
    else if (nbr < 0)
        ft_putnbr_base_fd((nbr * -1), dec_base, fd);
}

static void _print_decimal_plus_and_precision_fd(flags *flag, ssize_t nbr, int fd)
{
    _print_decimal_plus_fd(flag, nbr, fd);
    _print_decimal_precision_fd(flag, nbr, fd);
}

static void _update_output_length_by_0(int *length, flags *flag, ssize_t nbr)
{
    if (nbr == 0 && flag->precision)
        *length = 0;
}

static void _update_output_length_by_nbr(int *length, flags *flag, ssize_t nbr, int fd)
{
    if (nbr < 0)
    {
        flag->plus = 1;
        (*length)--;
    }
    _update_output_length_by_0(length, flag, nbr);
    if (flag->space && !flag->plus)
        ft_putchar_fd(' ', fd);
    else if (flag->plus)
        flag->space = 0;
}

static void _ft_print_decimal_fd(flags *flag, ssize_t nbr, int fd)
{
    int length;

    length = ft_nbrlen_base(nbr, 10);
    _update_output_length_by_nbr(&length, flag, nbr, fd);
    _update_output_length_by_precision(&length, flag);
    length += (flag->space + flag->plus);//for + and if there is (space and no -)
    _ft_output_length_cntl(length);
    if (flag->total_width > length)
    {
        flag->total_width -= length;
        _ft_output_length_cntl(flag->total_width);
        if (!flag->left_justify && flag->zero)
            _print_decimal_plus_fd(flag, nbr, fd);
        if (flag->left_justify)
            _print_decimal_plus_and_precision_fd(flag, nbr, fd);
        _ft_putl_zero_or_space_fd(flag->zero, flag->total_width, fd);
        if (!flag->left_justify)
        {
            if (!flag->zero)
                _print_decimal_plus_fd(flag, nbr, fd);
            _print_decimal_precision_fd(flag, nbr, fd);
        }
    }
    else
        _print_decimal_plus_and_precision_fd(flag, nbr, fd);
}

static void _print_hex_hash_fd(flags *flag, char x, ssize_t nbr, int fd)
{
    if (nbr != 0)
    {
        if (x == 'x')
        {
            if (flag->hash)
                ft_putstr_fd("0x", fd);
        }
        else
        {
            if (flag->hash)
                ft_putstr_fd("0X", fd);
        }
    }
}

static void _print_hex_precision_fd(flags *flag, char x, ssize_t nbr, int fd)
{
    if (flag->precision > 0)
        _ft_putlchar_fd('0', flag->precision, fd);
    if (nbr != 0 || (nbr == 0 && !flag->precision && flag->precision != -1))
    {
        if (x == 'x')
            ft_putnbr_base_fd(nbr, hex_base, fd);
        else
            ft_putnbr_base_fd(nbr, HEX_BASE, fd);
    }
}

static void _print_hex_hash_and_precision_fd(flags *flag, char x, ssize_t nbr, int fd)
{
    _print_hex_hash_fd(flag, x, nbr, fd);
    _print_hex_precision_fd(flag, x, nbr, fd);
}

static void _ft_print_hex_fd(flags *flag, char x, ssize_t nbr, int fd)
{
    int length;

    length = ft_nbrlen_base(nbr, 16);
    _update_output_length_by_0(&length, flag, nbr);
    _update_output_length_by_precision(&length, flag);
    if (nbr != 0 && nbr != LONG_MIN)
        length += flag->hash;//for + and if there is (space and no -)
    _ft_output_length_cntl(length);
    if (flag->total_width > length)
    {
        flag->total_width -= length;
        _ft_output_length_cntl(flag->total_width);
        if (!flag->left_justify && flag->zero)
            _print_hex_hash_fd(flag, x, nbr, fd);
        if (flag->left_justify)
            _print_hex_hash_and_precision_fd(flag, x, nbr, fd);
        _ft_putl_zero_or_space_fd(flag->zero, flag->total_width, fd);
        if (!flag->left_justify)
        {
            if (!flag->zero)
                _print_hex_hash_fd(flag, x, nbr, fd);
            _print_hex_precision_fd(flag, x, nbr, fd);
        }
    }
    else
        _print_hex_hash_and_precision_fd(flag, x, nbr, fd);
}

static void _ft_print_other_char_fd(flags *flag, char c, int fd)
{
    _ft_output_length_cntl(1);
    if (flag->total_width > 1 && flag->total_width < INT_MAX)
    {
        _ft_output_length_cntl(flag->total_width - 1);
        if (flag->left_justify)
            ft_putchar_fd(c, fd);
        _ft_putl_zero_or_space_fd(flag->zero, (flag->total_width - 1), fd);
        if (!flag->left_justify)
            ft_putchar_fd(c, fd);
    }
    else
        ft_putchar_fd(c, fd);
}

static void _ft_print_uint_fd(flags *flag, unsigned int nbr, int fd)
{
    flag->plus = 0;
    flag->space = 0;
    _ft_print_decimal_fd(flag, nbr, fd);
}

static void _ft_print_based_on_type_fd(va_list args, flags *flag, char c, int fd)
{
    if (c == '%')
        _ft_print_char_fd(c, flag, fd);
    else if (_is_in_set(c, "cspdiuxX"))
    {
        if (c == 'c')
                _ft_print_char_fd((char)va_arg(args, char *), flag, fd);
        else if (c == 's')
            _ft_print_string_fd(flag, va_arg(args, char *), fd);
        else if (c == 'p')
            _ft_print_ptr_fd(flag, (uintptr_t)va_arg(args, void *), fd);                 
        else if (c == 'd' || c == 'i')
            _ft_print_decimal_fd(flag, va_arg(args, int), fd);
        else if (c == 'u')
            _ft_print_uint_fd(flag, va_arg(args, unsigned int), fd);
        else if (c == 'x' || c == 'X')
            _ft_print_hex_fd(flag, c, va_arg(args, unsigned int), fd);
    }
    else if(ft_isalpha(c))
        _ft_print_other_char_fd(flag, c, fd);
}

static int _ft_printf_fd(va_list args, const char *str, const int fd)
{
    char        *tmp;
    flags       flag;

    tmp = (char *)str;
    while (*tmp)
    {
        ft_bzero(&flag, sizeof(flag));
        if (*tmp == '%')
        {
            _skip_flags_and_digits(&tmp, &flag);
            _ft_print_based_on_type_fd(args, &flag, *tmp, fd);
        }
        else
        {
            ft_putchar_fd(*tmp, fd);
            _ft_output_length_cntl(1);
        }
        tmp++;
    }
    return (_ft_output_length_cntl(-2));
}

/*
 // tmp = (char *)str;
    // while (*tmp)
    // {
    //     ft_bzero(&flag, sizeof(flag));
    //     if(*tmp == '%')
    //     {
    //         _skip_flags_and_digits(&tmp, &flag);
    //         if (*tmp == 's' && flag.total_width  >= 2147483644)
    //         {
    //             _ft_output_length_cntl(-1);
    //             return _ft_output_length_cntl(-2);
    //         }
    //         else if (*tmp && (flag.precision >= 2147483644 || flag.total_width  >= 2147483644))
    //         {
    //             _ft_output_length_cntl(-1);
    //             return _ft_output_length_cntl(-2);
    //         }
    //     }
    //     tmp++;
    // }


*/