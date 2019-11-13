/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naddino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:38:08 by naddino           #+#    #+#             */
/*   Updated: 2019/11/08 14:51:47 by naddino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_is_row_col(int board[10][10], int x, int y, int boolean)
{
	int n;

	n = 0;
	while (n < 10)
	{
		if (n == x)
			n++;
		if (board[n][y] == 1 && boolean != 1)
		{
			return (-1);
		}
		else if (board[n][y] == 1 && boolean == 1)
		{
			board[n][y] = 0;
			printf("Queen Really removed in %d,%d\n", n, y);
			return (n);
		}
		n++;
	}
	n = 0;
	while (n < 10)
	{
		if (n == y)
			n++;
		if (board[x][n] == 1)
		{
			return (-1);
		}
		n++;
	}
	printf("Check Row & Col  OK\n");
	return (0);
}

int		ft_is_diag(int board[10][10], int x, int y)
{
	int pos_x;
	int pos_y;

	pos_x = x;
	pos_y = y;
	while (x != 0 && y != 0)
	{
		y--;
		x--;
	}
	while (x < 10 && y < 10)
	{
		if (x == pos_x && y == pos_y)
		{
			x++;
			y++;
		}
		if (board[x][y] == 1)
		{
			return (-1);
		}
		x++;
		y++;
	}
	printf("Check diag1 Ok\n");
	return (0);
}

int ft_is_diag2(int board[10][10], int x, int y)
{
	int pos_x;
	int pos_y;

	pos_x = x;
	pos_y = y;
	while (x < 10 && y != 0)
	{
		y--;
		x++;
	}
	while (x != 0 && y < 10)
	{
		if (x == pos_x && y == pos_y)
		{
			x--;
			y++;
		}
		if (board[x][y] == 1)
		{
			return (-1);
		}
		x--;
		y++;
	}
	printf ("Check diag2 OK\n");
	return (0);
}
int		*ft_put_queen(int board[10][10], int x, int y)
{
	int n;
	if (ft_is_row_col(board, x, y, 0) == 0 && ft_is_diag(board, x, y) == 0 && ft_is_diag2(board, x, y) == 0)
	{
		board[x][y] = 1;
		printf("Queen placed in x = %d y = %d\n", x, y);
		return (ft_put_queen(board, 0, y + 1)); // yes y + 1
	}
	else if ((ft_is_row_col(board, x, y, 0) == -1 || ft_is_diag(board, x, y) == -1 || ft_is_diag2(board, x, y) == -1) && x < 9)
		return (ft_put_queen(board, x + 1, y)); //x + 1
	else if ((ft_is_row_col(board, x, y, 0) == -1 || ft_is_diag(board, x, y) == -1 || ft_is_diag2(board, x, y) == -1) && x == 9)
	{
		printf("n vaut %d\n", n);
		n = ft_is_row_col(board, 0, y - 1, 1);
		ft_is_row_col(board, 0, y - 1, 1);//REMOVE QUEEN
		printf("Try to put Queen in %d %d\n", n + 1, y - 2);
		if (n + 1 == 10)
		{
			n = ft_is_row_col(board, 0, y - 2, 1);
			ft_put_queen(board, n, y - 2);
		}
		return (ft_put_queen(board, n + 1, y - 2));
	}
	else
		return (&board[0][0]);
}


int		main(void)
{
	int board[10][10] = {0};
	int y = 0;
	int x = 0;
	write(1, "MAIN OK\n", 100);
	ft_put_queen(board, 0, 0);
/*	ft_ten_queens_puzzle(void);*/
	return (0);
}
