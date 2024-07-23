/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:23:10 by cbouwen           #+#    #+#             */
/*   Updated: 2024/07/22 19:28:05 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/Getnextline/getnextline.h"
# include "../lib/Libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "typedef.h"

# define HEIGHT 1080
# define WIDTH 1920
# define D_HEIGHT 1080.0
# define D_WIDTH 1920.0
# define FOV_ANGLE 66
# define MOVESPEED 0.40
# define RS 0.30
# define TEX_SIZE 64

//utils
int		map_name(char *str);
void	ft_free(void *ptr);
int		check_for_map(char *str);
int		ft_error(char *str, t_data *data);
void	ft_free_array(t_map **map, int count);
void	free_all(t_data *data);
void	destroy_textures(t_data *data);
void	free_cond(t_data *data);

/*parser.c*/
int		parse_cub(char *argv, t_data *data);
void	parse_input(int fd, t_data *data, t_mapchecker *elements);
void	parse_mapinfo(char *str, t_data *data);
void	map_errors(t_mapchecker *elements);
void	parse_texture(t_data *data);

/*parse_texture_error.c*/
void	check_texture_file(char *path);
void	create_image(t_data *data, int dir, char *path);
int		*get_data_addr(t_data *data, int dir);
void	check_texture_size(t_data *data, int dir);

/*mapinfo.c*/
void	check_input(char *str, t_data *data, t_mapchecker *elements);
void	parse_color(char *str, t_data *data);
void	parse_color_values(int *X, char *str, int i);
void	parse_path(char *str, t_data *data);

/*parse_utils.c*/
int		check_for_map(char *str);
void	check_all_elements(t_mapchecker *elements);
void	check_duplicates(char *str, t_mapchecker *elements);
void	update_mapchecker(char *str, t_mapchecker *elements);
void	init_map_checker(t_mapchecker *elements);

/*parse_map.c*/
void	parse_map(int fd, t_data *data);
t_map	**init_map(t_data *data);
void	fill_map(int fd, t_data *data);
void	set_remainder(t_data *data, int *x, int y);

/*valid_map.c*/
int		valid_map(t_data *data);
int		check_char(char c);
int		check_open(t_data *data, int y, int x);

/*parse_player.c*/
void	parse_player(t_data *data);
void	find_player(t_data *data);
void	parse_direction(t_data *data, char c);
void	parse_plane(t_data *data, char c);

/*execute.c*/
void	execute_map(t_data *data);
void	prep_dda(t_data *data);
void	calculate_dda(t_raycaster *rc, t_map **map);
void	calculate_lineheight(t_raycaster *rc, int side);

/*init_raycasting.c*/
void	init_raycasting(t_data *data);
void	setup_ray_dir(t_raycaster *rc, t_player *player, int x);
void	init_tile_traversal(t_raycaster *rc, double posx, double posy);
void	define_step(t_raycaster *rc, double posx, double posy);

/*window_utils.c*/
void	init_window(t_data *data);
int		close_window(t_data *data);
int		handle_input(int key, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_screen(t_data *data);
void	load_texture(t_raycaster *rc, int side, t_data *data);

/*movement.c*/
void	update_player(t_data *data);
void	move(t_player *player, t_map **map, int x);
void	strafe(t_player *player, t_map **map, int x);
void	rotate_player(t_player *player, int x);

/*init_struct_default.c*/
void	init_data_default(t_data *data);
void	init_player_default(t_player *player);
void	init_rc_default(t_raycaster *rc);
void	init_mapinfo_default(t_mapinfo *mapinfo);
void	init_text_mlx_default(t_text_mlx *text);



void	test_map(t_map **map, t_mapinfo mapinfo);
//parser
/*int			parse_cub(char *argv, t_mapinfo *mapinfo, t_map ***map);
void	init_map_checker(t_mapchecker *elements);
void	update_mapchecker(char *str, t_mapchecker *elements);
void	check_input(char *str, t_mapinfo *mapinfo, t_mapchecker *elements);
t_map	**parse_map(int fd, t_mapinfo mapinfo, t_map ***map);
int		valid_map(t_map **map, t_mapinfo mapinfo);
void	parse_player(t_mapinfo mapinfo, t_map **map, t_player *player);*/
/*
//mlx_ft's
void	init_window(t_mlx_data *win_data);
int		close_window(t_mlx_data *win_data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);//we need this?

//executing part
void	execute_map(t_map ***map, t_mapinfo mapinfo);

//raycasting ft's

void	update_player(t_raycaster *rc, t_mapinfo mapinfo);
void	init_raycasting(t_raycaster *raycaster, t_player *player);
void	draw_screen(t_raycaster *rc, t_data *img, t_mapinfo mapinfo);

//void	ft_draw_map(t_map **map, t_mapinfo mapinfo, t_mlx_data *win_data);

//tester ft's
void	tester(t_mapinfo mapinfo);
void	test_map(t_map **map, t_mapinfo mapinfo);
void	test_player(t_player player);
void	raytester(t_raycaster raycaster[]);
*/

//init ft's

#endif
