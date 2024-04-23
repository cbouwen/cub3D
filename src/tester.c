/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:39:36 by cbouwen           #+#    #+#             */
/*   Updated: 2024/04/23 16:28:52 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	tester(t_mapinfo mapinfo)
{
	printf("Path to NO is: %s\n", mapinfo.no);
	printf("Path to SO is: %s\n", mapinfo.so);
	printf("Path to WE is: %s\n", mapinfo.we);
	printf("Path to EA is: %s\n", mapinfo.ea);
	printf("Color for the floor is: %i, %i, %i\n", mapinfo.f.red,
			mapinfo.f.green, mapinfo.f.blue);
	printf("Color for the ceiling is: %i, %i, %i\n", mapinfo.c.red,
			mapinfo.c.green, mapinfo.c.blue);
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
