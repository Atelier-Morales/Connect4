/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 12:17:38 by fmorales          #+#    #+#             */
/*   Updated: 2014/03/09 12:17:40 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int     valid_play(char *set, int x)
{
    if (!ft_atoi(set) || ft_atoi(set) <= 0 || ft_atoi(set) > x)
        return (0);
    return (1);
}

void    play_IA_first(t_env *env)
{
    env->game[env->y  - 1][(env->x - 1) / 2] = '2';
}

int     winning_play(t_env *env, int move, int pos, char c)
{
    if (check_vertical(env->game, move, pos, c) == 4)
        return (4);
    if (check_horizontal(env->game, move, pos, c) == 4)
        return (4);
    if (check_diagonal_dl(env->game, move, pos, c) == 4)
        return (4);
    if (check_diagonal_dr(env->game, move, pos, c) == 4)
        return (4);
    return (0);
}
