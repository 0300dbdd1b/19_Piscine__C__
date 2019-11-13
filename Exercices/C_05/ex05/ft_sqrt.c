/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:46:15 by naddino           #+#    #+#             */
/*   Updated: 2019/11/06 14:15:51 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	long int	overage;
	int			left_lim;
	int			right_lim;

	left_lim = 0;
	right_lim = nb / 2;
	if (nb == 4)
		return (2);
	else if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	while (left_lim + 1 < right_lim)
	{
		overage = (left_lim + right_lim) / 2;
		if ((overage * overage) == nb)
			return (overage);
		else if ((overage * overage) > nb)
			right_lim = overage;
		else if ((overage * overage) < nb)
			left_lim = overage;
	}
	return (0);
}
