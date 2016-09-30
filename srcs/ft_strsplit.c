/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:08:40 by ofedorov          #+#    #+#             */
/*   Updated: 2016/09/30 15:10:12 by ofedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int		i;
	int		n;

	n = 0;
	if (s[0] == '\0')
		return (0);
	if (s[0] != c)
		n++;
	i = 1;
	while (s[i])
	{
		if (s[i] != c && s[i] != '\0' && s[i - 1] == c)
			n++;
		i++;
	}
	return (n);
}

static void	fill_arr(char **strings, char const *s, char c, int words)
{
	int		i;
	char	*end_word;

	i = -1;
	while (++i < words)
	{
		if ((end_word = ft_strchr(s, c)) != NULL)
			strings[i] = ft_strsub(s, 0, end_word - s);
		else
			strings[i] = ft_strdup(s);
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	strings[words] = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**strings;
	int		words;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	strings = (char **)malloc(sizeof(char *) * (words + 1));
	if (!strings)
		return (NULL);
	while (*s == c)
		s++;
	fill_arr(strings, s, c, words);
	return (strings);
}
