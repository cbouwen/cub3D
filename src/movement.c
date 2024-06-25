/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:23:30 by cbouwen           #+#    #+#             */
/*   Updated: 2024/06/21 15:17:27 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	change_position(t_player *player, int x) //you really need to think a bit more about this, lol
{
	if (x == 119)//up
	{
		player->position.x += player->direction.x * 0.25;
		player->position.y += player->direction.y * 0.25;
	}
	if (x == 115)//down
	{
		player->position.x -= player->direction.x * 0.25;
		player->position.y -= player->direction.y * 0.25;
	}
	if (x == 97)//strafe left
	{
		player->position.x += player->plane.x * 0.33;
		player->position.y += player->plane.y * 0.33;

	}
	if (x == 100)//strafe right
	{
		player->position.x -= player->plane.x * 0.33;
		player->position.y -= player->plane.y * 0.33;
	}
}

void	rotate_player(t_player *player,	int x)
{


}


static int	handle_input(int key, t_mlx_data *win_data)
{
	if (key == 119)
		printf("w is pressed\n\n");
	if (key == 115)
		printf("s is pressed\n\n");
	if (key == 97)
		printf("a is pressed\n\n");
	if (key == 100)
		printf("d is pressed\n\n");
	if (key == 65361)
		printf("Left arrow is pressed\n\n");
	if (key == 65363)
		printf("Right arrow is pressed\n\n");
	if (key == 65307)
		close_window(win_data);
	return (0);
}

void	update_player(t_raycaster *rc, t_mapinfo mapinfo)
{
	(void)rc;
	(void)mapinfo;
	t_mlx_data	win_data;

	win_data.mlx = mlx_init();
	init_window(&win_data);
	draw_screen(rc, &win_data.img, mapinfo);
	mlx_loop_hook(win_data.mlx, 
//	mlx_key_hook(win_data.mlx_win, handle_input, &win_data);
	mlx_loop(win_data.mlx);



}


/*w = 119
  s = 115
  a = 97
  d = 100
  <- = 65361
  -> = 65363
  */
