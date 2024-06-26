#include "../inc/cub3d.h"

void	setup_ray_dir(new_t_data *data, int x)
{
	data->rc.x = x;
	data->rc.camera_x = 2 * x / (double)WIDTH - 1;
	if (data->rc.camera_x == 0)
		data->rc.camera_x = 2 * (x - 1) / (double)WIDTH - 1;//hardcoded af. run tests if this doesn't give issues elsewhere. Check with other students how they fixed it
	data->rc.raydirx = data->player.direction.x + data->player.plane.x * data->rc.camera_x;
	data->rc.raydiry = data->player.direction.y + data->player.plane.y * data->rc.camera_x;
	//init_tile_traversal(rc, player->position.x, player->position.y);
}

void	init_raycasting(new_t_data *data)
{
	int x;

	x = 0;
	while (x < WIDTH)
	{
		setup_ray_dir(data[x], x);
		x++;
	}
}