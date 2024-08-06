/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:41:59 by cbouwen           #+#    #+#             */
/*   Updated: 2024/08/06 16:09:49 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_error("Wrong number of arguments. Try again!\n", NULL);
	else if (!(map_name(argv[1])))
		ft_error("Map doesn't end with .cub\n", NULL);
	else
	{
		init_data_default(&data);
		parse_cub(argv[1], &data);
		execute_map(&data);
		free_cond(&data);
	}
	return (0);
}
