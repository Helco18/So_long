/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:21:26 by gcannaud          #+#    #+#             */
/*   Updated: 2024/01/12 20:21:28 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy1(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (vars->full_map[x] != 0)
	{
		while (vars->full_map[x][y] != 0)
		{
			if (vars->full_map[x][y] == 'J')
				move_wher1(vars, x, y);
			y++;
		}
		x++;
		y = 0;
	}
	replace(vars, 'U', 'J');
}

void	move_wher1(t_vars *vars, int x, int y)
{
	if (x < (vars->textur_y / 32) && black_list(vars, (x + 1), y) == 0)
	{
		vars->full_map[x + 1][y] = 'U';
		vars->full_map[x][y] = '0';
	}
	else if (x > (vars->textur_y / 32) && black_list(vars, (x - 1), y) == 0)
	{
		vars->full_map[x - 1][y] = 'U';
		vars->full_map[x][y] = '0';
	}
	else if (y < (vars->textur_x / 32) && black_list(vars, x, y + 1) == 0)
	{
		vars->full_map[x][y + 1] = 'U';
		vars->full_map[x][y] = '0';
	}
	else if (y > (vars->textur_x / 32) && black_list(vars, x, y - 1) == 0)
	{
		vars->full_map[x][y - 1] = 'U';
		vars->full_map[x][y] = '0';
	}
}

int	black_list(t_vars *vars, int x, int y)
{
	if (vars->full_map[x][y] != '1' && vars->full_map[x][y] != 'J'
		&& vars->full_map[x][y] != 'S' && vars->full_map[x][y] != 'C'
		&& vars->full_map[x][y] != 'E' && vars->full_map[x][y] != 'U')
		return (0);
	return (1);
}
