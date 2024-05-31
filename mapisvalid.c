/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapisvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:33:44 by gcannaud          #+#    #+#             */
/*   Updated: 2024/03/07 17:25:49 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_is_close(t_vars *vars)
{
	if (walls_x(vars, 0) != 0 && walls_y(vars, 0) != 0
		&& walls_y(vars, 0) == walls_y(vars, (walls_x(vars, 0) - 1))
		&& walls_x(vars, 0) == walls_x(vars, (vars->len_line - 2)))
		return (0);
	return (1);
}

int	walls_y(t_vars *vars, int x)
{
	int	i;

	i = 0;
	while (vars->full_map[x][i] == '1')
		i++;
	if (vars->full_map[x][i] == '\n' || vars->full_map[x][i] == '\0')
		return (i);
	return (0);
}

int	walls_x(t_vars *vars, int y)
{
	int	i;

	i = 0;
	while (vars->full_map[i] != 0
		&& ft_strlen(vars->full_map[i]) >= (size_t)y
		&& vars->full_map[i][y] == '1')
		i++;
	if (vars->full_map[i] == 0 || vars->full_map[i][0] != '1')
		return (i);
	return (0);
}

void	flood_fill(char **flood, t_vars *vars, int x, int y)
{
	if (x < 0 || x >= vars->nb_line || y < 0 || y >= vars->len_line
		|| flood[x][y] == '1' || flood[x][y] == 'V')
		return ;
	if (flood[x][y] == 'C')
		vars->collecting++;
	if (flood[x][y] == 'E')
		vars->exit_count++;
	if (whetlist(flood[x][y]) == 0)
		vars->error++;
	flood[x][y] = 'V';
	flood_fill(flood, vars, x + 1, y);
	flood_fill(flood, vars, x - 1, y);
	flood_fill(flood, vars, x, y + 1);
	flood_fill(flood, vars, x, y - 1);
}

int	whetlist(char c)
{
	if (c == '1' || c == '0' || c == 'E' || c == 'C' || c == 'P' || c == 'S'
		|| c == 'I' || c == 'J')
		return (1);
	return (0);
}
