/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:12:51 by cbouwen           #+#    #+#             */
/*   Updated: 2024/08/14 12:06:25 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	set_remainder(t_data *data, int *x, int y)
{
	while (*x < data->mapinfo.columns)
	{
		data->mapinfo.map[y][*x].c = 32;
		(*x)++;
	}
}

void	fill_map(int fd, t_data *data)
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
	while (++y < data->mapinfo.rows)
	{
		x = -1;
		while (++x < data->mapinfo.columns)
		{
			data->mapinfo.map[y][x].x = x;
			data->mapinfo.map[y][x].y = y;
			data->mapinfo.map[y][x].c = line[x];
			if (line[x] == '\n')
				set_remainder(data, &x, y);
		}
		free(line);
		line = get_next_line(fd);
	}
}

t_map	**init_map(t_data *data)
{
	t_map	**map;
	int		i;

	i = 0;
	map = (t_map **)malloc(sizeof(t_map *) * data->mapinfo.rows);
	if (!map)
		ft_error("Malloc fail!\n", data);
	while (i < data->mapinfo.rows)
	{
		map[i] = (t_map *)malloc(sizeof(t_map) * data->mapinfo.columns);
		if (!map[i])
		{
			ft_free_array(map, i);
			ft_error("Malloc fail!\n", data);
		}
		i++;
	}
	return (map);
}

void	misconfigured_map(t_map **map, t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->mapinfo.rows)
	{
		x = -1;
		while (++x < data->mapinfo.columns)
		{
			if (map[y][x].c != '1' && map[y][x].c != '0' && map[y][x].c != 'W' && map[y][x].c !=  'E' && map[y][x].c != 'N' && map[y][x].c != 'S' && map[y][x].c!= ' ')
				ft_error("Map is misconfigured\n", data);
		}
	}
}


void	parse_map(int fd, t_data *data)
{
	data->mapinfo.map = init_map(data);
	fill_map(fd, data);
	if (!valid_map(data))
		ft_error("Invalid map\n", data);
	misconfigured_map(data->mapinfo.map, data);
}
