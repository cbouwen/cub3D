/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:28:38 by cbouwen           #+#    #+#             */
/*   Updated: 2024/06/18 20:35:49 by mlegendr         ###   ########.fr       */
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
	printf("DEFINE_STEP: raycaster.stepx = %i\n", raycaster.stepx);
	printf("DEFINE_STEP: raycaster.stepy = %i\n", raycaster.stepy);
}

void	fill_variables(t_raycaster raycaster, int posx, int posy)
{
	raycaster.mapx = posx;
	raycaster.mapy = posy;

	//just a quick check to see what value comes in
	//printf("pre if: raycaster.raydirx = %f\n", raycaster.raydirx);
	//printf("pre if: raycaster.raydiry = %f\n", raycaster.raydiry);

	/*
	Lode said to do this for some languages
	*/
	if (raycaster.raydirx == 0.0f)
		raycaster.raydirx = 1e30;
	if (raycaster.raydiry == 0.0f)
		raycaster.raydiry = 1e30;
	
	//just a quick check to see what value comes in
	//printf("raycaster.raydirx = %f\n", raycaster.raydirx);
	//printf("raycaster.raydiry = %f\n", raycaster.raydiry);
	
	raycaster.deltadistx = fabs(1.0f / raycaster.raydirx);
	//printf("lode (simplified) raycaster.deltadistx = %f\n", raycaster.deltadistx);

	//printf("\n");
		
	raycaster.deltadisty = fabs(1 / raycaster.raydiry);
	//printf("lode (simplified) raycaster.deltadisty = %f\n", raycaster.deltadisty);

	//printf("\n\n");
	printf("FILL_VARIABLES: raycaster.stepx = %i\n", raycaster.stepx);
	printf("FILL_VARIABLES: raycaster.stepy = %i\n", raycaster.stepy);
	define_step(raycaster, posx, posy);
}

void	init_raycasting(t_raycaster raycaster[], t_player player, int x)
{
	/*int x;

	x = -1;
	while (++x < WIDTH)
	{
		raycaster[x].x = x;
		raycaster[x].camera_x = 2 * x / (double)WIDTH - 1;
		raycaster[x].raydirx = player.direction.x + player.plane.x * raycaster[x].camera_x;
		raycaster[x].raydiry = player.direction.y + player.plane.y * raycaster[x].camera_x;
		fill_variables(raycaster[x], player.position.x, player.position.y);
	}*/

	raycaster[x].x = x;
	raycaster[x].camera_x = 2 * x / (double)WIDTH - 1;
	raycaster[x].raydirx = player.direction.x + player.plane.x * raycaster[x].camera_x;
	raycaster[x].raydiry = player.direction.y + player.plane.y * raycaster[x].camera_x;
	fill_variables(raycaster, player.position.x, player.position.y);
}
