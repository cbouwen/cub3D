/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:56:48 by cbouwen           #+#    #+#             */
/*   Updated: 2024/06/21 13:43:36 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	parse_direction(t_player *player, char c)
{
	if (c == 'N')
	{
		(*player).direction.x = 0;
		(*player).direction.y = -1;
	}	
	if (c == 'E')
	{
		(*player).direction.x = 1;
		(*player).direction.y = 0;
	}	
	if (c == 'S')
	{
		(*player).direction.x = 0;
		(*player).direction.y = 1;
	}
	if (c == 'W')
	{
		(*player).direction.x = -1;
		(*player).direction.y = 0;
	}
}

void	parse_plane(t_player *player, char c)
{
	if (c == 'N')
	{
		(*player).plane.x = -0.66;
		(*player).plane.y = 0;
	}	
	if (c == 'E')
	{
		(*player).plane.x = 0;
		(*player).direction.y = 0.66;
	}	
	if (c == 'S')
	{
		(*player).plane.x = 0.66;
		(*player).plane.y = 0;
	}
	if (c == 'W')
	{
		(*player).plane.x = 0;
		(*player).plane.y = -0.66;
	}
}

void	find_player(int rows, int colomns, t_map **map, t_player *player)
{
	int	x;
	int	y;

	y = -1;
	while (++y < rows)
	{
		x = -1;
		while (++x < colomns)
		{
			if ((map[y][x].c) != '0' && map[y][x].c != '1' && map[y][x].c != ' ')
			{
				(*player).position.x = x + 0.5;
				(*player).position.y = y + 0.5;
				parse_direction(player, map[y][x].c);
				parse_plane(player, map[y][x].c);
				return ;
			}
		}
	}
}

void	parse_player(t_mapinfo mapinfo, t_map **map, t_player *player)//we can probably leave this out
{
	find_player(mapinfo.rows, mapinfo.colomns, map, player);
//	test_player(*player);//	
}
