

#include "../inc/cub3d.h"

void	init_data_default(t_data *data)
{
	int	i;

	data->mlx = NULL;
	data->mlx_win = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->endian = 0;
	data->line_length = 0;
	init_player_default(&data->player);
	while (i < WIDTH)
	{
		init_rc_default(&data->rc[i]);
		i++;
	}
	init_mapinfo_default(&data->mapinfo);
}

void	init_player_default(t_player *player)
{
	player->position.x = 0;
	player->position.y = 0;
	player->direction.x = 0;
	player->direction.y = 0;
	player->plane.x = 0;
	player->plane.y = 0;
}

void	init_rc_default(t_raycaster *rc)
{
	rc->camera_x = 0.0;
	rc->raydirx = 0.0;
	rc->raydiry = 0.0;
	rc->sidedistx = 0.0;
	rc->sidedisty = 0.0;
	rc->deltadistx = 0.0;
	rc->deltadisty = 0.0;
	rc->stepx = 0;
	rc->stepy = 0;
	rc->mapx = 0;
	rc->mapy = 0;
	rc->side = 0;
	rc->perpwalldist = 0.0;
	rc->lineheight = 0;
	rc->drawstart = 0;
	rc->drawend = 0;
	rc->x = 0;
}

void	init_mapinfo_default(t_mapinfo *mapinfo)
{
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->f = 0;
	map->c = 0;
	map->rows = 0;
	map->columns = 0;
	map->map = NULL;
}
	