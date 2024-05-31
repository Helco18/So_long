/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcannaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:03:50 by gcannaud          #+#    #+#             */
/*   Updated: 2024/01/10 21:04:23 by gcannaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <fcntl.h>
# include "libft/include/libft.h"

typedef struct s_vars
{
	int		p;
	int		move;
	int		exit_count;
	int		objectif;
	int		nb_line;
	int		len_line;
	int		full;
	int		collecting;
	char	**full_map;
	void	*mlx;
	void	*win;
	void	*img;
	void	*map;
	void	*wall;
	void	*colle;
	void	*exit;
	void	*enemy;
	void	*enemy1;
	void	*platt;
	void	*platt2;
	void	*platt3;
	void	*platt4;
	void	*platt5;
	void	*platt6;
	void	*platt7;
	void	*sword;
	int		textur_x;
	int		textur_y;
	int		attack;
	int		textur;
	int		error;
}			t_vars;

int		close_program(t_vars *vars);
int		stop(int keycode, t_vars *vars);
int		load(t_vars *vars);
void	wher(t_vars *vars);
int		key_hook(int key, t_vars *vars);
void	set_xy(t_vars *vars);
void	load_imag(t_vars *vars);
size_t	map_h(char *nam_map);
int		map_w(char *nam_map);
void	load_map(char *nam_map, t_vars *vars);
void	load_imag_entity(t_vars *vars);
void	load_map_imag(t_vars *vars, int i, int j);
int		map_is_valid(char *map_name, t_vars *vars);
int		element_count(t_vars *vars, char ca);
int		map_is_close(t_vars *vars);
int		walls_y(t_vars *vars, int x);
int		walls_x(t_vars *vars, int y);
void	flood_fill(char **flood, t_vars *vars, int x, int y);
void	move12(t_vars *vars, int tag);
void	move34(t_vars *vars, int tag);
void	set_struct(t_vars *vars, char *map_name);
void	move_enemy(t_vars *vars);
void	move_wher(t_vars *vars, int x, int y);
void	replace(t_vars *vars, int j, int i);
void	new_window(t_vars *vars);
int		whetlist(char c);
char	*scorbord(t_vars *vars, char *obj, char *move2);
void	freetabstruct(t_vars *vars);
void	floodfill_maprelod(char *map_name, t_vars *vars);

void	move_enemy1(t_vars *vars);
void	move_wher1(t_vars *vars, int x, int y);
void	replace1(t_vars *vars, int j, int i);
void	attack(t_vars *vars, int tag);
void	load_imag_enemy(t_vars *vars);
void	load_imag_attack(t_vars *vars);
void	att_up(t_vars *vars);
void	att_l(t_vars *vars);
void	att_don(t_vars *vars);
void	att_r(t_vars *vars);
void	anim(t_vars *vars);
void	anim_attack_valu(t_vars *vars);
int		black_list(t_vars *vars, int x, int y);

#endif