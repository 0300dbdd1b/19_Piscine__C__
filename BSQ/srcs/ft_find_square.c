/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:57:50 by naddino           #+#    #+#             */
/*   Updated: 2019/11/20 12:54:35 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

int		ft_check_empty(t_map map, t_vec stop, t_vec *pos, t_vec coord)
{
	while (pos->y <= stop.y)
	{
		if (map.board[pos->y][pos->x] != map.s[0])
			return (0);
		pos->y++;
	}
	pos->y--;
	while (pos->x >= coord.x)
	{
		if (map.board[pos->y][pos->x] != map.s[0])
			return (0);
		pos->x--;
	}
	return (1);
}

int		ft_find_square_size(t_vec coord, t_map map)
{
	t_vec	pos;
	t_vec	stop;
	int		size;

	stop.y = coord.y + 1;
	stop.x = coord.x + 1;
	size = 1;
	if (map.board[coord.y][coord.x] != map.s[0])
		return (0);
	while (stop.x <= map.nb_char && stop.y <= map.nb_l)
	{
		pos.x = stop.x;
		pos.y = coord.y;
		if (ft_check_empty(map, stop, &pos, coord) == 0)
			return (size);
		stop.y++;
		stop.x++;
		size++;
	}
	return (size);
}

void	ft_maj(t_squa carr, t_map map)
{
	int x;
	int y;

	y = carr.m_y;
	while (y < carr.m_y + carr.m_s)
	{
		x = carr.m_x;
		while (x < carr.m_x + carr.m_s)
		{
			map.board[y][x] = map.s[2];
			x++;
		}
		y++;
	}
}

void	ft_bsq(int y, t_map map)
{
	int						i;
	struct s_square_i		carr;
	t_vec					vec;

	carr.m_s = 0;
	vec.y = y;
	while (map.board[vec.y])
	{
		vec.x = 0;
		while (map.board[vec.y][vec.x])
		{
			i = ft_find_square_size(vec, map);
			if (i > carr.m_s)
			{
				carr.m_s = i;
				carr.m_x = vec.x;
				carr.m_y = vec.y;
			}
			vec.x++;
		}
		vec.y++;
	}
	ft_maj(carr, map);
}
