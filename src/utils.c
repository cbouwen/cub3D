/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:15:54 by cbouwen           #+#    #+#             */
/*   Updated: 2024/04/11 13:52:34 by cbouwen          ###   ########.fr       */
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

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_error(char *str)
{
	printf("%s\n", str);
	exit(1);
}
