#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdint.h>
# define FD STDOUT_FILENO
# define LOW_HEX_BASE "0123456789abcdef"

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
int		ft_nbrlen_base(ssize_t n, unsigned int base);
int		ft_ptrlen(uintptr_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_base_fd(ssize_t n, char *base, int fd);
void	ft_putptr_fd(uintptr_t nbr, int fd);
#endif
