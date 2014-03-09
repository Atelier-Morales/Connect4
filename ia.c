/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuardoui <tuardoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 02:23:54 by tuardoui          #+#    #+#             */
/*   Updated: 2014/03/09 09:26:02 by tuardoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static void	ft_change_both_map(t_env *env, int x, int y, int value)
{
	env->atk[y][x] = value;
	env->def[y][x] = value;
}

void		ft_init_map(t_env *env)
{
	int		x;
	int		y;

    y = 0;
    while (y < env->y)
	{
		x = 0;
        while (x < env->x)
		{
            if (env->game[y][x] == '2')
				ft_change_both_map(env, x, y, -1);
            else if (env->game[y][x] == '1')
				ft_change_both_map(env, x, y, -2);
			else
				ft_change_both_map(env, x, y, 0);
			++x;
		}
		++y;
	}
}
