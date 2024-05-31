/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:47:46 by gcannaud          #+#    #+#             */
/*   Updated: 2024/01/11 15:47:48 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_program(t_vars *vars)
{
	freetabstruct(vars);
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_image(vars->mlx, vars->map);
	mlx_destroy_image(vars->mlx, vars->exit);
	mlx_destroy_image(vars->mlx, vars->colle);
	mlx_destroy_image(vars->mlx, vars->wall);
	mlx_destroy_image(vars->mlx, vars->sword);
	mlx_destroy_image(vars->mlx, vars->platt);
	mlx_destroy_image(vars->mlx, vars->platt2);
	mlx_destroy_image(vars->mlx, vars->platt3);
	mlx_destroy_image(vars->mlx, vars->platt4);
	mlx_destroy_image(vars->mlx, vars->platt5);
	mlx_destroy_image(vars->mlx, vars->platt6);
	mlx_destroy_image(vars->mlx, vars->platt7);
	mlx_destroy_image(vars->mlx, vars->enemy);
	mlx_destroy_image(vars->mlx, vars->enemy1);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

int	stop(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		freetabstruct(vars);
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_image(vars->mlx, vars->map);
		mlx_destroy_image(vars->mlx, vars->exit);
		mlx_destroy_image(vars->mlx, vars->colle);
		mlx_destroy_image(vars->mlx, vars->wall);
		mlx_destroy_image(vars->mlx, vars->sword);
		mlx_destroy_image(vars->mlx, vars->platt);
		mlx_destroy_image(vars->mlx, vars->platt2);
		mlx_destroy_image(vars->mlx, vars->platt3);
		mlx_destroy_image(vars->mlx, vars->platt4);
		mlx_destroy_image(vars->mlx, vars->platt5);
		mlx_destroy_image(vars->mlx, vars->platt6);
		mlx_destroy_image(vars->mlx, vars->platt7);
		mlx_destroy_image(vars->mlx, vars->enemy);
		mlx_destroy_image(vars->mlx, vars->enemy1);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	return (0);
}

void	freetabstruct(t_vars *vars)
{
	int	x;

	x = 0;
	while (vars->full_map[x] != 0)
	{
		free(vars->full_map[x]);
		x++;
	}
	free(vars->full_map[x]);
	free(vars->full_map);
}
