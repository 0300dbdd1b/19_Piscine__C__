/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 20:33:29 by naddino           #+#    #+#             */
/*   Updated: 2019/11/13 20:36:26 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char str[])
{
	int x;

	x = 0;
	while (str	[x])
	{
		write(1, &str[x], 1);
		x++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int x;

	x = 0;
	while (s1[x] && s2[x] && s1[x] == s2[x])
	{
		x++;
	}
	return (s1[x] - s2[x]);
}

void	sw(char **str1, char **str2)
{
	char *s;

	s = *str1;
	*str1 = *str2;
	*str2 = s;
}

int		main(int argc, char **argv)
{
	int x;
	int y;

	(void)argc;
	x = 1;
	while (argv[x])
	{
		y = 1;
		while (argv[y + 1])
		{
			if (ft_strcmp(argv[y], argv[y + 1]) > 0)
				sw(&argv[y], &argv[y + 1]);
			y++;
		}
		x++;
	}
	x = 1;
	while (argv[x])
	{
		ft_putstr(argv[x]);
		write(1, "\n", 1);
		x++;
	}
	return (0);
}
