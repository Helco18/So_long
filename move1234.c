/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1234.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:38:22 by gcannaud          #+#    #+#             */
/*   Updated: 2024/01/23 15:38:24 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move12(t_vars *vars, int tag)
{
	if (tag == 1)
	{
		vars->textur_y -= 32;
		vars->move++;
	}
	else if (tag == 2)
	{
		if (vars->attack == 1)
		{
			vars->attack = 2;
			vars->textur = 6;
		}
		vars->textur_x -= 32;
		vars->move++;
	}
	move_enemy(vars);
	move_enemy1(vars);
}

void	move34(t_vars *vars, int tag)
{
	if (tag == 3)
	{
		vars->textur_y += 32;
		vars->move++;
	}
	else if (tag == 4)
	{
		if (vars->attack == 2)
		{
			vars->attack = 1;
			vars->textur = 1;
		}
		vars->textur_x += 32;
		vars->move++;
	}
	move_enemy(vars);
	move_enemy1(vars);
}
