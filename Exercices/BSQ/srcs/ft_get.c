/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:39:18 by escarrie          #+#    #+#             */
/*   Updated: 2019/11/20 13:39:22 by escarrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

char		*ft_get_char_map(char *str_from, char *str_to)
{
	int j;
	int i;

	i = ft_strlen(str_from) - 3;
	j = 0;
	while (j < 3)
	{
		str_to[j] = str_from[i];
		j++;
		i++;
	}
	return (str_to);
}

int			ft_get_nb_ligne_map(char *str)
{
	char temp[ft_strlen(str) - 3];

	ft_strcpy(temp, str, ft_strlen(str) - 3);
	return (ft_atoi(temp));
}

int			ft_get_nb_char_map(char *str)
{
	return (ft_strlen(str));
}
