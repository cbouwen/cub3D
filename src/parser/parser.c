/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:31:22 by cbouwen           #+#    #+#             */
/*   Updated: 2024/08/14 12:13:23 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	map_errors(t_mapchecker *elements, t_data *data)
{
	if (elements->all_eles == false)
		ft_error("Not all elements defined before map initialization.\n", data);
	if (elements->duplicate == true)
		ft_error("Duplicate map arguments.\n", data);
}

void	parse_mapinfo(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (data->mapinfo.columns < i - 1)
		data->mapinfo.columns = i - 1;
	data->mapinfo.rows++;
}

void	parse_input(int fd, t_data *data, t_mapchecker *elements)
{
	char	*line;
	int		error;

	error = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (check_for_map(line) == 1)
			break ;
		error += check_input(line, data, elements, fd);
		free(line);
		line = get_next_line(fd);
	}
	while (line) //&& check_for_map(line) == 1)
	{
		parse_mapinfo(line, data);
		free(line);
		line = get_next_line(fd);
	}
	if (error != 0)
		ft_error("Unknown key\n", data);
}

int	parse_cub(char *argv, t_data *data)
{
	t_mapchecker	elements;
	int				fd;

	init_map_checker(&elements);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Error opening map.. Weird. Try again!\n", data);
	parse_input(fd, data, &elements);
	close(fd);
	map_errors(&elements, data);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Error opening map.. Weird. Try again!\n", data);
	parse_map(fd, data);
	close(fd);
	return (0);
}
