/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:15:54 by cbouwen           #+#    #+#             */
/*   Updated: 2024/07/23 10:49:20 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	map_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i = i - 4;
	if (!(ft_strcmp(str + i, ".cub")))
		return (1);
	return (0);
}

int	ft_error(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	if (data)
		free_cond(data);
	exit(1);
}
