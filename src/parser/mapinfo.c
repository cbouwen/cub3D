/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:55:36 by mlegendr          #+#    #+#             */
/*   Updated: 2024/07/31 16:45:19 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	parse_path(char *str, t_data *data)
{
	size_t	i;

	i = 0;
	while (str[i + 3] && (str[i + 3] != 32 && str[i + 3] != '\n'))
		i++;
	if (str[0] == 'N' && data->mapinfo.no == NULL)
		data->mapinfo.no = ft_strndup(str + 3, i);
	else if (str[0] == 'S' && data->mapinfo.so == NULL)
		data->mapinfo.so = ft_strndup(str + 3, i);
	else if (str[0] == 'W' && data->mapinfo.we == NULL)
		data->mapinfo.we = ft_strndup(str + 3, i);
	else if (str[0] == 'E' && data->mapinfo.ea == NULL)
		data->mapinfo.ea = ft_strndup(str + 3, i);
}

int	color_range(int red, int blue, int green)
{
	if (red < 0 || red > 255)
		return (0);
	if (blue < 0 || blue > 255)
		return (0);
	if (green < 0 || green > 255)
		return (0);
	return (1);
}

int	parse_color_values(int *X, char *str, int i)
{
	int	red;
	int	green;
	int	blue;
	int	error;

	error = 0;
	red = ft_atoi(str + i);
	while (str[i] != 44)
		i++;
	green = ft_atoi(str + ++i);
	while (str[i] != 44)
		i++;
	if (!(ft_isdigit(str[i + 1])))
		error = 1;
	blue = ft_atoi(str + ++i);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\n')
		error = 1;
	if (color_range(red, blue, green) == 0)
		error = 2;
	*X = (red << 16) | (green << 8) | blue;
	return (error);
}

void	parse_color(char *str, t_data *data, char *line, int fd)
{
	int	i;
	int	error;

	error = 0;
	i = 2;
	while (str[i] == 32)
		i++;
	if (str[0] == 'F')
		error += parse_color_values(&data->mapinfo.f, str, i);
	else
		error += parse_color_values(&data->mapinfo.c, str, i);
	if (error != 0)
	{
		while (line)
		{
			free(line);
			line = get_next_line(fd);
		}
		if (error == 1)
			ft_error("Wrong color format!\n", data);
		else if (error == 2)
			ft_error("Wrong color ranges!\n", data);
	}
}

int	check_input(char *str, t_data *data, t_mapchecker *elements, int fd)
{
	int	i;

	i = 0;
	if (valid_key(str) == 1)
		return (1);
	while (str[i] == 32)
		i++;
	while (str[i])
	{
		if (!ft_strncmp(str + i, "F ", 2) || !ft_strncmp(str + i, "C ", 2))
		{
			parse_color(str + i, data, str, fd);
			update_mapchecker(str + i, elements);
		}
		if (!ft_strncmp(str + i, "NO ", 3) || !ft_strncmp(str + i, "SO ", 3)
			|| !ft_strncmp(str + i, "WE ", 3) || !ft_strncmp(str + i, "EA ", 3))
		{
			parse_path(str + i, data);
			update_mapchecker(str + i, elements);
		}
		i++;
	}
	return (0);
}
