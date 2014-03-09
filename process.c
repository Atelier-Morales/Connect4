/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuardoui <tuardoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 22:16:48 by tuardoui          #+#    #+#             */
/*   Updated: 2014/03/09 09:36:06 by tuardoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "connect4.h"

int 	ft_ia_turn(t_env *env)
{
	t_choice	atk;
	t_choice	def;
    int         check;
    int         pos;

	(void)atk;
	ft_init_map(env);
	ft_reload_def(env, &def);
	ft_reload_atk(env, &atk);
	if (def.value >= 2)
    {
        pos = compute_play(def.col, env, env->y - 1, '2');
        check = winning_play(env, def.col, pos, '2');
    }
	else
    {
        pos = compute_play(atk.col, env, env->y - 1, '2');
        check = winning_play(env, atk.col, pos, '2');
    }
    render_set(env->x, env->y, env);
    if (check == 4)
        return (1);
    return (0);
}
