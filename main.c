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
#include <stdio.h>
#include <time.h>
#include "connect4.h"

void    print_connect(int x, int pos)
{
    static int  i;

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
/*
int     player_victory()
{
    ft_putendl("Player 1 won");
    return (0);
}
*/
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
    board = (char **)malloc(sizeof(char *) * y + 1);
    i = 0;
    env->x = x;
    env->y = y;
    while (i < y)
    {
        board[i] = create_line(x);
        ++i;
    }
    board[i] = NULL;
    return (board);
}

int     valid_play(char *set, int x)
{
    if (!ft_atoi(set) || ft_atoi(set) <= 0 || ft_atoi(set) > x)
        return (0);
    return (1);
}

int     compute_play(int move, t_env *env, int pos)
{
    if (env->game[0][move] != '0')
        return (0);
    else if (env->game[pos][move] == '0')
        env->game[pos][move] = '1';
    else if (env->game[pos][move] != '0')
        return (compute_play(move, env, pos - 1));
    return (pos);
}

int     check_horizontal(char **game, int x, int y)
{
    int i;
    int j;
    int check;

    i = 0;
    j = 0;
    check = 0;
    while (game[y][x - i] == '1' && check == 0)
        i++;
    i = x - (i - 1);
    while (game[y][i + j] == '1')
    {

        ++check;
        ++j;
    }
    return (check);
}

int     check_vertical(char **game, int x, int y)
{
    int i;
    int check;

    i = 0;
    check = 0;
    while (game[y + i])
    {
        if (check == 4)
            return (check);
        if (game[y + i][x] == '1')
            ++check;
        i++;
    }
    return (check);
}

int     check_diagonal_dl(char **game, int x, int y)
{
    int i;
    int j;
    int check;

    i = 0;
    j = 0;
    check = 0;
    while (game[y + i])
    {
        if (check == 4)
            return (check);
        if (game[y + i][x - j] == '1')
        {
            ++check;
        }
        i++;
        j++;
    }
    return (check);
}

int     check_diagonal_dr(char **game, int x, int y)
{
    int i;
    int j;
    int check;

    i = 0;
    j = 0;
    check = 0;
    while (game[y + i])
    {
        if (check == 4)
            return (check);
        if (game[y + i][x + j] == '1')
        {
            ++check;
        }
        i++;
        j++;
    }
    return (check);
}

int     check_diagonal_ul(char **game, int x, int y)
{
    int i;
    int j;
    int check;

    i = 0;
    j = 0;
    check = 0;
    while (game[y - i])
    {
        if (check == 4)
            return (check);
        if (game[y - i][x - j] == '1')
        {
            ++check;
        }
        i++;
        j++;
    }
    return (check);
}

int     check_diagonal_ur(char **game, int x, int y)
{
    int i;
    int j;
    int check;

    i = 0;
    j = 0;
    check = 0;
    while (game[y - i])
    {
        if (check == 4)
            return (check);
        if (game[y - i][x + j] == '1')
        {
            ++check;
        }
        i++;
        j++;
    }
    return (check);
}

int     winning_play(t_env *env, int move, int pos)
{
    if (check_vertical(env->game, move, pos) == 4)
        return (4);
    if (check_horizontal(env->game, move, pos) == 4)
        return (4);
    if (check_diagonal_dl(env->game, move, pos) == 4)
        return (4);
    if (check_diagonal_dr(env->game, move, pos) == 4)
        return (4);
    if (check_diagonal_ul(env->game, move, pos) == 4)
        return (4);
    if (check_diagonal_ur(env->game, move, pos) == 4)
        return (4);
    return (0);
}

void    play_IA_first(t_env *env)
{
    env->game[env->y  - 1][(env->x - 1) / 2] = '2';
}

int main(int ac, char **av)
{
    char    *set = NULL;
    t_env   env;
    int     pos;
    int     check;
    int     start;

    if (ac != 3)
        return (0);
    if (!(env.game = init_board(ft_atoi(av[1]), ft_atoi(av[2]), &env)))
        return (0);
    srand (time(NULL));
    start = rand() % 2 + 1;
    if (start == 2)
        play_IA_first(&env);
    render_set(env.x, env.y, &env);
    while (1)
    {
        ft_putendl("\nMake your play :");
        get_next_line(0, &set);
        if (valid_play(set, env.x))
        {
            if (!(pos = compute_play(ft_atoi(set) - 1, &env, env.y - 1)))
                ft_putendl("you cannot put this here");
            else
            {
                render_set(env.x, env.y, &env);
                check = winning_play(&env, ft_atoi(set) - 1, pos);
                if (check == 4)
                {
                    ft_putendl("victory");
                    return (0);
                }
            }
        }
        else
            ft_putendl("Invalid move. Try again");
    }
    return (0);
}
