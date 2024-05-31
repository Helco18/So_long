/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:26:02 by gcannaud          #+#    #+#             */
/*   Updated: 2024/01/11 15:26:04 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_imag(t_vars *vars)
{
	int		w;
	int		h;

	vars->objectif = element_count(vars, 'C');
	vars->full = 0;
	vars->move = 0;
	vars->textur = 0;
	w = 0;
	h = 0;
	vars->map = mlx_xpm_file_to_image(vars->mlx, "texture/ground.xpm", &w, &h);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "texture/wall.xpm", &w, &h);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, "texture/exit.xpm", &w, &h);
	load_imag_entity(vars);
}

void	load_imag_entity(t_vars *vars)
{
	int		w;
	int		h;

	w = 0;
	h = 0;
	vars->img = mlx_xpm_file_to_image(vars->mlx, "texture/player.xpm", &w, &h);
	vars->colle = mlx_xpm_file_to_image(vars->mlx,
			"texture/collectibe.xpm", &w, &h);
	load_imag_enemy(vars);
}

void	load_imag_attack(t_vars *vars)
{
	int		w;
	int		h;

	w = 0;
	h = 0;
	vars->platt = mlx_xpm_file_to_image(vars->mlx, "texture/playerattack1.xpm",
			&w, &h);
	vars->platt2 = mlx_xpm_file_to_image(vars->mlx,
			"texture/playerattack3.xpm", &w, &h);
	vars->platt3 = mlx_xpm_file_to_image(vars->mlx,
			"texture/playerattack5.xpm", &w, &h);
	vars->platt4 = mlx_xpm_file_to_image(vars->mlx,
			"texture/playerattack6.xpm", &w, &h);
	vars->platt5 = mlx_xpm_file_to_image(vars->mlx,
			"texture/playerattack7.xpm", &w, &h);
	vars->platt6 = mlx_xpm_file_to_image(vars->mlx,
			"texture/playerattack8.xpm", &w, &h);
	vars->platt7 = mlx_xpm_file_to_image(vars->mlx,
			"texture/playerattack9.xpm", &w, &h);
	vars->sword = mlx_xpm_file_to_image(vars->mlx, "texture/sword.xpm", &w, &h);
	set_xy(vars);
}

void	load_imag_enemy(t_vars *vars)
{
	int		w;
	int		h;

	w = 0;
	h = 0;
	vars->enemy = mlx_xpm_file_to_image(vars->mlx, "texture/enemy.xpm", &w, &h);
	vars->enemy1 = mlx_xpm_file_to_image(vars->mlx, "texture/enemy2.xpm",
			&w, &h);
	load_imag_attack(vars);
}

void	set_xy(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (vars->full_map[y] != 0 && vars->full_map[y][x] != 'P')
	{
		while (vars->full_map[y][x] != 0 && vars->full_map[y][x] != 'P')
		{
			if (vars->full_map[y][x] == 'P')
				break ;
			x++;
		}
		if (vars->full_map[y][x] == 'P')
			break ;
		x = 0;
		y++;
	}
	vars->textur_x = (x * 32);
	vars->textur_y = (y * 32);
	vars->full_map[vars->textur_y / 32][vars->textur_x / 32] = '0';
}
