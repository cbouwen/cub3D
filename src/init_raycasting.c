/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:28:38 by cbouwen           #+#    #+#             */
/*   Updated: 2024/06/12 14:54:10 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*void	find_dda(t_raycaster raycaster[], t_player player)
{
	

}
*/
void	find_raydir(t_raycaster raycaster[], t_player player)
{
	int x;

	x = -1;
	while (++x < WIDTH)
	{
		raycaster[x].camera_x = 2 * x / (double)WIDTH - 1;
		raycaster[x].rayDirX = player.direction.x + player.plane.x * raycaster[x].camera_x;
		raycaster[x].rayDirY = player.direction.y + player.plane.y * raycaster[x].camera_x;
	}

	test_player(player);//
	raytester(raycaster);//
}

void	init_raycasting(t_raycaster raycaster[], t_player player)
{
	find_raydir(raycaster, player);
//	find_dda(raycaster, player);



}
