/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:39:18 by jaehyji           #+#    #+#             */
/*   Updated: 2023/07/14 15:38:41 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_substr_gnl(char const *str, unsigned int start, size_t len);
char	*ft_strdup_gnl(const char *s1);
void	*ft_memcpy_gnl(void *dst, const void *src, size_t n);
char	*ft_strchr_gnl(const char *s, int c);

#endif