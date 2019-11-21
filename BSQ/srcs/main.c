/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:53:44 by naddino           #+#    #+#             */
/*   Updated: 2019/11/20 12:56:34 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"

void	ft_print_answer(t_map map)
{
	int x;

	x = 1;
	while (map.board[x])
	{
		ft_putstr(map.board[x]);
		ft_putstr("\n");
		x++;
	}
}

void	ft_main_arg(int argc, char **argv)
{
	int		i;
	int		error;
	t_map	map;

	i = 1;
	while (i < argc)
	{
		error = 0;
		map.board = ft_get_file(argv[i]);
		if (map.board == NULL)
			error++;
		if (!error && ft_check_main(&map))
			error++;
		if (!error)
			ft_bsq(1, map);
		if (!error)
			ft_print_answer(map);
		if (map.board != NULL)
			ft_free_all(&map);
		if (i < argc - 1)
			ft_putstr("\n");
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc >= 2)
		ft_main_arg(argc, argv);
	return (0);
}
