/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:47:09 by naddino           #+#    #+#             */
/*   Updated: 2019/11/12 21:42:12 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int x;

	x = 0;
	while (str[x])
	{
		x++;
	}
	return (x);
}

int		ft_check_base(char *base)
{
	int x;
	int i;

	i = 0;
	x = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[x])
	{
		i = x + 1;
		while (base[i])
		{
			if (base[x] == base[i] || base[x] == '+' || base[x] == '-'
					|| base[x] < 33 | base[x] == 127)
				return (0);
			i++;
		}
		x++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long i;

	i = nbr;
	if (ft_check_base(base) == 1)
	{
		if (i < 0)
		{
			ft_putchar('-');
			i = i * (-1);
		}
		if (i >= ft_strlen(base))
		{
			ft_putnbr_base(i / ft_strlen(base), base);
			ft_putnbr_base(i % ft_strlen(base), base);
		}
		else
			ft_putchar(base[i]);
	}
}
