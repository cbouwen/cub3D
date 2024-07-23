/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:58:34 by cbouwen           #+#    #+#             */
/*   Updated: 2024/07/23 16:24:31 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static	void	parse_texture_helper(t_data *data, int dir, char *path)
{
	int	*temp;
	int	x;
	int	y;

	check_texture_file(path, data);
	create_image(data, dir, path);
	temp = get_data_addr(data, dir);
	check_texture_size(data, dir);
	data->text[dir].addr = (int *)ft_calloc(data->text[dir].width
			* data->text[dir].height, sizeof(int));
	if (!data->text[dir].addr)
		ft_error("Error\nCalloc failed\n", data);
	y = -1;
	while (++y < data->text[dir].height)
	{
		x = -1;
		while (++x < data->text[dir].width)
			data->text[dir].addr[y * data->text[dir].width + x] = temp[y
				* (data->text[dir].line_length / 4) + x];
	}
}

void	parse_texture(t_data *data)
{
	parse_texture_helper(data, NORTH, data->mapinfo.no);
	parse_texture_helper(data, EAST, data->mapinfo.ea);
	parse_texture_helper(data, SOUTH, data->mapinfo.so);
	parse_texture_helper(data, WEST, data->mapinfo.we);
}
