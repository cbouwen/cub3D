/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:44:38 by cbouwen           #+#    #+#             */
/*   Updated: 2024/07/22 15:49:08 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	move(t_player *player, t_map **map, int x)
{
	if (x == 119)
	{
		if (map[(int)(player->position.y)][(int)(player->position.x
				+ player->direction.x * MOVESPEED)].c != '1')
			player->position.x += player->direction.x * MOVESPEED;
		if (map[(int)(player->position.y + player->direction.y
				* MOVESPEED)][(int)(player->position.x)].c != '1')
			player->position.y += player->direction.y * MOVESPEED;
	}
	if (x == 115)
	{
		if (map[(int)(player->position.y)][(int)(player->position.x
				- player->direction.x * MOVESPEED)].c != '1')
			player->position.x -= player->direction.x * MOVESPEED;
		if (map[(int)(player->position.y - player->direction.y
				* MOVESPEED)][(int)(player->position.x)].c != '1')
			player->position.y -= player->direction.y * MOVESPEED;
	}
}

void	strafe(t_player *player, t_map **map, int x)
{
	if (x == 100)
	{
		if (map[(int)player->position.y][(int)(player->position.x
			+ player->plane.x * MOVESPEED)].c != '1')
			player->position.x += player->plane.x * MOVESPEED;
		if (map[(int)(player->position.y + player->plane.y
				* MOVESPEED)][(int)player->position.x].c != '1')
			player->position.y += player->plane.y * MOVESPEED;
	}
	if (x == 97)
	{
		if (map[(int)player->position.y][(int)(player->position.x
			- player->plane.x * MOVESPEED)].c != '1')
			player->position.x -= player->plane.x * MOVESPEED;
		if (map[(int)(player->position.y - player->plane.y
				* MOVESPEED)][(int)player->position.x].c != '1')
			player->position.y -= player->plane.y * MOVESPEED;
	}
}

void	rotate_player(t_player *player, int x)
{
	double	olddirx;
	double	oldplanex;

	olddirx = player->direction.x;
	oldplanex = player->plane.x;
	if (x == 65361)
	{
		player->direction.x = player->direction.x * cos(-RS)
			- player->direction.y * sin(-RS);
		player->direction.y = olddirx * sin(-RS) + player->direction.y
			* cos(-RS);
		player->plane.x = player->plane.x * cos(-RS) - player->plane.y
			* sin(-RS);
		player->plane.y = oldplanex * sin(-RS) + player->plane.y * cos(-RS);
	}
	else
	{
		player->direction.x = player->direction.x * cos(RS)
			- player->direction.y * sin(RS);
		player->direction.y = olddirx * sin(RS) + player->direction.y * cos(RS);
		player->plane.x = player->plane.x * cos(RS) - player->plane.y * sin(RS);
		player->plane.y = oldplanex * sin(RS) + player->plane.y * cos(RS);
	}
}

void	update_player(t_data *data)
{
	draw_screen(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	mlx_loop(data->mlx);
}
