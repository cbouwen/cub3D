/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:41:59 by cbouwen           #+#    #+#             */
/*   Updated: 2024/04/19 16:25:47 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_mapinfo	mapinfo;

	//	int		fd;
	if (argc != 2)
		ft_error("Wrong number of arguments. Try again!");
	if (!(map_name(argv[1])))
		ft_error("Hmmmm. Map should end with .cub. Can you make sure of that please?");
	if (parse_cub(argv[1], &mapinfo) == 1)
		ft_error("Duplicate map arguments.");
	//	if (!(valid_map(fd, &map)))
	//		ft_error("Invalid map. Try again!");
	//run_cub3d(map);
	//	close(fd);
}
