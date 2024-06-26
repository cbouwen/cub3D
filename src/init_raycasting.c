#include "../inc/cub3d.h"

void	setup_ray_dir(new_t_player *rc, new_t_player *player, int x)
{
	rc->x = x;
	rc->camera_x = 2 * x / (double)WIDTH - 1;
	if (rc->camera_x == 0)
		rc->camera_x = 2 * (x - 1) / (double)WIDTH - 1;//hardcoded af. run tests if this doesn't give issues elsewhere. Check with other students how they fixed it
	rc->raydirx = player->direction.x + player->plane.x * rc->camera_x;
	rc->raydiry = player->direction.y + player->plane.y * rc->camera_x;
	//init_tile_traversal(rc, player->position.x, player->position.y);
}

void	init_raycasting(new_t_data *data)
{
	int x;

	x = 0;
	while (x < WIDTH)
	{
		setup_ray_dir(data->rc[x], data->player, x);
		x++;
	}
}