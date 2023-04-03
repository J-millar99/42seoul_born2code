/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:17:58 by jaehyji           #+#    #+#             */
/*   Updated: 2023/03/26 18:03:37 by jaehyji          ###   ########.fr       */
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
		free(optr);
		return (rstr);
	}
	rstr = ft_strdup(*backup);
	fptr(backup);
	return (rstr);
}

char	*read_file(int fd, char **backup, char **buff)
{
	ssize_t		rbyte;
	char		*tptr;

	rbyte = BUFFER_SIZE;
	while (!ft_strchr(*backup, '\n') && rbyte)
	{
		rbyte = read(fd, *buff, BUFFER_SIZE);
		if (rbyte < 0)
		{
			fptr(backup);
			return (NULL);
		}
		(*buff)[rbyte] = '\0';
		tptr = *backup;
		*backup = ft_strjoin(*backup, *buff);
		free(tptr);
	}
	if (*backup == NULL)
		return (NULL);
	if (!**backup)
	{
		fptr(backup);
		return (NULL);
	}
	return (make_line(&(*backup)));
}

char	*get_next_line(int fd)
{
	static char		*backup;
	char			*buff;
	char			*rstr;

	if (BUFFER_SIZE < 1 || OPEN_MAX < fd || fd < 2)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	if (backup == NULL)
	{
		backup = ft_strdup("\0");
		if (backup == NULL)
		{
			free(buff);
			return (NULL);
		}
	}
	rstr = read_file(fd, &backup, &buff);
	free(buff);
	return (rstr);
}
