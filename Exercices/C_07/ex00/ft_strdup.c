/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:40:45 by naddino           #+#    #+#             */
/*   Updated: 2019/11/18 21:04:07 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = malloc(sizeof(*dest) * ft_strlen(src) + 1)))
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
