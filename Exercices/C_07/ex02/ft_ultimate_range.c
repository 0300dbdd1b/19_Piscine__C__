/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:25:54 by naddino           #+#    #+#             */
/*   Updated: 2019/11/18 21:35:25 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		j;
	int		*tab;

	j = min;
	i = 0;
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	if (!(tab = malloc(sizeof(int) * (max - min))))
		return (-1);
	while (j < max)
	{
		tab[i] = j;
		j++;
		i++;
	}
	*range = tab;
	return (max - min);
}
