/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:33:26 by cbouwen           #+#    #+#             */
/*   Updated: 2024/04/23 15:39:18 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*void	set_remainder(t_map ***map, t_mapinfo mapinfo, int *x, int y)
{
	while (*x < mapinfo.colomns)
	{
		(*map)[y][*x].c = 32;
		(*x)++;
	}
}

void	fill_map(int fd, t_mapinfo mapinfo, t_map ***map)
{
	char	*line;
	int		y;
	int		x;

	line = get_next_line(fd);
	while (line && check_for_map(line) == 0)
	{
		free(line);
		line = get_next_line(fd);
	}
	y = -1;
	while (++y < mapinfo.rows)
	{
		x = -1;
		while (++x < mapinfo.colomns)
		{
			(*map)[y][x].x = x;
			(*map)[y][x].y = y;
			(*map)[y][x].c = line[x];
			if (line[x] == '\n')
				set_remainder(map, mapinfo, &x, y);
		}
		free(line);
		line = get_next_line(fd);
	}
}

t_map	**init_map(t_mapinfo mapinfo)
{
	t_map	**map;
	int		i;

	i = 0;
	map = (t_map **)malloc(sizeof(t_map *) * mapinfo.rows);
	if (!map)
		ft_free(&mapinfo);
	while (i < mapinfo.rows)
	{
		map[i] = (t_map *)malloc(sizeof(t_map) * mapinfo.colomns);
		if (!map[i])
		{
			ft_free_array(map, i);
			ft_free(&mapinfo);
		}
		i++;
	}
	return (map);
}

t_map	**parse_map(int fd, t_mapinfo mapinfo, t_map ***map)
{
	*map = init_map(mapinfo);
	fill_map(fd, mapinfo, map);
	if (!valid_map(*map, mapinfo))
		ft_error("Invalid map\n");
	return (*map);
}*/
