/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:56:48 by cbouwen           #+#    #+#             */
/*   Updated: 2024/05/08 15:41:26 by cbouwen          ###   ########.fr       */
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

char	player_info(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (c);
	return (0);
}

void	find_player(int rows, int colomns, t_map **map, t_player *player)
{
	int	x;
	int	y;
	char direction;

	y = -1;
	while (++y < rows)
	{
		x = -1;
		while (++x < colomns)
		{
			if ((direction = player_info(map[y][x].c)) != 0)
			{
				(*player).position.x = x;
				(*player).position.y = y;
				parse_direction(player, direction);
				return ;
			}
		}
	}
}

void	parse_player(t_mapinfo mapinfo, t_map **map, t_player *player)
{
	find_player(mapinfo.rows, mapinfo.colomns, map, player);
	(*player).plane.x = 0;
	(*player).plane.y = 0.66;
//	test_player(*player);//	
}
