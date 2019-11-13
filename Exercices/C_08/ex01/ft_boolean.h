/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:58:22 by naddino           #+#    #+#             */
/*   Updated: 2019/11/12 11:59:52 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# define TRUE 1
# define FALSE 0
# define ODD_MSG "I have an odd number of arguments.\n"
# define EVEN_MSG "I have an even number of arguments.\n"
# define SUCCES 0
# define EVEN(nbr) nbr % 2 ? 1 : 0

typedef int		t_bool;
void	ft_putstr(char *str);
t_bool	ft_is_even(int nbr);

#endif
