/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:41:59 by cbouwen           #+#    #+#             */
/*   Updated: 2024/04/10 17:28:09 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	**mapinfo;

	if (argc != 2)
		ft_error("Wrong number of arguments. Try again!");
	get_mapinfo(argv[1], &mapinfo);
//	if (!(valid_map(fd, &map)))
//		ft_error("Invalid map. Try again!");
	//run_cub3d(map);
	close(fd);

}
