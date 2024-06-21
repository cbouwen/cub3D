/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:39:36 by cbouwen           #+#    #+#             */
/*   Updated: 2024/06/21 12:48:42 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	tester(t_mapinfo mapinfo)
{
	printf("Path to NO is: %s\n", mapinfo.no);
	printf("Path to SO is: %s\n", mapinfo.so);
	printf("Path to WE is: %s\n", mapinfo.we);
	printf("Path to EA is: %s\n", mapinfo.ea);
	printf("Color for the floor is: %i\n", mapinfo.f);
	printf("Color for the ceiling is: %i\n", mapinfo.c);
	printf("\nAmount of rows: %i\n", mapinfo.rows);
	printf("Amount of colomns: %i\n\n", mapinfo.colomns);
}

void	test_map(t_map **map, t_mapinfo mapinfo)
{
	int	y;
	int	x;

	y = 0;
	while (y < mapinfo.rows)
	{
		x = -1;
		while (++x < mapinfo.colomns)
			printf("%c", map[y][x].c);
		printf("\n");
		y++;
	}
}

void	test_player(t_player player)
{
	printf("\n\nPlayer is on coordinate[%f][%f] and his direction vector is [%f][%f]\n", player.position.x, player.position.y, player.direction.x, player.direction.y);
	printf("Plane is on coordinates[%f][%f]\n", player.plane.x, player.plane.y);
}

void	raytester(t_raycaster raycaster[])
{
	int	x;

	x = 0;
	printf("\n\n");
	while (x < WIDTH)
	{
		printf("Percentile of screen: %f   rayDirX = %f rayDirY = %f\n", (double)x/(double)WIDTH, raycaster[x].raydirx, raycaster[x].raydiry);
		x = x + 100;
	}
}
