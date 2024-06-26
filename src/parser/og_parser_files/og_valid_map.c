/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:23:50 by cbouwen           #+#    #+#             */
/*   Updated: 2024/04/23 16:39:23 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*int	check_open(t_map **map, t_mapinfo mapinfo, int y, int x)
{
	if (map[y][x].c == '0' || map[y][x].c == 'N' || map[y][x].c == 'S'
		|| map[y][x].c == 'E' || map[y][x].c == 'W')
	{
		if (y == 0 || x == 0 || y == mapinfo.rows - 1 || x == mapinfo.colomns - 1)
			return (0);
		if (y > 0 && map[y - 1][x].c == 32)
			return (0);
		if (x > 0 && map[y][x - 1].c == 32)
			return (0);
		if (y < mapinfo.rows && map[y + 1][x].c == 32)
			return (0);
		if (x > mapinfo.colomns && map[y][x + 1].c == 32)
			return (0);
	}
	return (1);
}

int	check_char(char c)
{
	if (c == 'W' || c == 'N' || c == 'S' || c == 'E')
		return (1);
	return (0);
}

int	valid_map(t_map **map, t_mapinfo mapinfo)
{
	int	y;
	int	x;
	int	player;

	player = 0;
	y = 0;
	if (mapinfo.rows < 3 || mapinfo.colomns < 3)
		return (0);
	while (y < mapinfo.rows)
	{
		x = -1;
		while (++x < mapinfo.colomns)
		{
			if (!check_open(map, mapinfo, y, x))
				return (0);
			player += check_char(map[y][x].c);
		}
		y++;
	}
	if (player != 1)
		return (0);
	return (1);
}*/
