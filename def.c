/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: turardoui <thudry@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 04:01:32 by tuardoui          #+#    #+#             */
/*   Updated: 2014/03/09 09:48:08 by tuardoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static void         ft_choose_value(t_env *env, int x, int y)
{
    int             i;
    int             best;

	best = 0;
	i = x + 1;
    while (i < env->x && env->def[y][i] == -2)
		best = (best < i++ - x) ? best + 1 : best;
	i = x - 1;
	while (i >= 0 && env->def[y][i] == -2)
		best = (best < x - i--) ? best + 1 : best;
	i = y + 1;
    while (i < env->y && env->def[i][x] == -2)
		best = (best < i++ - y) ? best + 1 : best;
	i = 1;
    while (x - i >= 0 && y + i < env->y && env->def[y + i][x - i] == -2)
		best = (best < i++) ? best + 1 : best;
	i = 1;
    while (x + i < env->x && y + i < env->y\
		  && env->def[y + i][x + i] == -2)
		best = (best < i++) ? best + 1 : best;
    if ((y + 1 < env->y && env->def[y + 1][x] == -2) || y == env->y - 1)
		env->def[y][x] = (best > env->def[y][x]) ? best : env->def[y][x];
}

static void			ft_choose_best(t_env *env, t_choice *choice)
{
    int             x;
    int             y;

	y = 0;
	choice->value = 0;
	choice->col = 0;
	y = 0;
    while (y < env->y)
	{
		x = 0;
        while (x < env->x)
		{
			if (env->def[y][x] > choice->value)
			{
				choice->value = env->def[y][x];
				choice->col = x;
			}
			++x;
		}
		++y;
	}
}

t_choice            *ft_reload_def(t_env *env, t_choice *choice)
{
    int             x;
    int             y;

	y = 0;
    while (y < env->y)
	{
		x = 0;
        while (x < env->x)
		{
			if (env->def[y][x] == 0)
				ft_choose_value(env, x, y);
			++x;
		}
		++y;
	}
	ft_choose_best(env, choice);
	return (choice);
}
