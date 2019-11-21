/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:41:54 by escarrie          #+#    #+#             */
/*   Updated: 2019/11/20 12:43:57 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_BSQ_H
# define _FT_BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_map_i
{
	char	*s;
	int		nb_l;
	int		nb_char;
	char	**board;
}				t_map;

typedef struct	s_square_i
{
	int		m_s;
	int		m_y;
	int		m_x;
}				t_squa;

typedef struct	s_vector
{
	int			x;
	int			y;
}				t_vec;

char			*ft_read_stock(char *filepath);
long int		ft_get_file_len(char *filepath);
char			*ft_file_to_str(char *filepath, long long int file_len);
char			**ft_get_file(char *filepath);

int				ft_atoi(char *str);
int				ft_is_space(char c);

void			ft_free_all(t_map *map);
void			ft_putstr(char *str);
void			ft_putstr_error(char *str);
int				ft_strlen(char *str);
int				ft_get_max_y(char **board);

char			*ft_get_char_map(char *str_from, char *str_to);
int				ft_get_nb_ligne_map(char *str);
int				ft_get_nb_char_map(char *str);

int				space_charset(char c);
void			ft_strcpy(char *dest, char *src, unsigned int n);
unsigned int	count_words(char *str);
char			**ft_fill(char **tab, char *str, unsigned int words_count);
char			**ft_split(char *str);

int				ft_find_square_size(t_vec coord, t_map map);
int				ft_check_empty(t_map map, t_vec stop, t_vec *pos, t_vec coord);
int				ft_find_square(char **board, int y, int x, char vide);
void			ft_maj(t_squa carr, t_map map);
void			ft_bsq(int y, t_map map);

int				ft_check_char_main(t_map *map);
int				ft_check_nb_ligne(t_map *map);
int				ft_check_nb_char(t_map *map);
int				ft_check_main(t_map *map);

int				ft_check_board(t_map *map);
int				ft_check_empty_line(char *str);

#endif
