/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 20:51:41 by thudry            #+#    #+#             */
/*   Updated: 2014/03/09 09:28:21 by thudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H

# define PLAYER 'o'
# define CPU 'x'
# include <stdbool.h>
# include <list.h>

typedef struct		s_choice
{
	int		value;
	int		col;
}					t_choice;

typedef struct		s_env
{
	int		height;
	int		width;
	char	**map;
	int		**atk;
	int		**def;
}					t_env;

void		ft_free_map(char **map);
void		ft_free_map_ia(int **map);
void		ft_process(t_env *env);
void		put_start(t_env *env);
void		put_map(t_env *env);
int			play_chips(t_env *env, int column, int player);
void        play_IA_first(t_env *env);
int         valid_play(char *set, int x);
int			is_win(t_env *env);
int         check_horizontal(char **game, int x, int y, char c);
int         check_vertical(char **game, int x, int y, char c);
int         check_diagonal_dl(char **game, int x, int y, char c);
int         check_diagonal_dr(char **game, int x, int y, char c);
int         check_diagonal_ul(char **game, int x, int y, char c);
int         check_diagonal_ur(char **game, int x, int y, char c);
void		ft_free_all(t_env *env);
bool		is_draw(t_env *env);
void		ft_init_map(t_env *env);
t_choice	*ft_reload_def(t_env *env, t_choice *choice);
t_choice	*ft_reload_atk(t_env *env, t_choice *choice);

#endif
