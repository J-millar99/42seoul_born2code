/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:03:19 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/19 02:45:14 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		p_conversion_specifier(va_list vlist, const char c_s);
size_t	ft_strlen(const char *s);
int		p_char(int c);
int		check_decimal_len(int n);
void	print_decimal_num(int num);
int		p_decimal(int num);
int		check_hex_len(unsigned int num);
void	print_lowercase_hex_num(unsigned int num);
void	print_uppercase_hex_num(unsigned int num);
int		p_hex(unsigned int num, const char c_s);
int		check_pointer_len(unsigned long n);
void	print_pointer(unsigned long num);
int		p_pointer(void *pointer);
int		p_str(char *str);
int		check_unsigned_len(unsigned int num);
void	print_unsigned_num(unsigned int num);
int		p_unsigned(unsigned int num);

#endif
