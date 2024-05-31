/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:47:06 by gcannaud          #+#    #+#             */
/*   Updated: 2023/12/21 21:50:53 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load(t_vars *vars)
{
	int		i;
	int		j;
	char	*obj;
	char	*move;

	i = 0;
	j = 0;
	while (vars->full_map[j] != 0)
	{
		while (vars->full_map[j][i] != 0)
		{
			load_map_imag(vars, i++, j);
		}
		j++;
		i = 0;
	}
	obj = ft_itoa(vars->objectif);
	move = ft_itoa(vars->move);
	scorbord(vars, obj, move);
	free(obj);
	free(move);
	anim(vars);
	return (0);
}

char	*scorbord(t_vars *vars, char *obj, char *move2)
{
	char	*str;
	char	*coll;
	char	*move;
	char	*end_coll;
	char	*full;

	full = ft_itoa(vars->full);
	end_coll = ft_strjoin("/", obj);
	coll = ft_strjoin(full, end_coll);
	free(full);
	free(end_coll);
	move = ft_strjoin("  move : ", move2);
	str = ft_strjoin(coll, move);
	free(coll);
	free(move);
	mlx_string_put(vars->mlx, vars->win, 8, 16, 0xFFFFFF, str);
	free(str);
	return (str);
}

void	load_map_imag(t_vars *vars, int i, int j)
{
	if (vars->full_map[j][i] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->map,
			(i * 32), (j * 32));
	else if (vars->full_map[j][i] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall,
			(i * 32), (j * 32));
	else if (vars->full_map[j][i] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->colle,
			(i * 32), (j * 32));
	else if (vars->full_map[j][i] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit,
			(i * 32), (j * 32));
	else if (vars->full_map[j][i] == 'I')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy,
			(i * 32), (j * 32));
	else if (vars->full_map[j][i] == 'J')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy1,
			(i * 32), (j * 32));
	else if (vars->full_map[j][i] == 'S')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->sword,
			(i * 32), (j * 32));
}

void	wher(t_vars *vars)
{
	if (vars->full_map[vars->textur_y / 32][vars->textur_x / 32] == 'C')
	{
		vars->full = vars->full + 1;
		vars->full_map[vars->textur_y / 32][vars->textur_x / 32] = '0';
	}
	if (vars->full_map[vars->textur_y / 32][vars->textur_x / 32] == 'S')
	{
		vars->attack = 1;
		vars->full_map[vars->textur_y / 32][vars->textur_x / 32] = '0';
		load(vars);
	}
	if (vars->full_map[vars->textur_y / 32][vars->textur_x / 32] == 'E'
			&& vars->full == vars->objectif)
		close_program(vars);
	if (vars->full_map[vars->textur_y / 32][vars->textur_x / 32] == 'I')
		close_program(vars);
	if (vars->full_map[vars->textur_y / 32][vars->textur_x / 32] == 'J')
		close_program(vars);
}

int	key_hook(int key, t_vars *vars)
{
	if (key == 'w' && (vars->full_map[(vars->textur_y / 32) - 1]
			[vars->textur_x / 32] != '1'))
		move12(vars, 1);
	else if (key == 'a' && (vars->full_map[vars->textur_y / 32]
			[(vars->textur_x / 32) - 1] != '1'))
		move12(vars, 2);
	else if (key == 's' && (vars->full_map[(vars->textur_y / 32) + 1]
			[vars->textur_x / 32] != '1'))
		move34(vars, 3);
	else if (key == 'd' && (vars->full_map[vars->textur_y / 32]
			[(vars->textur_x / 32) + 1] != '1'))
		move34(vars, 4);
	else if (key == 65362)
		attack(vars, 1);
	else if (key == 65361)
		attack(vars, 2);
	else if (key == 65364)
		attack(vars, 3);
	else if (key == 65363)
		attack(vars, 4);
	wher(vars);
	load(vars);
	return (0);
}
