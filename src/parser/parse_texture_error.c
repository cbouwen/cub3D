/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 02:04:41 by mlegendr          #+#    #+#             */
/*   Updated: 2024/07/23 02:04:41 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void check_texture_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nTexture file not found.\n", NULL);
	close(fd);
}

void create_image(t_data *data, int dir, char *path)
{
	data->text[dir].img = mlx_xpm_file_to_image(data->mlx, path,
			&data->text[dir].width, &data->text[dir].height);
	if (!data->text[dir].img)
		ft_error("Error\nProblem with getting image for texture.\n", data);
}

int *get_data_addr(t_data *data, int dir)
{
	int	*temp;

	temp = (int *)mlx_get_data_addr(data->text[dir].img,
			&data->text[dir].bits_per_pixel, &data->text[dir].line_length,
			&data->text[dir].endian);
	if (!data->text[dir].addr)
		ft_error("Error\nProblem with getting data_addr for texture.\n", data);
	return (temp);
}

void check_texture_size(t_data *data, int dir)
{
	if (data->text[dir].width != TEX_SIZE || data->text[dir].height != TEX_SIZE)
		ft_error("Error\nTexture size is not equal to TEX_SIZE.\n", data);
}