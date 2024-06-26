/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:15:54 by cbouwen           #+#    #+#             */
/*   Updated: 2024/04/23 16:23:03 by cbouwen          ###   ########.fr       */
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

int	ft_error(char *str)	//this should call on a couple of frees or remove the exit. either way this will have to receive more arguments
{
	int i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	exit(1);
}
