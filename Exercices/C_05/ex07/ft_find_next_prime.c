/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:42:57 by naddino           #+#    #+#             */
/*   Updated: 2019/11/07 15:16:46 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_find_next_prime(int nb)
{
	int x;

	x = 13;
	if (nb <= 1)
		return (2);
	else if (nb == 2 || nb == 3 || nb == 5 || nb == 7 || nb == 11)
		return (nb);
	else if (nb % 3 == 0 || nb % 5 == 0 || nb % 7 == 0 || nb % 11 == 0)
		return (ft_find_next_prime(nb + 1));
	else
	{
		while (x < nb)
		{
			if (nb % x == 0)
				return (ft_find_next_prime(nb + 1));
			x = x + 2;
		}
		return (nb);
	}
}
