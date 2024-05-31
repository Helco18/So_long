/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:30:55 by gcannaud          #+#    #+#             */
/*   Updated: 2024/01/19 17:30:57 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	anim(t_vars *vars)
{
	if (vars->textur == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
			vars->textur_x, vars->textur_y);
	else if (vars->textur == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->platt,
			vars->textur_x, vars->textur_y);
	else if (vars->textur == 5)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->platt3,
			vars->textur_x, vars->textur_y);
	else if (vars->textur == 2)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->platt4,
			vars->textur_x, vars->textur_y);
	else if (vars->textur == 4)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->platt5,
			vars->textur_x, vars->textur_y);
	else if (vars->textur == 3)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->platt6,
			vars->textur_x, vars->textur_y);
	else if (vars->textur == 6)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->platt7,
			vars->textur_x, vars->textur_y);
	anim_attack_valu(vars);
}

void	anim_attack_valu(t_vars *vars)
{
	if (vars->attack == 1)
		vars->textur = 1;
	else if (vars->attack == 2)
		vars->textur = 6;
	else
		vars->textur = 0;
}
