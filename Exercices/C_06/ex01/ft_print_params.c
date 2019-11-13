/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:25:36 by naddino           #+#    #+#             */
/*   Updated: 2019/11/05 13:01:43 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_params(char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
	{
		write(1, &str[x], 1);
		x++;
	}
}

int		main(int argc, char **argv)
{
	int x;

	(void)argc;
	x = 1;
	while (argv[x])
	{
		ft_print_params(argv[x]);
		write(1, "\n", 1);
		x++;
	}
	return (0);
}
