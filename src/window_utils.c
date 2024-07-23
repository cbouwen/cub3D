/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:12:26 by mlegendr          #+#    #+#             */
/*   Updated: 2024/07/23 16:26:51 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

//hier zijn alle free's juist, en het werkt. Geen leaks.
int	close_window(t_data *data)
{
	
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_display(data->mlx);
	free_cond(data);
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
