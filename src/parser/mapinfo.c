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

void	parse_color_values(int *X, char *str, int i, t_data *data)
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
	if (!(ft_isdigit(str[i + 1])))
		ft_error("Wrong color format!\n", data);
	blue = ft_atoi(str + ++i);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\n')
		ft_error("Wrong color format!\n", data);
	if (color_range(red, blue, green) == 0)
	{
		free(str);
		ft_error("Wrong color ranges\n", data); //make new free function for colours
	}
	*X = (red << 16) | (green << 8) | blue;
}

void	parse_color(char *str, t_data *data)
{
	int	i;

	i = 2;
	while (str[i] == 32)
		i++;
	if (str[0] == 'F')
		parse_color_values(&data->mapinfo.f, str, i, data);
	else
		parse_color_values(&data->mapinfo.c, str, i, data);
}

int	check_input(char *str, t_data *data, t_mapchecker *elements)
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
			parse_color(str + i, data);
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
