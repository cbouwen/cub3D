/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:25:48 by mlegendr          #+#    #+#             */
/*   Updated: 2024/07/22 19:52:25 by mlegendr         ###   ########.fr       */
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
}

void	free_all(t_data *data)
{
	ft_free_array(data->mapinfo.map, data->mapinfo.rows);
	destroy_textures(data);
	free(data->mapinfo.no);
	free(data->mapinfo.so);
	free(data->mapinfo.we);
	free(data->mapinfo.ea);
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

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	write(2, "Error\n", 6);
	exit(1);
}
