	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:41:59 by cbouwen           #+#    #+#             */
/*   Updated: 2024/06/12 15:54:32 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void print_player(new_t_player *player)
{
	printf("position.x: %f\n", player->position.x);
	printf("position.y: %f\n", player->position.y);
	printf("direction.x: %f\n", player->direction.x);
	printf("direction.y: %f\n", player->direction.y);
	printf("plane.x: %f\n", player->plane.x);
	printf("plane.y: %f\n", player->plane.y);
}

void print_mapinfo(new_t_mapinfo *mapinfo)
{
	printf("no: %s\n", mapinfo->no);
	printf("so: %s\n", mapinfo->so);
	printf("we: %s\n", mapinfo->we);
	printf("ea: %s\n", mapinfo->ea);
	printf("f: %d\n", mapinfo->f);
	printf("c: %d\n", mapinfo->c);
	printf("rows: %d\n", mapinfo->rows);
	printf("columns: %d\n", mapinfo->columns);
	printf("map: %p\n", mapinfo->map);
}

void	print_rc_new(new_t_raycaster *rc)
{
	printf("x = %i\n", rc->x);
	printf("camera_x = %f\n", rc->camera_x);
	printf("raydirx = %f\n", rc->raydirx);
	printf("raydiry = %f\n", rc->raydiry);
	printf("sidedistx = %f\n", rc->sidedistx);
	printf("sidedisty = %f\n", rc->sidedisty);
	printf("deltadistx = %f\n", rc->deltadistx);
	printf("deltadisty = %f\n", rc->deltadisty);
	printf("stepx = %i\n", rc->stepx);
	printf("stepy = %i\n", rc->stepy);
	printf("mapx = %i\n", rc->mapx);
	printf("mapy = %i\n", rc->mapy);
	printf("side = %i\n", rc->side);
	printf("perpwalldist = %f\n", rc->perpwalldist);
	printf("lineheight = %i\n", rc->lineheight);
	printf("drawstart = %i\n", rc->drawstart);
	printf("drawend = %i\n", rc->drawend);
}

void print_data(new_t_data *data)
{
	printf("mlx: %p\n", data->mlx);
	printf("mlx_win: %p\n", data->mlx_win);
	printf("img: %p\n", data->img);
	printf("addr: %p\n", data->addr);
	printf("bits_per_pixel: %d\n", data->bits_per_pixel);
	printf("endian: %d\n", data->endian);
	printf("line_length: %d\n", data->line_length);
	print_player(&data->player);
	int i = 0;
	while (i < 3)
	{
		print_rc_new(&data->rc[i]);
		i++;
	}
	print_mapinfo(&data->mapinfo);
}

int	main(int argc, char **argv)
{
	/*t_mapinfo		mapinfo;
	t_map			**map;

	//	int		fd;
	if (argc != 2)
		ft_error("Wrong number of arguments. Try again!\n");
	else if (!(map_name(argv[1])))
		ft_error("Hmmmm. Map should end with .cub. Can you make sure of that please?\n");
	else
	{
		mapinfo.rows = 0;
		mapinfo.colomns = 0;
		parse_cub(argv[1], &mapinfo, &map);//error exit check?
		execute_map(&map, mapinfo);
	}
	//	if (!(valid_map(fd, &map)))
	//		ft_error("Invalid map. Try again!");
	//run_cub3d(map);
	//	close(fd);*/

	new_t_data	data;

	t_mapinfo		mapinfo;
	t_map			**map;

	if (argc != 2)
		ft_error("Wrong number of arguments. Try again!\n");
	else if (!(map_name(argv[1])))
		ft_error("Hmmmm. Map should end with .cub. Can you make sure of that please?\n");
	else
	{
		init_data_default(&data);
		//old ==> parse_cub(argv[1], &mapinfo, &map);//error exit check?
		parse_cub(argv[1], &data);//error exit check?
		print_mapinfo(&data.mapinfo);
	}
}
