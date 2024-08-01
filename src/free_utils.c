/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:25:48 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/01 16:41:20 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_cond(t_data *data)
{
	if (data->mapinfo.no)
		free(data->mapinfo.no);
	if (data->mapinfo.so)
		free(data->mapinfo.so);
	if (data->mapinfo.we)
		free(data->mapinfo.we);
	if (data->mapinfo.ea)
		free(data->mapinfo.ea);
	if (data->mapinfo.map)
		ft_free_array(data->mapinfo.map, data->mapinfo.rows);
	destroy_textures(data);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
}

void	free_line(char *line, int fd, t_data *data, int error)
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
	else if (error == 3)
		ft_error("Wrong amount of color arguments\n", data);
}

void	destroy_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->text[i].img)
			mlx_destroy_image(data->mlx, data->text[i].img);
		if (data->text[i].addr)
			free(data->text[i].addr);
		i++;
	}
}

void	ft_free_array(t_map **map, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		free(map[i]);
	free(map);
}

void	free_color_array(char **color, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		free(color[i]);
	free(color);
}
