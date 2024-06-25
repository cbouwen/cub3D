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
void		ft_free_array(t_map **map, int count);

//parser
int			parse_cub(char *argv, t_mapinfo *mapinfo, t_map ***map);
void		init_map_checker(t_mapchecker *elements);
void		update_mapchecker(char *str, t_mapchecker *elements);
void		check_input(char *str, t_mapinfo *mapinfo, t_mapchecker *elements);
t_map		**parse_map(int fd, t_mapinfo mapinfo, t_map ***map);
int			valid_map(t_map **map, t_mapinfo mapinfo);
void	parse_player(t_mapinfo mapinfo, t_map **map, t_player *player);

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

//init ft's
void	init_data_default(new_t_data *data);
void	init_player_default(new_t_player *player);
void	init_rc_default(new_t_raycaster *rc);
void	init_mapinfo_default(new_t_mapinfo *mapinfo);

#endif
