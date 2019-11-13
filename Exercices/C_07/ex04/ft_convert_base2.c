/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:18:57 by naddino           #+#    #+#             */
/*   Updated: 2019/11/12 19:28:23 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int x;

	x =			0;
	while (str[x] != '\0')
	{
		x++;
	}
	return (x);
}

char	*ft_strcpy	(char *dest, char *src)
{
	int x;

	x = 0;
	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char *dest;

	if (src)
	{
		dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
		ft_strcpy(dest, src);
	}
	return (dest);
}
