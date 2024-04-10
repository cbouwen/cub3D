/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:24:28 by cbouwen           #+#    #+#             */
/*   Updated: 2024/04/10 17:25:22 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	get_line_length(int	fd)
{
	int	i;


	return (i);
}

void	init_mapinfo(int rows, char ***mapinfo);
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	*mapinfo = (char **)malloc(sizeof(char *) * rows);
	if (!mapinfo)
		ft_free(mapinfo);
	while (i <  rows)
	{
		j =  get_line_length(fd); //fd?
		mapinfo[i] = (char *)malloc(sizeof(char) * j);


		i++;
	}
}

void	get_rows(int fd, int *rows)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		ft_free(mapinfo);
	while (line)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}
}


int	get_mapinfo(char *argv, char ***mapinfo)
{
	int	rows;
	int	fd;

	if (!(fd = open(argv, O_RDONLY)))
		ft_error ("Error opening map.. Weird. Try again!");
	rows = 0;
	get_rows(fd, &rows);
	close(fd);
	init_mapinfo(rows, mapinfo);
	if (!(fd = open(argv, O_RDONLY)))
		ft_error ("Error opening map.. Weird. Try again!");
	


	return (1);
}
