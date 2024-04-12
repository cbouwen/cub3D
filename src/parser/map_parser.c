/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:10:31 by cbouwen           #+#    #+#             */
/*   Updated: 2024/04/12 12:39:10 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	check_input(char *str, t_mapinfo *mapinfo, t_mapchecker *elements)
{
	int	i;

	i = 0;
	while (str[i] == 32)
		i++;
	while (str[i])
	{
		//if (str[i] == EA or whatever do parse_path or parse_color
	}

}

void    init_map_checker(t_mapchecker *elements)  //utils?
{
    elements->NO = false;
    elements->SO = false;
    elements->WE = false;
    elements->EA = false;
    elements->F = false;
    elements->C = false;
    elements->duplicate = false;
    elements->all_eles = false;
}

void	parse_map(int fd, t_mapinfo *mapinfo)
{
	char	*line;
	t_mapchecker	elements;

	init_map_checker(&elements);
	line = get_next_line(fd);
	while (line)
	{
		check_input(line, mapinfo, &elements);
		free(line);
		line = get_next_line(fd);
	}
	free(line);

}



int	parse_cub(char *argv, t_mapinfo *mapinfo)
{
	if (!(fd = open(argv, O_RDONLY)))
		ft_error("Error opening map.. Weird. Try again!");
	parse_map(fd, mapinfo);

	close(fd);
}
