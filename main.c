/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 21:08:05 by fmorales          #+#    #+#             */
/*   Updated: 2014/03/07 21:08:12 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "connect4.h"

int             compute_play(int move, t_env *env, int pos, char c)
{
    if (env->game[0][move] != '0')
        return (0);
    else if (env->game[pos][move] == '0')
        env->game[pos][move] = c;
    else if (env->game[pos][move] != '0')
        return (compute_play(move, env, pos - 1, c));
    return (pos);
}

static int     while_ft(t_env env)
{
    while (1)
    {
        ft_putendl("\nMake your play :");
        get_next_line(0, &env.set);
        if (valid_play(env.set, env.x))
        {
            if (!(env.pos = compute_play(ft_atoi(env.set) - 1, &env, env.y - 1, '1')))
                ft_putendl("you cannot put this here");
            else
            {
                render_set(env.x, env.y, &env);
                env.check = winning_play(&env, ft_atoi(env.set) - 1, env.pos, '1');
                if (env.check == 4)
                    return (player_victory("\nHuman player won"));
            }
            if (ft_ia_turn(&env))
                return (player_victory("\nComputer won"));
        }
        else
            ft_putendl("\nInvalid move. Try again");
    }
    return (0);
}

static void     ft_dump_tab(void ***tab)
{
    int            cur;

    cur = 0;
    while (tab[0][cur])
    {
        free(tab[0][cur]);
        tab[0][cur] = NULL;
        ++cur;
    }
    free(tab[0]);
    tab[0] = NULL;
}

int             free_tabs(t_env *env)
{
    env->set = NULL;
    free(env->set);
    ft_dump_tab((void ***)&env->game);
    ft_dump_tab((void ***)&env->atk);
    ft_dump_tab((void ***)&env->def);
    return (0);
}

int             main(int ac, char **av)
{
    t_env       env;

    if (ac != 3)
        return (0);
    if (!(env.game = init_board(ft_atoi(av[1]), ft_atoi(av[2]), &env)))
        return (0);
    srand (time(NULL));
    env.start = rand() % 2 + 1;
    if (env.start == 2)
        play_IA_first(&env);
    render_set(env.x, env.y, &env);
    if (!while_ft(env))
        return (free_tabs(&env));
    return (0);
}
