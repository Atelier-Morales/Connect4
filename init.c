/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 12:39:18 by fmorales          #+#    #+#             */
/*   Updated: 2014/03/09 12:39:19 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "connect4.h"

static char     *create_line(int x)
{
    char        *line;
    int         i;

    i = 0;
    line = (char *)malloc(sizeof(char) * x + 1);
    while (i < x)
    {
        line[i] = '0';
        ++i;
    }
    line[i] = '\0';
    return (line);
}

static void		ft_generate_map_ia(t_env *env, int ***map)
{
    bool        error;
    int         i;

    i = 0;
    error = false;
    *map = (int **)malloc(sizeof(int *) * (env->y + 1));
    (*map)[env->y] = 0;
    while (error == false && i < env->y)
    {
        (*map)[i] = (int *)malloc(sizeof(int) * (env->x + 1));
        ft_memset((*map)[i], 0, env->x + 1);
        ++i;
    }
}

char            **init_board(int x, int y, t_env *env)
{
    char        **board;
    int         i;

    if (x <= 0 || y <= 0)
        return (NULL);
    if (x > 2147483647 || y > 2147483647)
        return (NULL);
    board = (char **)malloc(sizeof(char *) * y + 1);
    env->x = x;
    env->y = y;
    ft_generate_map_ia(env, &env->def);
    ft_generate_map_ia(env, &env->atk);
    i = 0;

    while (i < y)
    {
        board[i] = create_line(x);
        ++i;
    }
    board[i] = NULL;
    return (board);
}
