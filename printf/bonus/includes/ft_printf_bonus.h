/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:46:55 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/19 04:31:13 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "libft_bonus.h"
# include <stdarg.h>

# define TYPE "cspdiuxX%"
# define DECI "0123456789"
# define HEXA "0123456789abcdef"
# define UPHX "0123456789ABCDEF"
# define FLAG "0123456789#+-. "

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

typedef void	(*t_type_ptr)(t_print *ps);

/*				main				*/
int			ft_printf(const char *format, ...);
void		init_flags(t_print *ps);
int			type_num(char *type, char sp);
const char	*set_flags(t_print *ps, const char *f);
const char	*handle_width(t_print *ps, const char *f);
void		check_type(t_print *ps, const char sp);
int			check_format(const char *f);
int			not_sp(const char *f);
//int			non_sp(const char *f);

/*				padding				*/
void		padding(t_print *ps, int occupied_len);
void		zero_padding(t_print *ps, int max, int min);
void		nb_zero_padding(t_print *ps);
void		sign_padding(t_print *ps, int occupied_len);

/*				type_c				*/
void		type_c(t_print *ps);

/*				type_s				*/
void		type_s(t_print	*ps);

/*				type_d				*/
void		type_d(t_print *ps);
void		type_d_minus(t_print *ps, int nb_len, int nb);
void		type_d_nminus(t_print *ps, int nb_len, int nb);
void		check_ign_flag(t_print *ps, int nb);
void		check_sign(t_print *ps, int nb);
void		type_d_nminus_dot(t_print *ps, int nb_len, int nb);
void		type_d_minus_dot(t_print *ps, int nb_len, int nb);
void		type_d_zero(t_print *ps, int nb_len, int nb);
void		d_nb_zero(t_print *ps);
void		d_nb_zero_minus(t_print *ps);

/*				type_i				*/
void		type_i(t_print *ps);

/*				type_u				*/
void		type_u(t_print *ps);
void		type_u_nminus(t_print *ps, int nb_len, unsigned int nb);
void		type_u_minus(t_print *ps, int nb_len, unsigned int nb);

/*				type_p				*/
void		type_p(t_print *ps);

/*				type_x				*/
void		type_lx(t_print *ps);
void		type_lx_hash(t_print *ps, int nb_len, unsigned int nb);
void		type_lx_hash_minus(t_print *ps, int nb_len, unsigned int nb);
void		type_lx_hash_nminus(t_print *ps, int nb_len, unsigned int nb);
void		type_lx_minus(t_print *ps, int nb_len, unsigned int nb);
void		type_lx_nminus(t_print *ps, int nb_len, unsigned int nb);
void		type_lx_hash_nminus_zero(t_print *ps, int nb_len, unsigned int nb);

/*				type_X				*/
void		type_ux(t_print *ps);
void		type_ux_hash(t_print *ps, int nb_len, unsigned int nb);
void		type_ux_hash_minus(t_print *ps, int nb_len, unsigned int nb);
void		type_ux_hash_nminus(t_print *ps, int nb_len, unsigned int nb);
void		type_ux_minus(t_print *ps, int nb_len, unsigned int nb);
void		type_ux_nminus(t_print *ps, int nb_len, unsigned int nb);
void		type_ux_hash_nminus_zero(t_print *ps, int nb_len, unsigned int nb);

/*				type_%				*/
void		type_percent(t_print *ps);

/*				utlis				*/
size_t		ft_unbrlen_base(unsigned long n, unsigned int base);
void		ft_put_unbr_base_fd(unsigned long n, char *base, int fd);
void		ft_putnbr_base_fd(long n, char *base, int fd);
int			flag_unbr_len_base(t_print *ps, unsigned int nb, unsigned int base);
int			flag_nbr_len_base(int nb, int base);
#endif
