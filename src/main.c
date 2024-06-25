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
		print_rc(&data->rc[i]);
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

	if (argc != 2)
		ft_error("Wrong number of arguments. Try again!\n");
	else if (!(map_name(argv[1])))
		ft_error("Hmmmm. Map should end with .cub. Can you make sure of that please?\n");
	else
	{
		init_data_default(&data);
		print_data(&data);
	}
}
