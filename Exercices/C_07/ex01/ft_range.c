/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:03:40 by naddino           #+#    #+#             */
/*   Updated: 2019/11/11 16:13:13 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_fill_tab(int *tab, int size, int min)
{
	int x;

	x = 0;
	while (x < size)
	{
		tab[x] = min + x;
		x++;
	}
	return (tab);
}

int		*ft_range(int min, int max)
{
	int size;
	int *tab;
	
	if (min >= max)
		return (NULL);
	size = max - min;
	if (size > 0)
		tab = malloc(sizeof(int) * size);
	if (tab == NULL)
		return (NULL);
	return (ft_fill_tab(tab, size, min));
}
