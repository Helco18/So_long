/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:10:10 by gcannaud          #+#    #+#             */
/*   Updated: 2024/01/10 21:10:20 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	char	*map_name;

	if (argc == 1)
	{
		map_name = ft_strdup("map/map00.ber");
		load_map(map_name, &vars);
	}
	else if (argc == 2 && map_is_valid(argv[1], &vars) == 0)
		map_name = ft_strdup(argv[1]);
	else
	{
		ft_printf("ERROR : to many arguments or map is not valid.\n");
		return (0);
	}
	vars.mlx = mlx_init();
	new_window(&vars);
	free(map_name);
	load_imag(&vars);
	load(&vars);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_key_hook(vars.win, stop, &vars);
	mlx_hook(vars.win, 17, 0L, close_program, &vars);
	mlx_loop(vars.mlx);
	close_program(&vars);
}

void	new_window(t_vars *vars)
{
	int		w;
	int		h;

	h = walls_x(vars, 0) * 32;
	w = walls_y(vars, 0) * 32;
	vars->win = mlx_new_window(vars->mlx, w, h, "so_long");
}

void	set_struct(t_vars *vars, char *map_name)
{
	load_map(map_name, vars);
	vars->objectif = element_count(vars, 'C');
	if (vars->objectif == 0)
		return ;
	vars->p = 0;
	vars->p = element_count(vars, 'P');
	if (vars->p != 1)
		return ;
	set_xy(vars);
	vars->collecting = 0;
	vars->exit_count = 0;
	vars->nb_line = (map_h(map_name));
	vars->len_line = (map_w(map_name));
	vars->attack = 0;
	vars->error = 0;
}

int	element_count(t_vars *vars, char ca)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (vars->full_map[j] != 0)
	{
		while (vars->full_map[j][i] != 0)
		{
			if (vars->full_map[j][i] == ca)
				c++;
			i++;
		}
		j++;
		i = 0;
	}
	return (c);
}

int	map_is_valid(char *map_name, t_vars *vars)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd != -1 && ft_strrchr(map_name, '.')
		&& ft_strncmp(".ber\0", ft_strrchr(map_name, '.'), 5) == 0)
	{
		set_struct(vars, map_name);
		if (vars->p == 1 && (element_count(vars, 'C') > 0
				&& element_count(vars, 'E') > 0 && map_is_close(vars) == 0))
		{
			floodfill_maprelod(map_name, vars);
			if (vars->objectif == vars->collecting && (vars->exit_count)
				> 0 && vars->error == 0)
			{
				close(fd);
				return (0);
			}
			else
				freetabstruct(vars);
		}
		else
			freetabstruct(vars);
	}
	close(fd);
	return (1);
}
