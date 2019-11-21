/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:58:22 by naddino           #+#    #+#             */
/*   Updated: 2019/11/20 17:16:41 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_BOOLEAN_H
# define _FT_BOOLEAN_H
# define TRUE 1
# define FALSE 0
# define EVEN_MSG "I have an even number of arguments.\n"
# define EVEN(nbr) (nbr % 2) == 0
# define ODD_MSG "I have an odd number of arguments.\n"
# define SUCCESS 1
# include <unistd.h>

typedef int		t_bool;

#endif
