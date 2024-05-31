/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:20:35 by gcannaud          #+#    #+#             */
/*   Updated: 2024/01/17 22:20:37 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	attack(t_vars *vars, int tag)
{
	if (tag == 1 && (vars->attack == 1 || vars->attack == 2))
		att_up(vars);
	else if (tag == 2 && (vars->attack == 1 || vars->attack == 2))
		att_l(vars);
	else if (tag == 3 && (vars->attack == 1 || vars->attack == 2))
		att_don(vars);
	else if (tag == 4 && (vars->attack == 1 || vars->attack == 2))
		att_r(vars);
}

void	att_up(t_vars *vars)
{
	vars->textur = 2;
	if (vars->full_map[(vars->textur_y / 32) - 1]
		[vars->textur_x / 32] == 'J')
		vars->full_map[(vars->textur_y / 32) - 1][vars->textur_x / 32] = '0';
}

void	att_l(t_vars *vars)
{
	vars->textur = 3;
	vars->attack = 2;
	if (vars->full_map[vars->textur_y / 32]
		[(vars->textur_x / 32) - 1] == 'J')
		vars->full_map[vars->textur_y / 32][(vars->textur_x / 32) - 1] = '0';
}

void	att_don(t_vars *vars)
{
	vars->textur = 4;
	if (vars->full_map[(vars->textur_y / 32) + 1]
		[vars->textur_x / 32] == 'J')
		vars->full_map[(vars->textur_y / 32) + 1][vars->textur_x / 32] = '0';
}

void	att_r(t_vars *vars)
{
	vars->textur = 5;
	vars->attack = 1;
	if (vars->full_map[vars->textur_y / 32]
		[(vars->textur_x / 32) + 1] == 'J')
		vars->full_map[vars->textur_y / 32][(vars->textur_x / 32) + 1] = '0';
}
