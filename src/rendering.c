/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:55:13 by cbouwen           #+#    #+#             */
/*   Updated: 2024/07/23 16:32:34 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static double	determine_wallpos(t_raycaster *rc, t_data *data, int side)
{
	double	wallpos;

	if (side == 0)
		wallpos = data->player.position.y + rc->perpwalldist * rc->raydiry;
	else
		wallpos = data->player.position.x + rc->perpwalldist * rc->raydirx;
	wallpos -= floor(wallpos);
	return (wallpos * data->text[side].width);
}

//dph = determine pixel hit
static int	dph(t_data *data, int side, double wallpos, int y)
{
	int		tex_x;
	int		tex_y;
	double	step;
	double	texture_pos;

	tex_x = (int)(wallpos) % data->text[side].width;
	step = 1.0 * data->text[side].height / data->rc[data->rc_x].lineheight;
	texture_pos = (y + data->rc[data->rc_x].lineheight / 2 - HEIGHT / 2) * step;
	tex_y = (int)texture_pos % data->text[side].height;
	return (data->text[side].addr[data->text[side].width * tex_y + tex_x]);
}

static void	determine_side(t_data *data, int x, int y)
{
	int	color;

	data->rc_x = x;
	color = 0;
	if (data->rc[x].side == 0)
	{
		if (data->rc[x].raydirx < 0)
			color = dph(data, WEST, \
			determine_wallpos(&data->rc[x], data, data->rc[x].side), y);
		else
			color = dph(data, EAST, \
			determine_wallpos(&data->rc[x], data, data->rc[x].side), y);
	}
	else if (data->rc[x].side == 1)
	{
		if (data->rc[x].raydiry > 0)
			color = dph(data, SOUTH, \
			determine_wallpos(&data->rc[x], data, data->rc[x].side), y);
		else
			color = dph(data, NORTH, \
			determine_wallpos(&data->rc[x], data, data->rc[x].side), y);
	}
	my_mlx_pixel_put(data, data->rc[x].x, y, color);
}

void	draw_screen(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			if (y < HEIGHT / 2)
				my_mlx_pixel_put(data, data->rc[x].x, y, data->mapinfo.c);
			if (y > HEIGHT / 2)
				my_mlx_pixel_put(data, data->rc[x].x, y, data->mapinfo.f);
			if (y > data->rc[x].drawstart && y < data->rc[x].drawend)
				determine_side(data, x, y);
		}		
	}
}
