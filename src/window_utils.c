/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:55:13 by cbouwen           #+#    #+#             */
/*   Updated: 2024/07/22 15:55:15 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int		dph(t_raycaster *rc, t_data *data, int side, double wallpos, int y);
static double	determine_wallpos(t_raycaster *rc, t_data *data, int side);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	handle_input(int key, t_data *data)
{
	if (key == 119 || key == 115)
		move(&data->player, data->mapinfo.map, key);
	if (key == 97 || key == 100)
		strafe(&data->player, data->mapinfo.map, key);
	if (key == 65361 || key == 65363)
		rotate_player(&data->player, key);
	if (key == 65307)
	{
		close_window(data);
	}
	init_raycasting(data);
	prep_dda(data);
	draw_screen(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_all(data);
	exit(1);
}

void	init_window(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3D");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	mlx_hook(data->mlx_win, 17, 1L << 17, &close_window, data);
	mlx_key_hook(data->mlx_win, handle_input, data);
}

void	draw_screen(t_data *data)
{
	int x;

	x = -1;
	while (++x < WIDTH)
		load_texture(&data->rc[x], data->rc[x].side, data);
}

void	load_texture(t_raycaster *rc, int side, t_data *data)
{
	int y;
	int color;

	y = -1;
	while (++y < HEIGHT)
	{
		if (y < HEIGHT / 2)
			my_mlx_pixel_put(data, rc->x, y, data->mapinfo.c);
		if (y > HEIGHT / 2)
			my_mlx_pixel_put(data, rc->x, y, data->mapinfo.f);
		if (y > rc->drawstart && y < rc->drawend)
		{
			if (side == 0)
			{
				if (rc->raydirx < 0)
					color = dph(rc, data, WEST, determine_wallpos(rc, data,
								side), y);
				else
					color = dph(rc, data, EAST, determine_wallpos(rc, data,
								side), y);
			}
			else if (side == 1)
			{
				if (rc->raydiry > 0)
					color = dph(rc, data, SOUTH, determine_wallpos(rc, data,
								side), y);
				else
					color = dph(rc, data, NORTH, determine_wallpos(rc, data,
								side), y);
			}
			my_mlx_pixel_put(data, rc->x, y, color);
		}
	}
}

static int	dph(t_raycaster *rc, t_data *data, int side, double wallpos, int y)
{
	int		tex_x;
	int		tex_y;
	double	step;
	double	texture_pos;

	tex_x = (int)(wallpos) % data->text[side].width;
	step = 1.0 * data->text[side].height / rc->lineheight;
	texture_pos = (y + rc->lineheight / 2 - HEIGHT / 2) * step;
	tex_y = (int)texture_pos % data->text[side].height;
	return (data->text[side].addr[data->text[side].width * tex_y + tex_x]);
}

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
