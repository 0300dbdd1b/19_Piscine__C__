/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:38:49 by shenquin          #+#    #+#             */
/*   Updated: 2019/11/19 11:39:09 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

int					space_charset(char c)
{
	if (c == '\n')
		return (1);
	return (0);
}

void				ft_strcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

unsigned int		count_words(char *str)
{
	unsigned int i;
	unsigned int words_count;
	unsigned int len_words;

	words_count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && space_charset(str[i]))
			i++;
		len_words = 0;
		while (str[i + len_words] && !space_charset(str[i + len_words]))
			len_words++;
		if (len_words)
			words_count++;
		i += len_words;
	}
	return (words_count);
}

char				**fill(char **tab, char *str, unsigned int words_count)
{
	unsigned int len_words;
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (str[j] && space_charset(str[j]))
			j++;
		len_words = 0;
		while (str[j + len_words] && !space_charset(str[j + len_words]))
			len_words++;
		tab[i] = malloc(sizeof(char) * (len_words + 1));
		if (!tab[i])
			return (NULL);
		ft_strcpy(tab[i], &str[j], len_words);
		j += len_words;
		i++;
	}
	return (tab);
}

char				**ft_split(char *str)
{
	char			**tab;
	unsigned int	words_count;

	words_count = count_words(str);
	tab = malloc(sizeof(char*) * (words_count + 1));
	if (!tab)
		return (NULL);
	tab = fill(tab, str, words_count);
	tab[words_count] = 0;
	return (tab);
}
