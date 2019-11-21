/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:24:51 by naddino           #+#    #+#             */
/*   Updated: 2019/11/14 18:47:24 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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
		if (base[i] == '-' || base[i] == '+' || base[i] == ' ')
			return (0);
		i++;
	}
	return (x);
}

int		ft_search_index(char index, char *base)
{
	int x;

	x = 0;
	while (base[x])
	{
		if (index == base[x])
			return (x);
		x++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	long int	neg;
	long int	nb;
	long int	x;

	neg = 1;
	x = 0;
	nb = 0;
	if (ft_check_base(base) != 0)
	{
		while (str[x] == '\t' || str[x] == '\v' || str[x] == '\n'
				|| str[x] == '\r' || str[x] == '\f' || str[x] == ' ')
			x++;
		while (str[x] == '-' || str[x] == '+')
		{
			if (str[x++] == '-')
				neg *= (-1);
		}
		while (str[x] && ft_search_index(str[x], base) != -1)
			nb = nb * ft_strlen(base) + ft_search_index(str[x++], base);
		nb *= neg;
		return ((int)nb);
	}
	return (0);
}

int main(void)
{
	char str[] = "40302";
	char base[] = "01234	87";
	printf("%d", ft_atoi_base(str, base));
}
