#include "../inc/cub3d.h"

/*
	Alles wat ge zou moeten hebben om dit aan te passen sta in de t_data struct.
	De prototype zou er dan zo uitzien: 
		void change_position(t_data *data, int x);
		void rotate_player(t_data *data, int x);

*/

/*void	change_position(t_player *player, int x) //you really need to think a bit more about this, lol
{
	if (x == 119)//up
	{
		player->position.x += player->direction.x * MOVESPEED;
		player->position.y += player->direction.y * MOVESPEED;
	}
	if (x == 115)//down
	{
		player->position.x -= player->direction.x * MOVESPEED;
		player->position.y -= player->direction.y * MOVESPEED;
	}
	if (x == 97)//strafe left
	{
		player->position.x += player->plane.x * ROTSPEED;
		player->position.y += player->plane.y * ROTSPEED;

	}
	if (x == 100)//strafe right
	{
		player->position.x -= player->plane.x * ROTSPEED;
		player->position.y -= player->plane.y * ROTSPEED;
	}
}

void	rotate_player(t_player *player,	int x)
{
	(void)player;
	(void)x;

}*/

void	update_player(t_data *data)
{
	data->mlx = mlx_init();
	init_window(data);
	draw_screen(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
//	mlx_loop_hook(win_data.mlx, 
//	mlx_key_hook(win_data.mlx_win, handle_input, &win_data);
	mlx_loop(data->mlx);



}

/*w = 119
  s = 115
  a = 97
  d = 100
  <- = 65361
  -> = 65363
*/