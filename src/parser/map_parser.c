/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:10:31 by cbouwen           #+#    #+#             */
/*   Updated: 2024/04/22 15:48:48 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	parse_path(char *str, t_mapinfo *mapinfo)
{
	size_t	i;

	i = 0;
	while (str[i + 3] && (str[i + 3] != 32 && str[i + 3] != '\n'))
		i++;
	if (str[0] == 'N')
		mapinfo->NO = ft_strndup(str + 3, i);
	else if (str[0] == 'S')
		mapinfo->SO = ft_strndup(str + 3, i);
	else if (str[0] == 'W')
		mapinfo->WE = ft_strndup(str + 3, i);
	else if (str[0] == 'E')
		mapinfo->EA = ft_strndup(str + 3, i);
}

void	parse_color(char *str, t_mapinfo *mapinfo)
{
	int	i;

	i = 2;
	while (str[i] == 32)
		i++;
	if (str[0] == 'F')
	{
		mapinfo->F.red = ft_atoi(str + i);
		while (str[i] != 44)
			i++;
		mapinfo->F.green = ft_atoi(str + ++i);
		while (str[i] != 44)
			i++;
		mapinfo->F.blue = ft_atoi(str + ++i);
	}
	else
	{
		mapinfo->C.red = ft_atoi(str + i);
		while (str[i] != 44)
			i++;
		mapinfo->C.green = ft_atoi(str + ++i);
		while (str[i] != 44)
			i++;
		mapinfo->C.blue = ft_atoi(str + ++i);
	}
	//check for overflow after parse?
}

void	check_input(char *str, t_mapinfo *mapinfo, t_mapchecker *elements)
{
	int	i;

	i = 0;
	while (str[i] == 32)
		i++;
	while (str[i])
	{
		if (!ft_strncmp(str + i, "F ", 2) || !ft_strncmp(str + i, "C ", 2))
		{
			parse_color(str + i, mapinfo);
			update_mapchecker(str + i, elements);
		}
		if (!ft_strncmp(str + i, "NO ", 3) || !ft_strncmp(str + i, "SO ", 3)
			|| !ft_strncmp(str + i, "WE ", 3) || !ft_strncmp(str + i, "EA ", 3))
		{
			parse_path(str + i, mapinfo);
			update_mapchecker(str + i, elements);
		}
		i++;
	}
}

void	parse_map(int fd, t_mapinfo *mapinfo, t_mapchecker *elements)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		check_input(line, mapinfo, elements);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

int	parse_cub(char *argv, t_mapinfo *mapinfo)
{
	t_mapchecker	elements;
	int				fd;

	init_map_checker(&elements);
	if (!(fd = open(argv, O_RDONLY)))
		ft_error("Error opening map.. Weird. Try again!");
	parse_map(fd, mapinfo, &elements);
	close(fd);
	if (elements.duplicate == true)
		return (1);
	tester(*mapinfo); //remove later
	return (0);
}
