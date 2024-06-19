/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:28:38 by cbouwen           #+#    #+#             */
/*   Updated: 2024/06/19 16:44:33 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	define_step(t_raycaster *raycaster, int posx, int posy)
{
	if (raycaster->raydirx < 0)
	{
		raycaster->stepx = -1;
		raycaster->sidedistx = (posx - raycaster->mapx) * raycaster->deltadistx;
	}
	else
	{
		raycaster->stepx = 1;
		raycaster->sidedistx = (raycaster->mapx + 1 - posx) * raycaster->deltadistx;
	}
	if (raycaster->raydiry < 0)
	{
		raycaster->stepy = -1;
		raycaster->sidedisty = (posy - raycaster->mapy) * raycaster->deltadisty;
	}
	else
	{
		raycaster->stepy = 1;
		raycaster->sidedisty = (raycaster->mapy + 1 - posy) * raycaster->deltadisty;
	}
	if (raycaster->x == 1800)
		printf("\n\nStepx = %i\nStepy = %i\n", raycaster->stepx, raycaster->stepy);
}

void	fill_variables(t_raycaster *raycaster, int posx, int posy)
{
	raycaster->mapx = posx;
	raycaster->mapy = posy;

	//just a quick check to see what value comes in
	//printf("pre if: raycaster.raydirx = %f\n", raycaster.raydirx);
	//printf("pre if: raycaster.raydiry = %f\n", raycaster.raydiry);

	/*
	Lode said to do this for some languages
	*/
	if (raycaster->raydirx == 0.0f)
		raycaster->raydirx = 1e30;
	if (raycaster->raydiry == 0.0f)
		raycaster->raydiry = 1e30;
	
	//just a quick check to see what value comes in
	//printf("raycaster.raydirx = %f\n", raycaster.raydirx);
	//printf("raycaster.raydiry = %f\n", raycaster.raydiry);
	
	/*
	Original method of calculation

	the original used sqrt, changd it to sqrtf to support floating point numbers.
	
	I think this is wrong? I have no real way of validating this by the way. Every number this returns could be right for all I know.
	*/
	raycaster->deltadistx = sqrtf(1.0f + (raycaster->raydirx / raycaster->raydiry));
	//printf("raycaster.deltadistx = %f\n", raycaster.deltadistx);
	
	/*
	As per the guide:
	deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))

	I changed sqrt to sqrtf to support floating point numbers.
	
	I also don't think this is correct, I don't know why but it always return 1 for X calculations. I'll have to carefully check the math.
	*/
	raycaster->deltadistx = sqrtf(1.0f + (raycaster->raydiry * raycaster->raydiry) / (raycaster->raydirx * raycaster->raydirx));
	//printf("lode (non simplified) raycaster.deltadistx = %f\n", raycaster.deltadistx);
	
	/*
	This is the simplified version of the above formula.
	This returns a completely different number than the other formula though. No real idea why. Seems to work for Y calculations though.

	~~
	JUISTE BEREKENING
	~~

	*/
	raycaster->deltadistx = fabs(1.0f / raycaster->raydirx);
	//printf("lode (simplified) raycaster.deltadistx = %f\n", raycaster.deltadistx);

	/*
	This is the calculation method used in the lode youtube video.
	Somehow another version of this formula.
	
	When calculating X,  the result is different from the simplified version
	When calculating Y, the result is the same as the simplified version
	*/
	raycaster->deltadistx = sqrtf(1.0f + (raycaster->raydiry / raycaster->raydirx) * (raycaster->raydiry / raycaster->raydirx));
	//printf("lode (yt video)raycaster.deltadistx = %f\n", raycaster.deltadistx);
	
	//printf("\n");
	
	//printf("raycaster.raydirx = %f\n", raycaster.raydirx);
	//printf("raycaster.raydiry = %f\n", raycaster.raydiry);
	
	raycaster->deltadisty = sqrtf(1 + (raycaster->raydiry / raycaster->raydirx));
	//printf("raycaster.deltadisty = %f\n", raycaster.deltadisty);

	raycaster->deltadisty = sqrtf(1 + (raycaster->raydirx * raycaster->raydirx) / (raycaster->raydiry * raycaster->raydiry));
	//printf("lode (non simplified) raycaster.deltadisty = %f\n", raycaster.deltadisty);
	
	raycaster->deltadisty = fabs(1 / raycaster->raydiry);
	//printf("lode (simplified) raycaster.deltadisty = %f\n", raycaster.deltadisty);

	raycaster->deltadistx = sqrtf(1.0 + (raycaster->raydirx / raycaster->raydiry) * (raycaster->raydirx / raycaster->raydiry));
	//printf("lode (yt video)raycaster.deltadisty = %f\n", raycaster.deltadisty);
	
	//printf("\n\n");
	define_step(raycaster, posx, posy);
	if (raycaster->x == 1800)
		printf("\n\nStepx = %i\nStepy = %i\n", raycaster->stepx, raycaster->stepy);

}

void	init_raycasting(t_raycaster **raycaster, t_player player)
{
	int x;

	x = -1;
	while (++x < WIDTH)
	{
		raycaster[x]->x = x;
		raycaster[x]->camera_x = 2 * x / (double)WIDTH - 1;
		raycaster[x]->raydirx = player.direction.x + player.plane.x * raycaster[x]->camera_x;
		raycaster[x]->raydiry = player.direction.y + player.plane.y * raycaster[x]->camera_x;
		fill_variables(raycaster[x], player.position.x, player.position.y);
	}
}
