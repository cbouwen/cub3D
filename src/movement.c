#include "../inc/cub3d.h"

void	move(t_player *player, t_map **map, int x)
{
	if (x == 119)//up
	{
		if (map[(int)(player->position.y)][(int)(player->position.x + player->direction.x * MOVESPEED)].c != '1')
			player->position.x += player->direction.x * MOVESPEED;
		if (map[(int)(player->position.y + player->direction.y * MOVESPEED)][(int)(player->position.x)].c != '1')
			player->position.y += player->direction.y * MOVESPEED;
	}
	if (x == 115)//down
	{
		if (map[(int)(player->position.y)][(int)(player->position.x - player->direction.x * MOVESPEED)].c != '1')
			player->position.x -= player->direction.x * MOVESPEED;
		if (map[(int)(player->position.y - player->direction.y * MOVESPEED)][(int)(player->position.x)].c != '1')
			player->position.y -= player->direction.y * MOVESPEED;
	}
}

void	strafe(t_player *player, t_map **map, int x)
{
	if (x == 100)//strafe left
	{
		if (map[(int)player->position.y][(int)(player->position.x + player->plane.x * MOVESPEED)].c != '1')
			player->position.x += player->plane.x * MOVESPEED;
		if (map[(int)(player->plane.y + player->direction.y * MOVESPEED)][(int)player->position.x].c != '1')
			player->position.y += player->plane.y * MOVESPEED;
	}
	if (x == 97)//strafe right
	{
		if (map[(int)player->position.y][(int)(player->position.x - player->plane.x * MOVESPEED)].c != '1')
			player->position.x -= player->plane.x * MOVESPEED;
		if (map[(int)(player->position.y - player->plane.y * MOVESPEED)][(int)player->position.x].c != '1')
			player->position.y -= player->plane.y * MOVESPEED;
	}
}

void	rotate_player(t_player *player,	int x)
{
	double	olddirx;
	double	oldplanex;

	olddirx = player->direction.x;
	oldplanex = player->plane.x;
	if (x == 65363)//rotate right
	{
		player->direction.x = player->direction.x * cos(-ROTSPEED) - player->direction.y * sin(-ROTSPEED);
		player->direction.y = olddirx * sin(-ROTSPEED) + player->direction.y * cos(-ROTSPEED);
		player->plane.x = player->plane.x * cos(-ROTSPEED) - player->plane.y * sin(-ROTSPEED);
		player->plane.y = oldplanex * sin(-ROTSPEED) + player->plane.y * cos(-ROTSPEED);
	}
	else //rotate left
	{
		player->direction.x = player->direction.x * cos(ROTSPEED) - player->direction.y * sin(ROTSPEED);
		player->direction.y = olddirx * sin(ROTSPEED) + player->direction.y * cos(ROTSPEED);
		player->plane.x = player->plane.x * cos(ROTSPEED) - player->plane.y * sin(ROTSPEED);
		player->plane.y = oldplanex * sin(ROTSPEED) + player->plane.y * cos(ROTSPEED);
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
