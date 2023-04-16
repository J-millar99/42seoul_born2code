/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 02:00:54 by jaehyji           #+#    #+#             */
/*   Updated: 2023/03/26 02:00:54 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# define LLONG_MAX 9223372036854775807LL

int		ft_isdigit(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *str, unsigned int start, size_t len);
int		ft_atoi(const char *str);
int		ft_putchar_fd(char c, int fd);
ssize_t	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif