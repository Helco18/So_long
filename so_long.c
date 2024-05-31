/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:19:06 by gcannaud          #+#    #+#             */
/*   Updated: 2024/01/10 21:19:09 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	map_h(char *nam_map)
{
	int		fd;
	char	*line;
	size_t	nb_line;

	nb_line = 0;
	fd = open(nam_map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		nb_line++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (nb_line);
}

int	map_w(char *nam_map)
{
	int		fd;
	char	*line;
	size_t	len;
	size_t	nb_line;

	nb_line = 0;
	len = 0;
	fd = open(nam_map, O_RDONLY);
	line = get_next_line(fd);
	len = ft_strlen(line);
	while (line)
	{
		nb_line++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (len);
}

void	load_map(char *nam_map, t_vars *vars)
{
	int		fd;
	char	*line;
	int		j;

	j = 0;
	vars->full_map = ft_calloc(sizeof(char *), (map_h(nam_map) + 1));
	if (!vars->full_map)
		return ;
	fd = open(nam_map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		vars->full_map[j] = ft_strdup(line);
		j++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	vars->attack = 0;
	vars->full_map[j] = 0;
}

void	floodfill_maprelod(char *map_name, t_vars *vars)
{
	flood_fill(vars->full_map, vars, (vars->textur_y / 32),
		(vars->textur_x / 32));
	freetabstruct(vars);
	load_map(map_name, vars);
}
