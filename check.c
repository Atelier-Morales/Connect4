/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 12:27:56 by fmorales          #+#    #+#             */
/*   Updated: 2014/03/09 18:08:14 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int		check_horizontal(char **game, int x, int y, char c)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	check = 0;
	while (game[y][x - i] == c && check == 0)
		i++;
	i = x - (i - 1);
	while (game[y][i + j] == c)
	{
		++check;
		++j;
	}
	return (check);
}

int		check_vertical(char **game, int x, int y, char c)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (game[y + i])
	{
		if (game[y + i][x] != c && check < 4)
			return (0);
		if (check == 4)
			return (check);
		if (game[y + i][x] == c)
			++check;
		i++;
	}
	return (check);
}

int		check_diagonal_dl(char **game, int x, int y, char c)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	check = 0;
	while (game[y - i] && game[y - i][x + j] == c)
	{
		++i;
		++j;
	}
	i = y - (i - 1);
	j = x + (j - 1);
	while (game[i])
	{
		if (game[i][j] != c && check < 4)
			return (0);
		if (check == 4)
			return (check);
		/*check = game[i][j] == c ? ++check : check;*/
		if (game[i][j] == c)
			++check;
		i++;
		j--;
	}
	return (check);
}

int		check_diagonal_dr(char **game, int x, int y, char c)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	check = 0;
	while (game[y - i] && game[y - i][x - j] == c)
	{
		++i;
		++j;
	}
	i = y - (i - 1);
	j = x - (j - 1);
	while (game[i])
	{
		if (game[i][j] != c && check < 4)
			return (0);
		if (check == 4)
			return (check);
		/*check = game[i][j] == c ? ++check : check;*/
		if (game[i][j] == c)
			++check;
		i++;
		j++;
	}
	return (check);
}
