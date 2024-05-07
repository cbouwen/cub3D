	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:41:59 by cbouwen           #+#    #+#             */
/*   Updated: 2024/05/07 16:57:23 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_mapinfo		mapinfo;
	t_map			**map;

	//	int		fd;
	if (argc != 2)
		ft_error("Wrong number of arguments. Try again!");
	else if (!(map_name(argv[1])))
		ft_error("Hmmmm. Map should end with .cub. Can you make sure of that please?");
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
	//	close(fd);
}
