/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:23:10 by cbouwen           #+#    #+#             */
/*   Updated: 2024/06/25 16:33:08 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/Getnextline/getnextline.h"
# include "../lib/Libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "../mlx_linux/mlx.h"
# include "typedefs.h"
# include "typedef_new.h"

#define HEIGHT 1080
#define WIDTH 1920
#define D_HEIGHT 1080.0
#define D_WIDTH 1920.0
#define FOV_ANGLE 66
#define MOVESPEED 0.25
#define ROTSPEED 0.33

//utils
int			map_name(char *str);
void		ft_free(void *ptr);
int			check_for_map(char *str);
int			ft_error(char *str);
void		ft_free_array(new_t_map **map, int count);

/*parser.c*/
int			parse_cub(char *argv, new_t_data *data);
void		parse_input(int fd, new_t_data *data, new_t_mapchecker *elements);
int			color_range(int	x);
void		parse_mapinfo(char *str, new_t_data *data);
void		map_errors(new_t_mapchecker *elements, new_t_data *data);

/*mapinfo.c*/
void		check_input(char *str, new_t_data *data, new_t_mapchecker *elements);
void		parse_color(char *str, new_t_data *data);
void		parse_color_values(int *X, char *str, int i);
void		parse_path(char *str, new_t_data *data);

/*parse_utils.c*/
int			check_for_map(char *str);
void		check_all_elements(new_t_mapchecker *elements);
void		check_duplicates(char *str, new_t_mapchecker *elements);
void		update_mapchecker(char *str, new_t_mapchecker *elements);
void		init_map_checker(new_t_mapchecker *elements);

/*parse_map.c*/
void		parse_map(int fd, new_t_data *data);
new_t_map	**init_map(new_t_data *data);
void		fill_map(int fd, new_t_data *data);
void		set_remainder(new_t_data *data, int *x, int y);

/*valid_map.c*/
int			valid_map(new_t_data *data);
int			check_char(char c);
int			check_open(new_t_data *data, int y, int x);

/*parse_player.c*/
void		parse_player(new_t_data *data);
void		find_player(new_t_data *data);
void		parse_direction(new_t_data *data, char c);
void		parse_plane(new_t_data *data, char c);

/*execute.c*/
void		execute_map(new_t_data *data);
void		prep_dda(new_t_data *data);
void		calculate_dda(new_t_raycaster *rc, new_t_map **map);
void		calculate_lineheight(new_t_raycaster *rc, int side);

/*init_raycasting.c*/
void		init_raycasting(new_t_data *data);
void		setup_ray_dir(new_t_raycaster *rc, new_t_player *player, int x);
void		init_tile_traversal(new_t_raycaster *rc, double posx, double posy);
void		define_step(new_t_raycaster *rc, double posx, double posy);

/*window_utils.c*/
void		init_window(new_t_data *data);
int			close_window(new_t_data *data);
int  		handle_input(int key, new_t_data *data);
void		my_mlx_pixel_put(new_t_data *data, int x, int y, int color);
void		draw_screen(new_t_data *data);
void		load_texture(new_t_raycaster *rc, int side, new_t_data *data);

/*movement.c*/
void	update_player(new_t_data *data);

//parser
/*int			parse_cub(char *argv, t_mapinfo *mapinfo, t_map ***map);
void		init_map_checker(t_mapchecker *elements);
void		update_mapchecker(char *str, t_mapchecker *elements);
void		check_input(char *str, t_mapinfo *mapinfo, t_mapchecker *elements);
t_map		**parse_map(int fd, t_mapinfo mapinfo, t_map ***map);
int			valid_map(t_map **map, t_mapinfo mapinfo);
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
void		tester(t_mapinfo mapinfo);
void		test_map(t_map **map, t_mapinfo mapinfo);
void		test_player(t_player player);
void		raytester(t_raycaster raycaster[]);
*/

//init ft's
void	init_data_default(new_t_data *data);
void	init_player_default(new_t_player *player);
void	init_rc_default(new_t_raycaster *rc);
void	init_mapinfo_default(new_t_mapinfo *mapinfo);

#endif
