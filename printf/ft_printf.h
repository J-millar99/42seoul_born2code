/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:03:19 by jaehyji           #+#    #+#             */
/*   Updated: 2023/04/08 00:03:19 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const char *s);
void	p_char(va_list *vlist);
void	p_str(va_list *vlist);
void	p_pointer(va_list *vlist);
void	p_decimal(va_list *vlist);
void	p_unsigned(va_list *vlist);
void	p_hex(va_list *vlist);
void	p_capital_hex(va_list *vlist);
void	p_percent_sign(va_list *vlist);

#endif
