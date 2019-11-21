/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:47:09 by naddino           #+#    #+#             */
/*   Updated: 2019/11/13 18:36:26 by naddino          ###   ########.fr       */
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
	if (!base || !base[0] || !base[1])
		return (0);
	while (base[i + 1])
	{
		x = i + 1;
		while (base[x])
		{
			if (base[i] == base[x])
				return (0);
			x++;
		}
		i++;
	}
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	return (x);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	i;

	i = nbr;
	if (ft_check_base(base) != 0)
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
			ft_putchar(base[i % ft_strlen(base)]);
	}
}
