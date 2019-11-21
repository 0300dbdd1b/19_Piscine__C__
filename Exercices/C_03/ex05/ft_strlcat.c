/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:03:35 by naddino           #+#    #+#             */
/*   Updated: 2019/11/20 13:57:24 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int l;
	unsigned int j;

	i = 0;
	l = 0;
	j = 0;
	while (src[l] != '\0')
		l++;
	while (dest[i])
		i++;
	if (size <= i)
		l = l + size;
	else
		l = l + i;
	while (i + 1 < size && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (l);
}
