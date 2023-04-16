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

typedef struct s_print
{
	va_list	vlist;
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

/*				main				*/
int			ft_printf(const char *format, ...);
void		init_flags(t_print *print_info);
int			type_num(char *type, char sp);
const char	*set_flags(t_print *print_info, const char *f);
const char	*handle_width(t_print *print_info, const char *f);

/*				padding				*/
void		padding(t_print *print_info, int occupied_len);
void		zero_padding(t_print *ps, int max, int min);

/*				type_c				*/
void		type_c(t_print *print_info);

/*				type_s				*/
void		type_s(t_print	*ps);
void		type_ston(t_print *ps, char *null);

/*				type_d				*/
void		type_d(t_print *print_info);

/*				type_i				*/
void		type_i(t_print *print_info);

/*				type_u				*/
void		type_u(t_print *ps);
void		type_u_nminus(t_print *ps, int nb_len, unsigned int nb);
void		type_u_minus(t_print *ps, int nb_len, unsigned int nb);
void		type_u_zero(t_print *ps);

/*				type_p				*/
void		type_p(t_print *ps);
void		type_pton(t_print *ps, char *nil);

/*				type_x				*/
void		type_lower_x(t_print *ps);
void		type_x_zero(t_print *ps);

/*				type_X				*/
void		type_upper_x(t_print *ps);

/*				type_%				*/
void		type_percent(t_print *ps);

/*				libft				*/
int			ft_putchar_fd(char c, int fd);
ssize_t		ft_putstr_fd(char *s, int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
void		*ft_memcpy(void *dst, const void *src, size_t n);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *str, unsigned int start, size_t len);

/*				utlis				*/
size_t		ft_unbrlen_base(unsigned long n, unsigned int base);
void		ft_put_unbr_base_fd(unsigned long n, char *base, int fd);
void		ft_putnbr_base_fd(long n, char *base, int fd);
static int	flag_unbr_len_base(t_print *ps, unsigned int nb, unsigned int base);
void		unbr_left_padding(t_print *ps, int nb_len, unsigned int nb);

#endif