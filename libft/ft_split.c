/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyji <jaehyji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:36:27 by jaji              #+#    #+#             */
/*   Updated: 2023/03/25 02:56:41 by jaehyji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

static int	word_count(const char *s, char c)
{
	int		cnt;

	cnt = 0;
	while (*s)
	{
		while (is_sep(*s, c) && *s != '\0')
			s++;
		if (!is_sep(*s, c) && *s != '\0')
			cnt++;
		while (!is_sep(*s, c) && *s != '\0')
			s++;
	}
	return (cnt);
}

static char	*word_block(char const *pstr, char c, unsigned int *start)
{
	char	*word;
	int		len;

	len = 0;
	while (pstr[*start])
	{
		while (is_sep(pstr[*start], c) && pstr[*start] != '\0')
			(*start)++;
		while (!is_sep(pstr[*start], c) && pstr[*start] != '\0')
		{
			len++;
			(*start)++;
		}
		word = ft_substr(pstr, *start - len, len);
		if (word == NULL)
			return (NULL);
		return (word);
	}
	return (NULL);
}

static void	free_word_arr(char **word_arr, int idx)
{
	while (idx >= 0)
	{
		free(word_arr[idx]);
		word_arr[idx] = NULL;
		idx--;
	}
	free(word_arr);
	word_arr = NULL;
}

char	**ft_split(char const *s, char c)
{
	char			**word_arr;
	int				idx;
	int				word_cnt;
	unsigned int	start;

	word_cnt = word_count(s, c);
	word_arr = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (word_arr == NULL)
		return (NULL);
	idx = 0;
	start = 0;
	while (idx < word_cnt)
	{
		word_arr[idx] = word_block(s, c, &start);
		if (word_arr[idx] == NULL)
		{
			free_word_arr(word_arr, idx);
			return (NULL);
		}
		++idx;
	}
	word_arr[idx] = NULL;
	return (word_arr);
}
