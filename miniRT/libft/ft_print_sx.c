/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gibkim <gibkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:30:04 by gibkim            #+#    #+#             */
/*   Updated: 2023/04/12 19:00:03 by gibkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static char	*ft_bufadd_front(char *buf, char *str, int prec)
{
	char	*tempbuf;
	char	*newbuf;

	if (buf == NULL || str == NULL)
		return (ft_nullguard(buf, str));
	if (!ft_strncmp(buf, "0x", 2) && prec && *buf)
		tempbuf = ft_strjoin("0x", str);
	else
	{
		tempbuf = ft_strdup(str);
		prec = 0;
	}
	if (tempbuf)
		newbuf = ft_strjoin(tempbuf, buf + prec);
	free(buf);
	free(str);
	if (tempbuf == NULL)
		return (NULL);
	free(tempbuf);
	return (newbuf);
}

static char	*ft_add_buf(char *buf, t_printf_flag flag)
{
	if (buf == NULL)
		return (NULL);
	if (flag.hash)
		buf = ft_bufadd_front(buf, ft_strdup("0x"), 0);
	if (flag.zero && (flag.width > (int)ft_strlen(buf)))
		buf = ft_bufadd_front(buf,
				ft_addlen_str('0', flag.width - (int)ft_strlen(buf), buf), 2);
	if (flag.precision + flag.hash * 2 > (int)ft_strlen(buf))
		buf = ft_bufadd_front(buf, ft_addlen_str('0',
					flag.precision + flag.hash * 2
					- (int)ft_strlen(buf), buf), 2);
	if ((flag.width > (int)ft_strlen(buf)) && !flag.hyphen)
		buf = ft_bufadd_front(buf, ft_addlen_str(' ',
					flag.width - (int)ft_strlen(buf), buf), 0);
	if ((flag.width > (int)ft_strlen(buf)) && flag.hyphen)
		buf = ft_bufadd_back(buf, ft_addlen_str(' ',
					flag.width - (int)ft_strlen(buf), buf));
	return (buf);
}

int	ft_print_sx_bonus(const char *fmt, unsigned int num)
{
	t_printf_flag	flag;
	char			*buf;
	int				byte;

	ft_memset(&flag, 0, sizeof(t_printf_flag));
	flag = ft_setflag(fmt, flag);
	if (flag.space || flag.plus)
		return (-1);
	if (flag.zero && (flag.hyphen || flag.precision >= 0))
		flag.zero = 0;
	if (!num)
		flag.hash = 0;
	buf = ft_sizetohex(num, 0);
	if (!flag.precision && !num)
	{
		free(buf);
		buf = (char *)ft_calloc(sizeof(char), 1);
	}
	buf = ft_add_buf(buf, flag);
	byte = write (1, buf, ft_strlen(buf));
	free(buf);
	return (byte);
}
