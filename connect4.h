/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorales <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 03:28:15 by fmorales          #+#    #+#             */
/*   Updated: 2014/03/08 03:28:16 by fmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT4_H
# define CONNECT4_H
# include <string.h>
# include "./libft/libft.h"

# define BUFF_SIZE 90960

typedef struct		s_read
{
    int				size;
    int				index;
    int				fd;
    char			*read;
    struct s_read	*next;
}                   t_read;

typedef struct      s_env
{
    int             x;
    int             y;
    char            **game;
}                   t_env;

int					get_next_line(int const fd, char **line);
int                 main(int ac, char **av);

#endif
