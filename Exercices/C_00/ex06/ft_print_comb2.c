/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:35:22 by naddino           #+#    #+#             */
/*   Updated: 2019/10/31 16:59:46 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_decomp(int i, int j)
{
	char a;
	char b;
	char c;
	char d;

	a = i / 10 + '0';
	b = i % 10 + '0';
	c = j / 10 + '0';
	d = j % 10 + '0';
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (i != 98)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	b = 1;
	while (a <= 99)
	{
		while (b <= 99)
		{
			ft_decomp(a, b);
			b++;
		}
		a++;
		b = a + 1;
	}
}
