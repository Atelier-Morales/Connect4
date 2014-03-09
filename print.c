/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 12:34:28 by fmorales          #+#    #+#             */
/*   Updated: 2014/03/09 18:27:11 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static void		print_connect(int x, int pos)
{
	static int	i;

	++i;
	ft_putchar('|');
	ft_putchar('(');
	if (pos == 1)
		ft_putstr("\033[33mX\033[0m");
	else if (pos == 2)
		ft_putstr("\033[31mX\033[0m");
	else
		ft_putchar(' ');
	ft_putchar(')');
	if (i == x)
	{
		ft_putchar('|');
		i = 0;
	}
}

int				player_victory(char *str)
{
	ft_putendl(str);
	return (0);
}

static void		print_numbers(int x)
{
	static int	i;

	++i;
	ft_putchar(' ');
	if (i < 10)
		ft_putchar(' ');
	ft_putstr(ft_itoa(i));
	ft_putchar(' ');
	if (i == x)
	{
		ft_putchar('\n');
		i = 0;
	}
}

int				print_error(int i)
{
	if (!i)
		ft_putendl("Dude, don't be silly. Values over 0, please.");
	else
		ft_putendl("Come on, this is bigger than an int! Be reasonable.");
	return (0);
}

int				render_set(int x, int y, t_env *env)
{
	int			i;
	int			j;
	int			k;

	j = 0;
	k = -1;
	ft_putchar('\n');
	while (j < y)
	{
		i = -1;
		while (++k < x)
			print_numbers(x);
		while (++i < x)
		{
			if (env->game[j][i] == '1')
				print_connect(x, 1);
			else if (env->game[j][i] == '2')
				print_connect(x, 2);
			else
				print_connect(x, 0);
		}
		ft_putchar('\n');
		++j;
	}
	return (1);
}
