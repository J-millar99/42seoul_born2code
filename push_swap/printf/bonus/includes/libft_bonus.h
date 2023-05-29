/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:47:45 by jaehyji           #+#    #+#             */
/*   Updated: 2023/05/24 13:13:25 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# define FT_INT_MAX 2147483647
# define FT_INT_MIN 2147483648

int		ft_isdigit(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *str, unsigned int start, size_t len);
int		ft_atoi(const char *str);
int		ft_putchar_fd(char c, int fd);
ssize_t	ft_putstr_fd(char *s, int fd);
int		ft_atoi_flag(const char *str, int *flag);

#endif