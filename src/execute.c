/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 09:22:09 by cbouwen           #+#    #+#             */
/*   Updated: 2024/06/21 14:23:29 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	print_rc(t_raycaster raycaster)
{
	printf("\n\nRaycaster\n\n");
	printf("x = %i\n", raycaster.x);
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
	printf("\n\n");
}

void	print_debug(t_raycaster *rc, char *function_name)
{
	printf("\n\nDebugging %s\n\n", function_name);
	printf("lineheight = %i\n", rc->lineheight);
	printf("drawstart = %i\n", rc->drawstart);
	printf("drawend = %i\n", rc->drawend);
}

void	calculate_lineheight(t_raycaster *rc, int side) //Will this work? FT for avoiding fisheye. This calculates the line coming from the camera plane instead of position.
{
	if (side == 0)
		rc->perpwalldist = (rc->sidedistx - rc->deltadistx);
	else
		rc->perpwalldist = (rc->sidedisty - rc->deltadisty);
	rc->lineheight = (int)(HEIGHT / rc->perpwalldist);
	rc->drawstart = -rc->lineheight / 2 + HEIGHT / 2 - 1;
	if (rc->drawstart < 0)
		rc->drawstart = 0;
	rc->drawend = rc->lineheight / 2 + HEIGHT / 2;
	if (rc->drawend >= HEIGHT)
		rc->drawend = HEIGHT;
	//printf("\n\nLineheight = %i\nDrawstart = %i\nDrawend = %i\n", raycaster.lineheight,raycaster.drawstart, raycaster.drawend);
}

void	put_color_to_pixel(t_data *mlx, int x, int y, int color)
{
	int	*buffer;

	buffer = mlx->addr;
	buffer[(y * mlx->line_length / 4) + x * (mlx->bits_per_pixel / 8)] = color;
}

void	load_texture(t_raycaster *rc, int side, t_data *img, t_mapinfo mapinfo) //change colors with textures. Add line for Ceiling and Floor. Maybe move this to utils?
{
	int	y;
	int	color;

	(void)mapinfo;

	if (side == 1)
		color = 16711680;
	else
		color = 16743936;
	y = -1;
	while (++y < HEIGHT)
	{
		/*if (y < HEIGHT / 2)	//not super efficient because it constantly overwrites but hey. If we want, easy fix
			my_mlx_pixel_put(img, rc->x, y, mapinfo.c);
		if (y > HEIGHT / 2)
			my_mlx_pixel_put(img, rc->x, y, mapinfo.f);
		if (y > rc->drawstart && y < rc->drawend)
			my_mlx_pixel_put(img, rc->x, y, color);*/
		if (y < HEIGHT / 2)	//not super efficient because it constantly overwrites but hey. If we want, easy fix
			put_color_to_pixel(img, rc->x, y, color);
		if (y > HEIGHT / 2)
			put_color_to_pixel(img, rc->x, y, color);
		if (y > rc->drawstart && y < rc->drawend)
			put_color_to_pixel(img, rc->x, y, color);
	}
}

void	calculate_dda(t_raycaster *rc, t_map **map)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (rc->sidedistx < rc->sidedisty)
		{
			rc->sidedistx += rc->deltadistx;
			rc->mapx += rc->stepx;
			rc->side = 0; //look at comment under
		}
		else
		{
			rc->sidedisty += rc->deltadisty;
			rc->mapy += rc->stepy;
			rc->side = 1; //this is not enough. Add more rules for N, S, E and W   @Matisse: We need the right int here so we know what texture to project(N,S,E,W)
			//Edit: Maybe this is enough. Maybe with a combination of stepdirx or whatever value, we know which side we'll be facing. Either way this is for the end
		}
		if (map[rc->mapy][rc->mapx].c == '1')
			hit = 1;
	}
	calculate_lineheight(rc, rc->side);
//	if (rc->x % 100 == 0)//for testing purposes. can be deleted
//		print_rc(*rc);
}

void	prep_dda(t_raycaster *raycaster, t_map **map)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		calculate_dda(&raycaster[x], map);
		x++;
	}
}

void	draw_screen(t_raycaster *rc, t_data *img, t_mapinfo mapinfo)//LodeV mentioned that for textures we can't do lines anymore. This means we need a nested loop here. no big changes
{
	int	x;

	x = -1;
	while (++x < WIDTH)
		load_texture(&rc[x], rc[x].side, img, mapinfo);
}

void execute_map(t_map ***map, t_mapinfo mapinfo)
{
	t_player	player;
	t_raycaster	raycaster[WIDTH];

	t_mlx_data  win_data;
	win_data.mlx = mlx_init();
    init_window(&win_data);

	parse_player(mapinfo, *map, &player);
	init_raycasting(raycaster, &player);
	prep_dda(raycaster, *map);

	update_player(raycaster, mapinfo);//Final step

	mlx_loop(win_data.mlx);
}
