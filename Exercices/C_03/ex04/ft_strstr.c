/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 17:51:40 by naddino           #+#    #+#             */
/*   Updated: 2019/11/03 18:13:47 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int a;
	int i;

	a = 0;
	i = 0;
	if (to_find == 0 || to_find[0] == '\0')
		return (str);
	if (str == 0)
		return (0);
	while (str[i])
	{
		while (str[i + a] == to_find[a])
		{
			a++;
			if (to_find[a] == '\0')
				return (&str[i]);
		}
		a = 0;
		i++;
	}
	return (0);
}
