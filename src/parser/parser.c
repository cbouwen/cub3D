/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:10:31 by cbouwen           #+#    #+#             */
/*   Updated: 2024/06/21 12:55:03 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	color_range(int	x)
{
	if (x < 0)
		return (0);
	if (x > 16777215)
		return (0);
	return (1);
}

void	map_errors(t_mapchecker elements, t_mapinfo mapinfo)
{
	if (elements.all_eles == false)
		ft_error("Not all elements are defined before map initialization.\n");
	if (elements.duplicate == true)
		ft_error("Duplicate map arguments.\n");
	if (!color_range(mapinfo.c))
		ft_error("Wrong color ranges for ceiling\n");
	if (!color_range(mapinfo.f))
		ft_error("Wrong color ranges for floor\n");
}

void	parse_mapinfo(char *str, t_mapinfo *mapinfo)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (mapinfo->colomns < i - 1)
		mapinfo->colomns = i - 1;
	mapinfo->rows++;
}

void	parse_input(int fd, t_mapinfo *mapinfo, t_mapchecker *elements)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (check_for_map(line) == 1)
			break ;
		check_input(line, mapinfo, elements);
		free(line);
		line = get_next_line(fd);
	}
	while (line && check_for_map(line) == 1)
	{
		parse_mapinfo(line, mapinfo);
		free(line);
		line = get_next_line(fd);
	}
}

int	parse_cub(char *argv, new_t_data *data)
{
	t_mapchecker	elements;
	int				fd;

	init_map_checker(&elements); //keep the same, mapchecker is seperate from the main struct
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Error opening map.. Weird. Try again!\n");
	parse_input(fd, data->mapinfo, &elements);
	close(fd);
	map_errors(elements, data->mapinfo);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Error opening map.. Weird. Try again!\n");
	parse_map(fd, data->mapinfo, data->mapinfo);
	close(fd);
	tester(data->mapinfo); //remove later
	test_map(data->mapinfo, data->mapinfo);
	return (0);
}

int	_parse_cub(char *argv, t_mapinfo *mapinfo, t_map ***map)
{
	t_mapchecker	elements;
	int				fd;

	init_map_checker(&elements); //keep the same, mapchecker is seperate from the main struct
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Error opening map.. Weird. Try again!\n");
	parse_input(fd, mapinfo, &elements);
	close(fd);
	map_errors(elements, *mapinfo);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Error opening map.. Weird. Try again!\n");
	parse_map(fd, *mapinfo, map);
	close(fd);
	tester(*mapinfo); //remove later
	test_map(*map, *mapinfo);
	return (0);
}
