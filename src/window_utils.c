#include "../inc/cub3d.h"

void	my_mlx_pixel_put(new_t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int  handle_input(int key, new_t_data *data)
{
    if (key == 119)
        printf("w is pressed\n\n");//move_player(&player, key);
    if (key == 115)
        printf("s is pressed\n\n");
    if (key == 97)
        printf("a is pressed\n\n");
    if (key == 100)
        printf("d is pressed\n\n");
    if (key == 65361)
        printf("Left arrow is pressed\n\n");//rotate_player(&player, key);
    if (key == 65363)
        printf("Right arrow is pressed\n\n");
    if (key == 65307)
        close_window(data);
//	update_player(win_data, key);      We need to call a function here which performs the dda with the new player data changed by the above key presses and afterwards prints it on the screen as well
    return (0);
}

int	close_window(new_t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (1);
}

void	init_window(new_t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3D");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	//mlx_put_image_to_window(win_data->mlx, win_data->mlx_win, win_data->img.img, 0, 0);
	mlx_hook(data->mlx_win, 17, 1L<<17, &close_window, data);
	mlx_key_hook(data->mlx_win, handle_input, data);
}

void	draw_screen(new_t_data *data)//LodeV mentioned that for textures we can't do lines anymore. This means we need a nested loop here. no big changes
{
	int	x;

	x = -1;
	while (++x < WIDTH)
		load_texture(&data->rc[x], data->rc[x].side, data);
}

void	load_texture(new_t_raycaster *rc, int side, new_t_data *data) //change colors with textures. Add line for Ceiling and Floor. Maybe move this to utils?
{
	int	y;
	int	color;

	if (side == 1)
		color = 16711680;
	else
		color = 16743936;
	y = -1;
	while (++y < HEIGHT)
	{
		if (y < HEIGHT / 2)	//not super efficient because it constantly overwrites but hey. If we want, easy fix
			my_mlx_pixel_put(data, rc->x, y, data->mapinfo.c);
		if (y > HEIGHT / 2)
			my_mlx_pixel_put(data, rc->x, y, data->mapinfo.f);
		if (y > rc->drawstart && y < rc->drawend)
			my_mlx_pixel_put(data, rc->x, y, color);
	}
}