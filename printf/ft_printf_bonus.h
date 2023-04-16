/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:46:55 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/15 17:46:55 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "libft.h"
# include <stdarg.h>

# define TYPE "cspdiuxX%"
# define DECI "0123456789"
# define HEXA "0123456789abcdef"
# define UPHX "0123456789ABCDEF"

typedef struct	s_print
{
	va_list vlist;
	int		plen;
	int		space;
	int		hash;
	int		minus;
	int		plus;
	int		zero;
	int		dot;
	int		precision;
	int		width;
}	t_print;

typedef void	(*t_type_ptr)(t_print *print_struct);

int			ft_printf(const char *format, ...);
const char	*set_flags(t_print *print_Info, const char *f);
void		init_flags(t_print *print_Info);
const char	*handle_width(t_print *print_Info, const char *f);
int			check_type(t_print *print_Info, const char sp);
int			type_num(char *type, char sp);

void		type_c(t_print *print_Info);
void		type_s(t_print *print_Info);
void		type_p(t_print *print_Info);
void		type_d(t_print *print_Info);
void		type_i(t_print *print_Info);
void		type_u(t_print *print_Info);
void		type_lower_x(t_print *ps);
void		type_upper_x(t_print *ps);
void		type_percent(t_print *ps);

int			unbrlen_base(unsigned long n, unsigned int base);
void		ft_putptr_base_fd(unsigned long n, char *base, int fd);
void		ft_putnbr_base_fd(long n, char *base, int fd);
void		print_int(t_print *ps, long n, int nlen);
ssize_t		nbrlen_base(long n, unsigned int base);
int			flag_unbr_len_base(t_print *ps, unsigned int nb, unsigned int base);


void		padding(t_print *print_Info, int occupied_len);
void		middle_padding(t_print *pI, int nb_len, unsigned int nb);
void		zero_padding(t_print *print_Info, int nb_len);
void		int_left_padding(t_print *ps, int n, int nlen);
void		int_right_padding(t_print *ps, long n, int nlen);
void		unbr_left_padding(t_print *ps, int nb_len, unsigned int nb);

char		*ft_strchr(const char *s, int c);
int			ft_isdigit(int c);
int			ft_putchar_fd(char c, int fd);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *str, unsigned int start, size_t len);
ssize_t		ft_putstr_fd(char *s, int fd);
#endif