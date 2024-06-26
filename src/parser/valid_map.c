#include "../../inc/cub3d.h"

int	check_open(new_t_data *data, int y, int x)
{
	if (data->mapinfo.map[y][x].c == '0' || data->mapinfo.map[y][x].c == 'N' || data->mapinfo.map[y][x].c == 'S'
		|| data->mapinfo.map[y][x].c == 'E' || data->mapinfo.map[y][x].c == 'W')
	{
		if (y == 0 || x == 0 || y == data->mapinfo.rows - 1 || x == data->mapinfo.colomns - 1)
			return (0);
		if (y > 0 && data->mapinfo.map[y - 1][x].c == 32)
			return (0);
		if (x > 0 && data->mapinfo.map[y][x - 1].c == 32)
			return (0);
		if (y < data->mapinfo.rows && data->mapinfo.map[y + 1][x].c == 32)
			return (0);
		if (x > data->mapinfo.colomns && data->mapinfo.map[y][x + 1].c == 32)
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

int	valid_map(new_t_data *data)
{
	int	y;
	int	x;
	int	player;

	player = 0;
	y = 0;
	if (data->mapinfo.rows < 3 || data->mapinfo.colomns < 3)
		return (0);
	while (y < data->mapinfo.rows)
	{
		x = -1;
		while (++x < data->mapinfo.colomns)
		{
			if (!check_open(data, y, x))
				return (0);
			player += check_char(data->mapinfo.map[y][x].c);
		}
		y++;
	}
	if (player != 1)
		return (0);
	return (1);
}