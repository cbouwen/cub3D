#include "../inc/cub3d.h"

void	update_player(new_t_data *data)
{
	data->mlx = mlx_init();
	init_window(data);
	//draw_screen(rc, &win_data.img, mapinfo);
	//mlx_put_image_to_window(win_data.mlx, win_data.mlx_win, win_data.img.img, 0, 0);
//	mlx_loop_hook(win_data.mlx, 
//	mlx_key_hook(win_data.mlx_win, handle_input, &win_data);
	mlx_loop(win_data.mlx);



}

/*w = 119
  s = 115
  a = 97
  d = 100
  <- = 65361
  -> = 65363
*/