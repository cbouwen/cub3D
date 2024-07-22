/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:58:34 by cbouwen           #+#    #+#             */
/*   Updated: 2024/07/22 15:59:39 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	parse_texture(t_data *data)
{
	parse_texture_helper(data, NORTH, data->mapinfo.no);
	parse_texture_helper(data, EAST, data->mapinfo.ea);
	parse_texture_helper(data, SOUTH, data->mapinfo.so);
	parse_texture_helper(data, WEST, data->mapinfo.we);
}

void	parse_texture_helper(t_data *data, int dir, char *path)
{
	int	*temp;
	int	x;
	int	y;

	data->text[dir].img = mlx_xpm_file_to_image(data->mlx, path, &data->text[dir].width, &data->text[dir].height);
	if (!data->text[dir].img)
		ft_error("Error\nTexture not found");
	if (data->text[dir].width != 128 || data->text[dir].height != 128) //nog aanpassen naar de juiste check (check tegen elkaar niet gewoon de size) || also voeg define toe aan header voor de grootte
		ft_error("Error\nTexture size not 64x64");
	temp = (int *)(mlx_get_data_addr(data->text[dir].img, &data->text[dir].bits_per_pixel, &data->text[dir].line_length, &data->text[dir].endian));
	if (!temp)
		ft_error("Error\nTexture not found");
	data->text[dir].addr = (int *)ft_calloc(data->text[dir].width * data->text[dir].height, sizeof(int));
	if (!data->text[dir].addr)
		ft_error("Error\nCalloc failed");
	y = -1;
	while (++y < data->text[dir].height)
	{
		x = -1;
		while (++x < data->text[dir].width)
			data->text[dir].addr[y * data->text[dir].width + x] = temp[y * (data->text[dir].line_length / 4) + x];
	}
}
