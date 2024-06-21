/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:42:49 by cbouwen           #+#    #+#             */
/*   Updated: 2024/06/21 12:57:24 by cbouwen          ###   ########.fr       */
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
		mapinfo->no = ft_strndup(str + 3, i);
	else if (str[0] == 'S')
		mapinfo->so = ft_strndup(str + 3, i);
	else if (str[0] == 'W')
		mapinfo->we = ft_strndup(str + 3, i);
	else if (str[0] == 'E')
		mapinfo->ea = ft_strndup(str + 3, i);
}

void	parse_color_values(int *X, char *str, int i)
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
	*X = (red << 16) | (green << 8) | blue;
}

void	parse_color(char *str, t_mapinfo *mapinfo)
{
	int	i;

	i = 2;
	while (str[i] == 32)
		i++;
	if (str[0] == 'F')
		parse_color_values(&mapinfo->f, str, i);
	else
		parse_color_values(&mapinfo->c, str, i);
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
