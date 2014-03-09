/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 03:28:15 by fmorales          #+#    #+#             */
/*   Updated: 2014/03/09 18:32:35 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT4_H
# define CONNECT4_H
# include <string.h>
# include <stdbool.h>
# include "./libft/libft.h"

# define BUFF_SIZE	90960

typedef struct		s_read
{
	int				size;
	int				index;
	int				fd;
	char			*read;
	struct s_read	*next;
}					t_read;

typedef struct		s_choice
{
	int				value;
	int				col;
}					t_choice;

typedef struct		s_env
{
	int				x;
	int				y;
	int				height;
	int				width;
	int				start;
	int				pos;
	int				check;
	char			*set;
	char			**game;
	int				**atk;
	int				**def;
}					t_env;

int					get_next_line(int const fd, char **line);
int					main(int ac, char **av);
void				ft_free_map(char **map);
void				ft_free_map_ia(int **map);
void				ft_process(t_env *env);
void				put_start(t_env *env);
void				put_map(t_env *env);
int					play_chips(t_env *env, int column, int player);
int					compute_play(int move, t_env *env, int pos, char c);
int					is_win(t_env *env);
void				play_IA_first(t_env *env);
int					valid_play(char *set, int x);
int					check_horizontal(char **game, int x, int y, char c);
int					check_vertical(char **game, int x, int y, char c);
int					check_diagonal_dl(char **game, int x, int y, char c);
int					check_diagonal_dr(char **game, int x, int y, char c);
int					check_diagonal_ul(char **game, int x, int y, char c);
int					check_diagonal_ur(char **game, int x, int y, char c);
void				ft_free_all(t_env *env);
bool				is_draw(t_env *env);
void				ft_init_map(t_env *env);
char				**init_board(int x, int y, t_env *env);
int					render_set(int x, int y, t_env *env);
int					ft_ia_turn(t_env *env);
int					winning_play(t_env *env, int move, int pos, char c);
int					player_victory(char *str);
int					print_error(int i);
int					render_set(int x, int y, t_env *env);
t_choice			*ft_reload_def(t_env *env, t_choice *choice);
t_choice			*ft_reload_atk(t_env *env, t_choice *choice);

#endif
