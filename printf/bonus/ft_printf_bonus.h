/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 02:32:46 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/11 02:32:46 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		p_conversion_specifier(va_list vlist, const char c_s);
int		p_char(int c);
size_t	ft_strlen(const char *s);
int		check_decimal_len(int n);
void	print_decimal_num(int num);
int		p_decimal(int num);
int		check_hex_len(int num);
void	print_lowercase_hex_num(unsigned int num);
void	print_uppercase_hex_num(unsigned int num);
int		p_hex(unsigned int num, const char c_s);
int		check_pointer_len(unsigned long long n);
void	print_pointer(unsigned long long num);
int		p_pointer(unsigned long long num);
int		p_str(char *str);
int		check_unsigned_len(unsigned int num);
void	print_unsigned_num(unsigned int num);
int		p_unsigned(unsigned int num);
int		is_flag(const char flag);

#endif
