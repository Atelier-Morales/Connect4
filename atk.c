/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuardoui <tuardoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 04:01:32 by tuardoui          #+#    #+#             */
/*   Updated: 2014/03/09 18:06:28 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static void			ft_choose_value(t_env *env, int x, int y)
{
	int				i;
	int				best;

	best = 0;
	i = x + 1;
	while (i < env->x && env->atk[y][i] == -1)
		best = (best < i++ - x) ? best + 1 : best;
	i = x - 1;
	while (i >= 0 && env->atk[y][i] == -1)
		best = (best < x - i--) ? best + 1 : best;
	i = y + 1;
	while (i < env->y && env->atk[i][x] == -1)
		best = (best < i++ - y) ? best + 1 : best;
	i = 1;
	while (x - i >= 0 && y + i < env->y && env->atk[y + i][x - i] == -1)
		best = (best < i++) ? best + 1 : best;
	i = 1;
	while (x + i < env->x && y + i < env->y\
			&& env->atk[y + i][x + i] == -1)
		best = (best < i++) ? best + 1 : best;
	if ((y + 1 < env->y && env->atk[y + 1][x] == -1) || y == env->y - 1)
		env->atk[y][x] = (best > env->atk[y][x]) ? best : env->atk[y][x];
}

static void			ft_choose_best(t_env *env, t_choice *choice)
{
	int				x;
	int				y;

	y = 0;
	choice->value = 0;
	choice->col = 0;
	y = 0;
	while (y < env->y)
	{
		x = 0;
		while (x < env->x)
		{
			if (env->atk[y][x] > choice->value)
			{
				choice->value = env->atk[y][x];
				choice->col = x;
			}
			++x;
		}
		++y;
	}
}

t_choice			*ft_reload_atk(t_env *env, t_choice *choice)
{
	int				x;
	int				y;

	y = 0;
	while (y < env->y)
	{
		x = 0;
		while (x < env->x)
		{
			if (env->atk[y][x] == 0)
				ft_choose_value(env, x, y);
			++x;
		}
		++y;
	}
	ft_choose_best(env, choice);
	return (choice);
}
