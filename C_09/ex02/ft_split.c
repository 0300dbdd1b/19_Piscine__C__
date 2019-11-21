/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:28:05 by naddino           #+#    #+#             */
/*   Updated: 2019/11/20 18:40:30 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int					space_charset(char c, char *charset)
{
	int				x;

	x = 0;
	while (charset[x])
	{
		if (c == charset[x])
			return (1);
		x++;
	}
	return (0);
}

void				ft_strcpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

unsigned int		count_words(char *str, char *charset)
{
	unsigned int	i;
	unsigned int	words_count;
	unsigned int	len;

	words_count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && space_charset(str[i], charset))
			i++;
		len = 0;
		while (str[i + len] && !space_charset(str[i + len], charset))
			len++;
		if (len)
			words_count++;
		i += len;
	}
	return (words_count);
}

char				**fill(char **tb, char *str, unsigned int count, char *set)
{
	unsigned int	len;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < count)
	{
		while (str[j] && space_charset(str[j], set))
			j++;
		len = 0;
		while (str[j + len] && !space_charset(str[j + len], set))
			len++;
		tb[i] = malloc(sizeof(char) * (len + 1));
		if (!tb[i])
			return (NULL);
		ft_strcpy(tb[i], &str[j], len);
		j += len;
		i++;
	}
	return (tb);
}

char				**ft_split(char *str, char *charset)
{
	char			**tab;
	unsigned int	words_count;

	words_count = count_words(str, charset);
	tab = malloc(sizeof(char*) * (words_count + 1));
	if (!tab)
		return (NULL);
	tab = fill(tab, str, words_count, charset);
	tab[words_count] = 0;
	return (tab);
}
