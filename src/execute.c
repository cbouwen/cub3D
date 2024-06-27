#include "../inc/cub3d.h"

void	calculate_lineheight(t_raycaster *rc, int side) //Will this work? FT for avoiding fisheye. This calculates the line coming from the camera plane instead of position.
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
	//printf("\n\nLineheight = %i\nDrawstart = %i\nDrawend = %i\n", raycaster.lineheight,raycaster.drawstart, raycaster.drawend);
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
	calculate_lineheight(rc, rc->side);
//	if (rc->x % 100 == 0)//for testing purposes. can be deleted
//		print_rc(*rc);
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

void execute_map(t_data *data)
{
	parse_player(data);
	init_raycasting(data);
	prep_dda(data);
	update_player(data);//Final step*/
}
