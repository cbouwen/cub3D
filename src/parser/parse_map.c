#include "../../inc/cub3d.h"

void	set_remainder(new_t_data *data, int *x, int y)
{
	while (*x < data->mapinfo.columns)
	{
		data->mapinfo.map[y][*x].c = 32;
		(*x)++;
	}
}

void	fill_map(int fd, new_t_data *data)
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

new_t_map	**init_map(new_t_data *data)
{
	new_t_map	**map;
	int		i;

	i = 0;
	map = (new_t_map **)malloc(sizeof(new_t_map *) * data->mapinfo.rows);
	if (!map)
		ft_free(&data->mapinfo);
	while (i < data->mapinfo.rows)
	{
		map[i] = (new_t_map *)malloc(sizeof(new_t_map) * data->mapinfo.columns);
		if (!map[i])
		{
			ft_free_array(data->mapinfo.map, i);
			ft_free(&data->mapinfo);
			printf("free map, not implemented");
		}
		i++;
	}
	return (map);
}

void	parse_map(int fd, new_t_data *data)
{
	data->mapinfo.map = init_map(data);
	fill_map(fd, data);
	if (!valid_map(data))
		ft_error("Invalid map\n");
	else
		printf("Map is valid\n");
}