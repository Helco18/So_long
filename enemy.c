/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:21:26 by gcannaud          #+#    #+#             */
/*   Updated: 2024/01/12 20:21:28 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (vars->full_map[x] != 0)
	{
		while (vars->full_map[x][y] != 0)
		{
			if (vars->full_map[x][y] == 'I')
				move_wher(vars, x, y);
			y++;
		}
		x++;
		y = 0;
	}
	replace(vars, 'Y', 'I');
}

void	move_wher(t_vars *vars, int x, int y)
{
	if (x < (vars->textur_y / 32) && vars->full_map[x + 1][y] != '1')
	{
		vars->full_map[x + 1][y] = 'Y';
		vars->full_map[x][y] = '0';
	}
	else if (x > (vars->textur_y / 32) && vars->full_map[x - 1][y] != '1')
	{
		vars->full_map[x - 1][y] = 'Y';
		vars->full_map[x][y] = '0';
	}
	else if (y < (vars->textur_x / 32) && vars->full_map[x][y +1] != '1')
	{
		vars->full_map[x][y + 1] = 'Y';
		vars->full_map[x][y] = '0';
	}
	else if (y > (vars->textur_x / 32) && vars->full_map[x][y - 1] != '1')
	{
		vars->full_map[x][y - 1] = 'Y';
		vars->full_map[x][y] = '0';
	}
}

void	replace(t_vars *vars, int j, int i)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (vars->full_map[x] != 0)
	{
		while (vars->full_map[x][y] != 0)
		{
			if (vars->full_map[x][y] == j)
				vars->full_map[x][y] = i;
			y++;
		}
		x++;
		y = 0;
	}
}
