/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escarrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:45:08 by escarrie          #+#    #+#             */
/*   Updated: 2019/11/19 11:46:38 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_bsq.h"
#define BUFFER_SIZE 1000

long int		ft_get_file_len(char *filepath)
{
	long int			fd;
	long int			x;
	long int			file_len;
	char				buff[BUFFER_SIZE + 1];

	file_len = 0;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_error("Error Opening the File\n");
		return (0);
	}
	while ((x = read(fd, buff, BUFFER_SIZE)))
	{
		buff[x] = '\0';
		file_len = file_len + x;
	}
	if (close(fd) == -1)
	{
		ft_putstr_error("Error Closing the File\n");
		return (0);
	}
	return (file_len);
}

char			*ft_file_to_str(char *filepath, long long int file_len)
{
	long int		fd;
	long int		x;
	char			*output;

	output = malloc(sizeof(char) * file_len);
	if (!output)
		return (NULL);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_error("Error Opening the File\n");
		return (0);
	}
	while ((x = read(fd, output, file_len)))
		output[file_len] = '\0';
	if (close(fd) == -1)
		ft_putstr_error("Error Closing the File\n");
	if (ft_check_empty_line(output))
	{
		ft_putstr_error("map error\n");
		return (NULL);
	}
	return (output);
}

char			**ft_get_file(char *filepath)
{
	long long int	file_len;
	char			*file_in_str;
	char			**board;

	file_len = ft_get_file_len(filepath);
	file_in_str = ft_file_to_str(filepath, file_len);
	if (file_in_str == NULL)
		return (NULL);
	board = ft_split(file_in_str);
	free(file_in_str);
	return (board);
}
