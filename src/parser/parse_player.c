#include "../../inc/cub3d.h"

void	parse_plane(new_t_data *data, char c)
{
	if (c == 'N')
	{
		(*data).player.plane.x = -0.66;
		(*data).player.plane.y = 0;
	}	
	if (c == 'E')
	{
		(*data).player.plane.x = 0;
		(*data).player.direction.y = 0.66;
	}	
	if (c == 'S')
	{
		(*data).player.plane.x = 0.66;
		(*data).player.plane.y = 0;
	}
	if (c == 'W')
	{
		(*data).player.plane.x = 0;
		(*data).player.plane.y = -0.66;
	}
}

void	parse_direction(new_t_data *data, char c)
{
	if (c == 'N')
	{
		(*data).player.direction.x = 0;
		(*data).player.direction.y = -1;
	}	
	if (c == 'E')
	{
		(*data).player.direction.x = 1;
		(*data).player.direction.y = 0;
	}	
	if (c == 'S')
	{
		(*data).player.direction.x = 0;
		(*data).player.direction.y = 1;
	}
	if (c == 'W')
	{
		(*data).player.direction.x = -1;
		(*data).player.direction.y = 0;
	}
}

void	find_player(new_t_data *data)
{
	int	x;
	int	y;
	new_t_map	**map;

	y = -1;
	map = data->mapinfo.map;
	while (++y < data->mapinfo.rows)
	{
		x = -1;
		while (++x < data->mapinfo.columns)
		{
			if ((map[y][x].c) != '0' && map[y][x].c != '1' && map[y][x].c != ' ')
			{
				(*data).player.position.x = x + 0.5;
				(*data).player.position.y = y + 0.5;
				parse_direction(data, map[y][x].c);
				parse_plane(init_data_default, map[y][x].c);
				return ;
			}
		}
	}
}

void	parse_player(new_t_data *data)//we can probably leave this out
{
	find_player(data);
//	test_player(*player);//	
}