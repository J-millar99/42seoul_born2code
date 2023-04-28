/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:03:19 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/29 03:20:37 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# define TYPE "cspdiuxX%"

typedef int	(*t_ptr)(va_list vlist);

/*      ft_printf       */
int		ft_printf(const char *format, ...);
int		check_sp(va_list vlist, const char c);
int		type_num(char *type, char sp);

/*      cs      */
int		type_c(va_list vlist);
int		type_s(va_list vlist);
int		type_percent(void);

/*      p       */
int		type_p(va_list vlist);
void	print_pointer(unsigned long num);

/*      diu     */
int		type_d(va_list vlist);
void	print_decimal_num_positive(int num);
void	print_decimal_num_negative(int num);
int		type_i(va_list vlist);
int		type_u(va_list vlist);
void	print_unsigned_num(unsigned int num);

/*      xX      */
int		type_lx(va_list vlist);
int		type_ux(va_list vlist);
void	print_lowercase_hex_num(unsigned int num);
void	print_uppercase_hex_num(unsigned int num);

/*      utils       */
int		check_unsigned_long_len(unsigned long n);
int		check_unsigned_int_len(unsigned int num, int baselen);
int		check_int_len(int n);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

#endif