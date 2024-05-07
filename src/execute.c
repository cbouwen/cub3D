/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:16:09 by cbouwen           #+#    #+#             */
/*   Updated: 2024/05/07 17:02:37 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    execute_map(t_map ***map, t_mapinfo mapinfo)
{
    t_mlx_data  win_data;
	t_player	player;
	t_camera	camera;

    win_data.mlx = mlx_init();
    init_window(&win_data);
	init_raycasting(*map, &player, &camera);
//	ft_calculate_map(map, mapinfo);
//	ft_draw_map(*map, mapinfo, &win_data);
//	free_params(map, &mapinfo);
    mlx_loop(win_data.mlx);
}
