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

	while (1)
	{
		draw_screen(rc, &win_data.img, mapinfo);
		mlx_loop(win_data.mlx);
	}



}
