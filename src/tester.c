/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:39:36 by cbouwen           #+#    #+#             */
/*   Updated: 2024/04/22 14:48:06 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	tester(t_mapinfo mapinfo)
{
	printf("Path to NO is: %s\n", mapinfo.NO);
	printf("Path to SO is: %s\n", mapinfo.SO);
	printf("Path to WE is: %s\n", mapinfo.WE);
	printf("Path to EA is: %s\n", mapinfo.EA);
	printf("Color for the floor is: %i, %i, %i\n", mapinfo.F.red,
			mapinfo.F.green, mapinfo.F.blue);
	printf("Color for the ceiling is: %i, %i, %i\n", mapinfo.C.red,
			mapinfo.C.green, mapinfo.C.blue);
}
