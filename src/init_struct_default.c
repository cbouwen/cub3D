/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_default.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:55:56 by cbouwen           #+#    #+#             */
/*   Updated: 2024/07/22 17:02:32 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_data_default(t_data *data)
{
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->endian = 0;
	data->line_length = 0;
	data->pos = 0.0;
	data->rc_x = 0;
	init_player_default(&data->player);
	init_rc_default(data->rc);
	init_mapinfo_default(&data->mapinfo);
	init_text_mlx_default(data->text);
}

void	init_player_default(t_player *player)
{
	player->position.x = 0;
	player->position.y = 0;
	player->direction.x = 0;
	player->direction.y = 0;
	player->plane.x = 0;
	player->plane.y = 0;
}

void	init_rc_default(t_raycaster *rc)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		rc[i].camera_x = 0.0;
		rc[i].raydirx = 0.0;
		rc[i].raydiry = 0.0;
		rc[i].sidedistx = 0.0;
		rc[i].sidedisty = 0.0;
		rc[i].deltadistx = 0.0;
		rc[i].deltadisty = 0.0;
		rc[i].stepx = 0;
		rc[i].stepy = 0;
		rc[i].mapx = 0;
		rc[i].mapy = 0;
		rc[i].side = 0;
		rc[i].perpwalldist = 0.0;
		rc[i].lineheight = 0;
		rc[i].drawstart = 0;
		rc[i].drawend = 0;
		rc[i].x = 0;
		i++;
	}
}

void	init_mapinfo_default(t_mapinfo *mapinfo)
{
	mapinfo->no = NULL;
	mapinfo->so = NULL;
	mapinfo->we = NULL;
	mapinfo->ea = NULL;
	mapinfo->f = 0;
	mapinfo->c = 0;
	mapinfo->rows = 0;
	mapinfo->columns = 0;
	mapinfo->map = NULL;
}

void	init_text_mlx_default(t_text_mlx *text)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		text[i].img = NULL;
		text[i].addr = NULL;
		text[i].bits_per_pixel = 0;
		text[i].line_length = 0;
		text[i].endian = 0;
		text[i].width = 0;
		text[i].height = 0;
		i++;
	}
}
