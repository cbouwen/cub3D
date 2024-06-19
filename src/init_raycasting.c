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

void	__fill_variables(t_raycaster raycaster, int posx, int posy)
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

void	__init_raycasting(t_raycaster raycaster[], t_player player)
{
	int x;

	x = -1;
	while (++x < WIDTH)
	{
		raycaster[x].x = x;
		raycaster[x].camera_x = 2 * x / (double)WIDTH - 1;
		raycaster[x].raydirx = player.direction.x + player.plane.x * raycaster[x].camera_x;
		raycaster[x].raydiry = player.direction.y + player.plane.y * raycaster[x].camera_x;
		__fill_variables(raycaster[x], player.position.x, player.position.y);
	}
}

void	init_raycasting_real(t_raycaster *rc);
void	setup_ray_dir(t_raycaster *rc, t_player *player, int x);
void	initTileTraversal(t_raycaster *rc, int posx, int posy);

void	init_raycasting(t_raycaster *raycaster, t_player *player)
{
	int x;

	x = 0;
	while (x < WIDTH)
	{
		init_raycasting_real(&raycaster[x]);
		setup_ray_dir(&raycaster[x], player, x);
		x++;
	}
}

void	init_raycasting_real(t_raycaster *rc)
{
	rc->camera_x = 0.0f;
	rc->raydirx = 0.0f;
	rc->raydiry = 0.0f;
	rc->sidedistx = 0.0f;
	rc->sidedisty = 0.0f;
	rc->deltadistx = 0.0f;
	rc->deltadisty = 0.0f;
	rc->stepx = 0;
	rc->stepy = 0;
	rc->mapx = 0;
	rc->mapy = 0;
	rc->perpwalldist = 0.0f;
	rc->lineheight = 0;
	rc->drawstart = 0;
	rc->drawend = 0;
	rc->x = 0;
}

void	setup_ray_dir(t_raycaster *rc, t_player *player, int x)
{
	rc->x = x;
	rc->camera_x = 2 * x / (double)WIDTH - 1;
	rc->raydirx = player->direction.x + player->plane.x * rc->camera_x;
	rc->raydiry = player->direction.y + player->plane.y * rc->camera_x;
	initTileTraversal(rc, player->position.x, player->position.y);
}

void	initTileTraversal(t_raycaster *rc, int posx, int posy)
{
	rc->mapx = posx;
	rc->mapy = posy;
	if (rc->raydirx == 0.0f)
		rc->raydirx = 1e30;
	if (rc->raydiry == 0.0f)
		rc->raydiry = 1e30;
	rc->deltadistx = fabs(1.0f / rc->raydirx);
	rc->deltadisty = fabs(1 / rc->raydiry);
	//define_step(rc, posx, posy);
}