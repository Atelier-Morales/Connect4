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
#include "connect4.h"

void    print_connect(int x, int pos)
{
    static int  i;

    ++i;
    ft_putchar('|');
    ft_putchar('(');
    if (pos == 1)
        ft_putstr("\033[32mX\033[0m");
    else
        ft_putchar(' ');
    ft_putchar(')');
    if (i == x)
    {
        ft_putchar('|');
        i = 0;
    }
}

void    print_numbers(int x)
{
    static int  i;

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

int     print_error(int i)
{
    if (!i)
        ft_putendl("Dude, don't be silly. Values over 0, please.");
    else
        ft_putendl("Come on, this is bigger than an int! Be reasonable.");
    return (0);
}

int    render_set(int x, int y, t_env *env)
{
    int i;
    int j;
    int k;

    j = 0;
    k = -1;
    while (j < y)
    {
        i = -1;
        while (++k < x)
            print_numbers(x);
        while (++i < x)
        {
            if (env->game[j][i] == '1')
                print_connect(x, 1);
            else
                print_connect(x, 0);
        }
        ft_putchar('\n');
        ++j;
    }
    return (1);
}

char    *create_line(int x)
{
    char    *line;
    int     i;

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

char    **init_board(int x, int y, t_env *env)
{
    char    **board;
    int     i;

    if (x <= 0 || y <= 0)
        return (NULL);
    if (x > 2147483647 || y > 2147483647)
        return (NULL);
    board = (char **)malloc(sizeof(char *) * y);
    i = 0;
    env->x = x;
    env->y = y;
    while (i < y)
    {
        board[i] = create_line(x);
        ++i;
    }
    return (board);
}

int     valid_play(char *set, int x)
{
    if (!ft_atoi(set) || ft_atoi(set) <= 0 || ft_atoi(set) > x)
        return (0);
    return (1);
}

int    compute_play(int move, t_env *env, int pos)
{
    if (env->game[pos][move] == '0')
        env->game[pos][move] = '1';
    else if (env->game[pos][move] != '0' && pos > 0)
        compute_play(move, env, pos - 1);
    else if (env->game[pos][move] != '0' && pos <= 0)
        return (0);
    return (1);
}

int main(int ac, char **av)
{
    char    *set = NULL;
    t_env   env;
    int     play;

    if (ac != 3)
        return (0);
    play = 0;
    if (!(env.game = init_board(ft_atoi(av[1]), ft_atoi(av[2]), &env)))
        return (0);
    render_set(env.x, env.y, &env);
    while (1)
    {
        if (!play)
            ft_putendl("\nMake your play :");
        get_next_line(0, &set);
        ft_putendl(set);
        if (valid_play(set, env.x))
        {
            if (!(compute_play(ft_atoi(set) - 1, &env, env.y - 1)))
                ft_putendl("you cannot put this here");
        }
        else
            ft_putendl("Invalid move. Try again");
        render_set(env.x, env.y, &env);
    }
    return (0);
}
