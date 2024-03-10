/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:04:18 by dhorvath          #+#    #+#             */
/*   Updated: 2023/11/27 16:43:44 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_new_sub(const char *s, int start, int len, char **res);
static void	fix_my_code(char **res);

static int	count_words(char const *s, char c)
{
	int	words;
	int	i;
	int	old_i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while ((char)s[i] == c && s[i])
			i++;
		old_i = i;
		while ((char)s[i] != c && s[i])
			i++;
		if (i != old_i)
			words++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		old_i;
	int		c_word;
	char	**res;

	if (!s)
		return (0);
	c_word = 0;
	res = ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!res)
		return ((char **) 0);
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		old_i = i;
		while (s[i] != c && s[i])
			i++;
		if (i != old_i)
			res[c_word++] = ft_new_sub(s, old_i, i - old_i, res);
		if (!res[c_word - 1])
			break ;
	}
	return (res);
}

static char	*ft_new_sub(const char *s, int start, int len, char **lst)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(len * sizeof(char) + 1);
	if (!res)
	{
		fix_my_code(lst);
		return (0);
	}
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[len] = 0;
	return (res);
}

static void	fix_my_code(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
}
