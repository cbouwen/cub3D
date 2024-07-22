#include "../inc/cub3d.h"

void	calculate_lineheight(t_raycaster *rc, int side)
{
	if (side == 0)
		rc->perpwalldist = (rc->sidedistx - rc->deltadistx);
	else
		rc->perpwalldist = (rc->sidedisty - rc->deltadisty);
	rc->lineheight = (int)(HEIGHT / rc->perpwalldist);
	rc->drawstart = -rc->lineheight / 2 + HEIGHT / 2 - 1;
	if (rc->drawstart < 0)
		rc->drawstart = 0;
	rc->drawend = rc->lineheight / 2 + HEIGHT / 2;
	if (rc->drawend >= HEIGHT)
		rc->drawend = HEIGHT;
}

void	calculate_dda(t_raycaster *rc, t_map **map)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (rc->sidedistx < rc->sidedisty)
		{
			rc->sidedistx += rc->deltadistx;
			rc->mapx += rc->stepx;
			rc->side = 0;
		}
		else
		{
			rc->sidedisty += rc->deltadisty;
			rc->mapy += rc->stepy;
			rc->side = 1;
		}
		if (map[rc->mapy][rc->mapx].c == '1')
			hit = 1;
	}
	calculate_lineheight(rc, rc->side);
}

void	prep_dda(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		calculate_dda(&data->rc[x], data->mapinfo.map);
		x++;
	}
}

void	execute_map(t_data *data)
{
	data->mlx = mlx_init();
	init_window(data);
	parse_texture(data);
	parse_player(data);
	init_raycasting(data);
	prep_dda(data);
	update_player(data);
}
