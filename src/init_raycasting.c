/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:28:38 by cbouwen           #+#    #+#             */
/*   Updated: 2024/06/17 16:54:06 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	define_step(t_raycaster raycaster, int posx, int posy)
{
	if (raycaster.raydirx < 0)
	{
		raycaster.stepx = -1;
		raycaster.sidedistx = (posx - raycaster.mapx) * raycaster.deltadistx;
	}
	else
	{
		raycaster.stepx = 1;
		raycaster.sidedistx = (raycaster.mapx + 1 - posx) * raycaster.deltadistx;
	}
	if (raycaster.raydiry < 0)
	{
		raycaster.stepy = -1;
		raycaster.sidedisty = (posy - raycaster.mapy) * raycaster.deltadisty;
	}
	else
	{
		raycaster.stepy = 1;
		raycaster.sidedisty = (raycaster.mapy + 1 - posy) * raycaster.deltadisty;
	}
}

void	fill_variables(t_raycaster raycaster, int posx, int posy)
{
	raycaster.mapx = posx;
	raycaster.mapy = posy;
	raycaster.deltadistx = sqrt(1 + (raycaster.raydirx / raycaster.raydiry));
	raycaster.deltadisty = sqrt(1 + (raycaster.raydiry / raycaster.raydirx));
	define_step(raycaster, posx, posy);
}

void	init_raycasting(t_raycaster raycaster[], t_player player)
{
	int x;

	x = -1;
	while (++x < WIDTH)
	{
		raycaster[x].x = x;
		raycaster[x].camera_x = 2 * x / (double)WIDTH - 1;
		raycaster[x].raydirx = player.direction.x + player.plane.x * raycaster[x].camera_x;
		raycaster[x].raydiry = player.direction.y + player.plane.y * raycaster[x].camera_x;
		fill_variables(raycaster[x], player.position.x, player.position.y);
	}
}
