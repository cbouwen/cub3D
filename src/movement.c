/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:23:30 by cbouwen           #+#    #+#             */
/*   Updated: 2024/06/25 16:17:55 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	change_position(t_player *player, int x) //you really need to think a bit more about this, lol
{
	if (x == 119)//up
	{
		printf("\nPlayer.position.x = %f\nPlayer.position.y = %f\n", player->position.x, player->position.y);
		player->position.x += player->direction.x * MOVESPEED;
		player->position.y += player->direction.y * MOVESPEED;
		printf("\nPlayer.position.x = %f\nPlayer.position.y = %f\n", player->position.x, player->position.y);
	}
	if (x == 115)//down
	{
		player->position.x -= player->direction.x * MOVESPEED;
		player->position.y -= player->direction.y * MOVESPEED;
	}
	if (x == 97)//strafe left
	{
		player->position.x += player->plane.x * ROTSPEED;
		player->position.y += player->plane.y * ROTSPEED;

	}
	if (x == 100)//strafe right
	{
		player->position.x -= player->plane.x * ROTSPEED;
		player->position.y -= player->plane.y * ROTSPEED;
	}
}

void	rotate_player(t_player *player,	int x)
{
(void)player;
(void)x;

}

void	update_player(t_file *file)
{
	t_mlx_data	win_data;

	win_data.mlx = mlx_init();
	file->win_data = win_data;
	init_window(&win_data, file.player, file.rc);
	draw_screen(rc, &win_data.img, mapinfo);
	mlx_put_image_to_window(win_data.mlx, win_data.mlx_win, win_data.img.img, 0, 0);
	mlx_loop(win_data.mlx);
}

/*w = 119
  s = 115
  a = 97
  d = 100
  <- = 65361
  -> = 65363
  */
