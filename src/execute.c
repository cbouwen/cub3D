/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:16:09 by cbouwen           #+#    #+#             */
/*   Updated: 2024/06/12 16:02:37 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    execute_map(t_map ***map, t_mapinfo mapinfo)
{
    t_mlx_data  win_data;
	t_player	player;
	t_raycaster	raycaster[WIDTH];

    win_data.mlx = mlx_init();
    init_window(&win_data);
	parse_player(mapinfo, *map, &player);
	init_raycasting(raycaster, player);
//	ft_calculate_map(map, mapinfo);
//	while (1)
//		ft_draw_map(*map, mapinfo, &win_data); //is this correct?? Do we keep looping here to continue program or we do it in main?
//	free_params(map, &mapinfo);
    mlx_loop(win_data.mlx);
}
