#include "../inc/cub3d.h"

void	init_tile_traversal(t_raycaster *rc, double posx, double posy)
{
	rc->mapx = posx;
	rc->mapy = posy;
	if (rc->raydirx == 0.0)
		rc->raydirx = 1e30;
	if (rc->raydiry == 0.0)
		rc->raydiry = 1e30;
	rc->deltadistx = fabs(1.0 / rc->raydirx);
	rc->deltadisty = fabs(1.0 / rc->raydiry);
	/*define_step(rc, posx, posy);
	if (rc->raydirx == 1e30)
		rc->raydirx = 0.0;
	if (rc->raydiry == 1e30)
		rc->raydiry = 0.0;*/
}

void	setup_ray_dir(new_t_raycaster *rc, new_t_player *player, int x)
{
	rc->x = x;
	rc->camera_x = 2 * x / (double)WIDTH - 1;
	if (rc->camera_x == 0)
		rc->camera_x = 2 * (x - 1) / (double)WIDTH - 1;//hardcoded af. run tests if this doesn't give issues elsewhere. Check with other students how they fixed it
	rc->raydirx = player->direction.x + player->plane.x * rc->camera_x;
	rc->raydiry = player->direction.y + player->plane.y * rc->camera_x;
	init_tile_traversal(rc, player->position.x, player->position.y);
}

void	init_raycasting(new_t_data *data)
{
	int x;

	x = 0;
	while (x < WIDTH)
	{
		setup_ray_dir(&data->rc[x], &data->player, x);
		x++;
	}
}