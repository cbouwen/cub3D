#include "../inc/cub3d.h"

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
			rc->side = 0; //look at comment under
		}
		else
		{
			rc->sidedisty += rc->deltadisty;
			rc->mapy += rc->stepy;
			rc->side = 1; //this is not enough. Add more rules for N, S, E and W   @Matisse: We need the right int here so we know what texture to project(N,S,E,W)
			//Edit: Maybe this is enough. Maybe with a combination of stepdirx or whatever value, we know which side we'll be facing. Either way this is for the end
		}
		if (map[rc->mapy][rc->mapx].c == '1')
			hit = 1;
	}
	//calculate_lineheight(rc, rc->side);
//	if (rc->x % 100 == 0)//for testing purposes. can be deleted
//		print_rc(*rc);
}

void	prep_dda(new_t_data *data)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		calculate_dda(&data->rc[x], data->mapinfo.map);
		x++;
	}
}

void execute_map(new_t_data *data)
{
	parse_player(data);
	init_raycasting(data);
	prep_dda(data);

	//update_player(raycaster, mapinfo);//Final step*/
}