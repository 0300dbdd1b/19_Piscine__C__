/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:24:51 by naddino           #+#    #+#             */
/*   Updated: 2019/11/12 19:10:02 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
					|| base[x] == ' ')
				return (0);
			i++;
		}
		x++;
	}
	return (1);
}

int		ft_search_index(char index, char *base)
{
	int x;

	x = 0;
	while (index != base[x])
	{
		x++;
	}
	return (x);
}

int		ft_atoi_base(char *str, char *base)
{
	int neg;
	int nb;
	int x;

	neg = 1;
	x = 0;
	nb = 0;
	if (ft_check_base(base) == 1)
	{
		while (str[x] == '-' || str[x] == '+')
		{
			if (str[x] == '-')
				neg *= (-1);
			x++;
		}
		while (str[x])
		{
			nb = nb * ft_strlen(base) + ft_search_index(str[x], base);
			x++;
		}
		nb *= neg;
		return (nb);
	}
	return (0);
}
