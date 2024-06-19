/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:16:09 by cbouwen           #+#    #+#             */
/*   Updated: 2024/06/18 20:21:36 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	load_texture(t_raycaster raycaster, int side, t_data *img)
{
	int	y;
	int	color;

	if (side == 1)
		color = 16711680;
	else
		color = 16743936;
	y = -1;
	while (++y < HEIGHT)
	{
		if (y > raycaster.drawstart && y < raycaster.drawend)
			my_mlx_pixel_put(img, raycaster.x, y, color);
	}
}

void	print_rc(t_raycaster raycaster)
{
	printf("\n\nRaycaster\n\n");
	printf("camera_x = %f\n", raycaster.camera_x);
	printf("raydirx = %f\n", raycaster.raydirx);
	printf("raydiry = %f\n", raycaster.raydiry);
	printf("sidedistx = %f\n", raycaster.sidedistx);
	printf("sidedisty = %f\n", raycaster.sidedisty);
	printf("deltadistx = %f\n", raycaster.deltadistx);
	printf("deltadisty = %f\n", raycaster.deltadisty);
	printf("stepx = %i\n", raycaster.stepx);
	printf("stepy = %i\n", raycaster.stepy);
	printf("mapx = %i\n", raycaster.mapx);
	printf("mapy = %i\n", raycaster.mapy);
	printf("side = %i\n", raycaster.side);
	printf("perpwalldist = %f\n", raycaster.perpwalldist);
	printf("lineheight = %i\n", raycaster.lineheight);
	printf("drawstart = %i\n", raycaster.drawstart);
	printf("drawend = %i\n", raycaster.drawend);
	printf("x = %i\n", raycaster.x);
	printf("\n\n");
}

void	calculate_lineheight(t_raycaster raycaster, int side) //Will this work? FT for avoiding fisheye. This calculates the line coming from the camera plane instead of position.
{
	//print_rc(raycaster);
	if (side == 0)
		raycaster.perpwalldist = (raycaster.sidedistx - raycaster.deltadistx);
	else
		raycaster.perpwalldist = (raycaster.sidedisty - raycaster.deltadisty);
	raycaster.lineheight = (int)(HEIGHT / raycaster.perpwalldist);
	raycaster.drawstart = -raycaster.lineheight / 2 + HEIGHT / 2;
	if (raycaster.drawstart < 0)
		raycaster.drawstart = 0;
	raycaster.drawend = raycaster.lineheight / 2 + HEIGHT / 2;
	if (raycaster.drawend >= HEIGHT)
		raycaster.drawend = HEIGHT - 1;
	//printf("\n\nLineheight = %i\nDrawstart = %i\nDrawend = %i\n", raycaster.lineheight,raycaster.drawstart, raycaster.drawend);
	//print_rc(raycaster);
}

void	calculate_dda(t_raycaster raycaster, t_map **map, t_data *img)
{
	/*printf("calculate_dda: raycaster.stepx = %i\n", raycaster.stepx);
	printf("calculate_dda: raycaster.stepy = %i\n", raycaster.stepy);*/
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (raycaster.sidedistx < raycaster.sidedisty)
		{
			raycaster.sidedistx += raycaster.deltadistx;
			raycaster.mapx += raycaster.stepx;
			raycaster.side = 0; //look at comment under
		}
		else
		{
			raycaster.sidedisty += raycaster.deltadisty;
			raycaster.mapy += raycaster.stepy;
			raycaster.side = 1; //this is not enough. Add more rules for N, S, E and W   @Matisse: We need the right int here so we know what texture to project(N,S,E,W)
		}
		if (map[raycaster.mapx][raycaster.mapy].c == '1')
			hit = 1;
	}
	calculate_lineheight(raycaster, raycaster.side);
	load_texture(raycaster, raycaster.side, img);
}

void    __execute_map(t_map ***map, t_mapinfo mapinfo)
{
    t_mlx_data  win_data;
	t_player	player;
	t_raycaster	raycaster[WIDTH];
	int	x;

    win_data.mlx = mlx_init();
    init_window(&win_data);
	parse_player(mapinfo, *map, &player);
	while (1) //unsure if this is the correct way to be handling this. Let's leave it in for now
	{
		//init_raycasting(raycaster, player);
		x = -1;
		while (++x < WIDTH)
			calculate_dda(raycaster[x], *map, &win_data.img);
		mlx_loop(win_data.mlx);//?? do we keep the mlx_loop in the permanent loop? how do we refresh the screen. Problems for later
	}
	//	free_params(map, &mapinfo);
}

void execute_map(t_map ***map, t_mapinfo mapinfo)
{
	t_mlx_data	win_data;
	t_player	player;
	t_raycaster	raycaster[WIDTH];
	int			x;

	win_data.mlx = mlx_init();
	init_window(&win_data);
	parse_player(mapinfo, *map, &player);
	x = 0;
	while (1)
	{
		init_raycasting(raycaster, &player);
		printf("execute_map: raycaster[0].raydirx = %f\n", raycaster[0].raydirx);
		printf("execute_map: raycaster[0].raydiry = %f\n", raycaster[0].raydiry);
		x++;
	}
}
