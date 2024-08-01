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

	red = ft_atoi(str + i);
	while (str[i] != 44)
		i++;
	green = ft_atoi(str + ++i);
	while (str[i] != 44)
		i++;
	blue = ft_atoi(str + ++i);
	while (ft_isdigit(str[i]))
		i++;
	if (color_range(red, blue, green) == 0)
		return (2);
	*X = (red << 16) | (green << 8) | blue;
	return (0);
}

void	parse_color(char *str, t_data *data, char *line, int fd)
{
	int		i;
	int		error;
	char	**color;
	int		count;

	count = 0;
	error = 0;
	i = 2;
	while (str[i] == 32)
		i++;
	color = ft_split(str + i, ',');
	while (color[count] != NULL)
		count++;
	printf("Value of color[2] == %s\n", color[count]);
	error = free_color_array(color, count);
	if (count != 3 || color[count - 1] == NULL)
		free_line(line, fd, data, 3); //wrong amount of RGB
	if (error != 0)
		free_line(line, fd, data, error); //no digits
	if (str[0] == 'F')
		error = parse_color_values(&data->mapinfo.f, str, i); //out of scope
	else
		error = parse_color_values(&data->mapinfo.c, str, i); //out of scope
	if (error != 0)
		free_line(line, fd, data, error);
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
