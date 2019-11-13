/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:25:54 by naddino           #+#    #+#             */
/*   Updated: 2019/11/11 13:20:22 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int x;
	int size;

	x = 0;
	if (min >= max)
		return (0);
	size = max - min;
	if (size > 0)
		*range = malloc(sizeof(int) * size);
	if (*range == NULL)
		return (-1);
	while (x < max)
	{
		(*range)[x] = min + x;
		x++;
	}
	return (*range[0]);
}
