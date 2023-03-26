/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:04:11 by jaehyji           #+#    #+#             */
/*   Updated: 2023/03/26 18:09:09 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*make_oneline(char **backup)
{
	int		idx;
	char	*line;
	char	*old_backup;

	idx = 0;
	while ((*backup)[idx] != '\n')
		idx++;
	old_backup = *backup;
	line = ft_substr(old_backup, 0, idx + 1);
	*backup = ft_strdup(&(*backup)[idx + 1]);
	free(old_backup);
	return (line);
}

void	free_backup(char **backup)
{
	free(*backup);
	*backup = NULL;
}

int	get_line(int fd, char **buff, char **backup)
{
	int		read_size;
	char	*old_backup;

	read_size = 1;
	while (!ft_strchr(*backup, '\n') && read_size)
	{
		read_size = read(fd, *buff, BUFFER_SIZE);
		if (read_size < 0)
			return (-1);
		(*buff)[read_size] = '\0';
		old_backup = *backup;
		*backup = ft_strjoin(old_backup, *buff);
		free(old_backup);
	}
	return (read_size);
}

char	*read_line(int fd, char **buff, char **backup)
{
	int		flag;
	char	*lastline;

	flag = get_line(fd, buff, backup);
	if (flag < 0 || !**backup)
	{
		free_backup(backup);
		return (NULL);
	}
	if (ft_strchr(*backup, '\n'))
		return (make_oneline(backup));
	lastline = ft_strdup(*backup);
	free_backup(backup);
	return (lastline);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*backup[OPEN_MAX];
	char		*buff;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	if (!backup[fd])
		backup[fd] = ft_strdup("\0");
	result = read_line(fd, &buff, &backup[fd]);
	free(buff);
	return (result);
}
