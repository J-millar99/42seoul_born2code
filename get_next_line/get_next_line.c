/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:39:13 by jaehyji           #+#    #+#             */
/*   Updated: 2023/06/22 20:48:07 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	fptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*make_line(char **backup)
{
	size_t	i;
	char	*optr;
	char	*rstr;

	i = 0;
	if (ft_strchr(*backup, '\n'))
	{
		while ((*backup)[i] != '\n')
			++i;
		optr = *backup;
		rstr = ft_substr(optr, 0, i + 1);
		*backup = ft_strdup(*backup + i + 1);
		if (!*backup && rstr)
			fptr(&rstr);
		if (!rstr)
			fptr(backup);
		free(optr);
		return (rstr);
	}
	rstr = ft_strdup(*backup);
	fptr(backup);
	return (rstr);
}

char	*read_file(int fd, char **backup, char **buff)
{
	ssize_t	rbyte;
	char	*tptr;

	rbyte = 1;
	while (!ft_strchr(*backup, '\n') && rbyte > 0)
	{
		rbyte = read(fd, *buff, BUFFER_SIZE);
		if (rbyte == -1)
		{
			fptr(backup);
			return (0);
		}
		(*buff)[rbyte] = '\0';
		tptr = *backup;
		*backup = ft_strjoin(*backup, *buff);
		free(tptr);
		if (!*backup)
			return (0);
	}
	if (!**backup)
	{
		fptr(backup);
		return (0);
	}
	return (make_line(&(*backup)));
}

char	*get_next_line(int fd)
{
	static char		*backup;
	char			*buff;
	char			*result;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	if (!backup)
	{
		backup = ft_strdup("");
		if (!backup)
		{
			free(buff);
			return (0);
		}
	}
	result = read_file(fd, &backup, &buff);
	free(buff);
	return (result);
}
