/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:15:54 by cbouwen           #+#    #+#             */
/*   Updated: 2024/07/22 19:49:10 by mlegendr         ###   ########.fr       */
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

/*
	Hier hebben we nog een paar errors.
	Afhankelijk van waar we een error tegenkomen, zijn er nog steeds leaks.

	Als we de error tegenkomen als de MLX al bestaat, dan leakt de mlx.
	Redelijk simpel op te lossen door een aparte free functie te maken voor errors.

	Als we de error tegenkomen als de MLX nog niet bestaat, dan leaken er andere dingen.
	De meest voorkomende leak zit in parse_path in mapinfo.c.
	Als we een error tegenkomen in parse_path, dan leakt de ft_strndup.
	Ik weet niet al te goed hoe ik dit moet oplossen tbh.

	Andere leaks zal ik pas echt zien zitten als de bovenstaande leaks zijn opgelost.
	
	De flags voor valgrind zijn (dan kunt gij ook alle leaks zien):
	--leak-check=full --show-leak-kinds=all --track-origins=yes
*/
int	ft_error(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	(void)data;
	/*if (data)
		free_cond(data);*/
	exit(1);
}
