#include "../inc/cub3d.h"

int	check_collision(t_data *data, int x)
{
	if (x == 119)//up
	{
		if (data->map[(int)data->player.position.x + data->player.direction.x * MOVESPEED][(int)data->player.position.y] == '1')

	}
	if (x == 115)//down
	{
		player->position.x -= player->direction.x * MOVESPEED;
		player->position.y -= player->direction.y * MOVESPEED;
	}
	if (x == 100)//strafe left
	{
		player->position.x += player->plane.x * MOVESPEED;
		player->position.y += player->plane.y * MOVESPEED;

	}
	if (x == 97)//strafe right
	{
		player->position.x -= player->plane.x * MOVESPEED;
		player->position.y -= player->plane.y * MOVESPEED;
	}
}

void	change_position(t_player *player, int x)
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
	if (x == 100)//strafe left
	{
		player->position.x += player->plane.x * MOVESPEED;
		player->position.y += player->plane.y * MOVESPEED;

	}
	if (x == 97)//strafe right
	{
		player->position.x -= player->plane.x * MOVESPEED;
		player->position.y -= player->plane.y * MOVESPEED;
	}
}

void	rotate_player(t_player *player,	int x)
{
	if (x == 65363)//rotate right
	{
		player->direction.y = player->direction.x * sin(-ROTSPEED) + player->direction.y * cos(-ROTSPEED);
		player->direction.x = player->direction.x * cos(-ROTSPEED) - player->direction.y * sin(-ROTSPEED);
		player->plane.y = player->plane.x * sin(-ROTSPEED) + player->plane.y * cos(-ROTSPEED);
		player->plane.x = player->plane.x * cos(-ROTSPEED) - player->plane.y * sin(-ROTSPEED);
	}
	else //rotate left
	{
		player->direction.y = player->direction.x * sin(ROTSPEED) + player->direction.y * cos(ROTSPEED);
		player->direction.x = player->direction.x * cos(ROTSPEED) - player->direction.y * sin(ROTSPEED);
		player->plane.y = player->plane.x * sin(ROTSPEED) + player->plane.y * cos(ROTSPEED);
		player->plane.x = player->plane.x * cos(ROTSPEED) - player->plane.y * sin(ROTSPEED);
	}
}

void	update_player(t_data *data)
{
	data->mlx = mlx_init();
	init_window(data);
	draw_screen(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	mlx_loop(data->mlx);
}
