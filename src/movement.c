/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:23:30 by cbouwen           #+#    #+#             */
/*   Updated: 2024/06/21 14:22:09 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	update_player(t_raycaster *rc, t_mapinfo mapinfo)
{
	(void)rc;
	(void)mapinfo;
	t_mlx_data	win_data;

	win_data.mlx = mlx_init();
	init_window(&win_data);

	draw_screen(rc, &win_data.img, mapinfo);
	
	while (1)
	{
		mlx_put_image_to_window(win_data.mlx, win_data.mlx_win, win_data.img.img, 0, 0);
		mlx_loop(win_data.mlx);
	}



}
