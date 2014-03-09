#include <stdlib.h>
#include "libft.h"
#include <puissance4.h>

int			ft_generate_map(t_env *env)
{
	bool	error;
	int		i;

	i = 0;
	error = false;
	env->map = (char **)malloc(sizeof(char *) * (env->height + 1));
	if (env->map == 0)
	{
		ft_putstr_fd("Error : unable to malloc.\n", 2);
		return (1);
	}
	env->map[env->height] = 0;
	while (error == false && i < env->height)
	{
		env->map[i] = ft_strnew(env->width + 1);
		ft_memset(env->map[i], '.', env->width);
		if (env->map[i] == 0)
			error = true;
		++i;
	}
	if (error == true)
	{
		ft_free_map(env->map);
		return (1);
	}
	return (0);
}

int			ft_generate_map_ia(t_env *env, int ***map)
{
	bool	error;
	int		i;

	i = 0;
	error = false;
	*map = (int **)malloc(sizeof(int *) * (env->height + 1));
	if (map == 0)
	{
		ft_putstr_fd("Error : unable to malloc.\n", 2);
		return (1);
	}
	(*map)[env->height] = 0;
	while (error == false && i < env->height)
	{
		(*map)[i] = (int *)malloc(sizeof(int) * (env->width + 1));
		ft_memset((*map)[i], 0, env->width + 1);
		if ((*map)[i] == 0)
			error = true;
		++i;
	}
	if (error == true)
	{
		ft_free_map_ia(*map);
		return (1);
	}
	return (0);
}

void		ft_init_env(t_env *env)
{
	ft_memset(env, 0, sizeof(env));
	env->run = true;
	env->current = 0;
}

int			main(int ac, char **av)
{
	t_env	env;

	ft_init_env(&env);
	if (ac != 3)
	{
		ft_putstr_fd("Usage : ./puissance4 height width.\n", 2);
		ft_free_all(&env);
		return (1);
	}
	env.height = ft_atoi(av[1]);
	env.width = ft_atoi(av[2]);
	if (env.width < 7 || env.height < 6)
	{
		ft_putstr_fd("Error : invalid map size.\n", 2);
		ft_free_all(&env);
		return (1);
	}
	if (ft_generate_map(&env) == 1 || ft_generate_map_ia(&env, &env.def) == 1 || ft_generate_map_ia(&env, &env.atk) == 1)
	{
		ft_free_all(&env);
		return (1);
	}
	put_start(&env);
	ft_process(&env);
	ft_free_all(&env);
	return (0);
}