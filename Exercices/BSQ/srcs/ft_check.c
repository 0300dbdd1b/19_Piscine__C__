/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:41:54 by escarrie          #+#    #+#             */
/*   Updated: 2019/11/20 12:43:57 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

int		ft_check_char_not_same(t_map *map)
{
	int i;

	i = ft_strlen(map->board[0]) - 3;
	if (map->board[0][i] == map->board[0][i + 1] ||
		map->board[0][i] == map->board[0][i + 2])
	{
		ft_putstr_error("map error\n");
		return (1);
	}
	if (map->board[0][i + 1] == map->board[0][i + 2])
	{
		ft_putstr_error("map error\n");
		return (1);
	}
	return (0);
}

int		ft_check_char_main(t_map *map)
{
	int size;

	size = ft_strlen(map->board[0]);
	if (size < 4)
	{
		ft_putstr_error("map error\n");
		return (1);
	}
	if (ft_check_char_not_same(map))
		return (1);
	map->s = (char *)malloc(sizeof(char) * 4);
	map->s = ft_get_char_map(map->board[0], map->s);
	return (0);
}

int		ft_check_nb_ligne(t_map *map)
{
	int i;
	int nb;

	nb = ft_get_nb_ligne_map(map->board[0]);
	if (nb <= 0)
	{
		ft_putstr_error("map error\n");
		return (1);
	}
	i = 0;
	while (map->board[i])
		i++;
	if (nb != i - 1)
	{
		ft_putstr_error("map error\n");
		return (1);
	}
	map->nb_l = nb;
	return (0);
}

int		ft_check_nb_char(t_map *map)
{
	int i;
	int nb;

	i = 1;
	nb = ft_strlen(map->board[1]);
	while (map->board[++i])
		if (ft_strlen(map->board[i]) != nb)
		{
			ft_putstr_error("map error\n");
			return (1);
		}
	map->nb_char = nb;
	return (0);
}

int		ft_check_main(t_map *map)
{
	if (ft_check_char_main(map))
		return (1);
	if (ft_check_nb_ligne(map))
		return (1);
	if (ft_check_nb_char(map))
		return (1);
	if (ft_check_board(map))
		return (1);
	return (0);
}
