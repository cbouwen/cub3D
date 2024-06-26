/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:30:01 by cbouwen           #+#    #+#             */
/*   Updated: 2024/04/23 16:33:06 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_for_map(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == 32 || str[i] == '\t'))
		i++;
	if (str[i] == '1' || str[i] == '0')
		return (1);
	return (0);
}

void	check_all_elements(new_t_mapchecker *elements)
{
	if (elements->no == true && elements->so == true && elements->we == true
		&& elements->ea == true && elements->c == true && elements->f == true)
		elements->all_eles = true;
}

void	check_duplicates(char *str, new_t_mapchecker *elements)
{
	if (str[0] == 'N' && elements->no == true)
		elements->duplicate = true;
	else if (str[0] == 'S' && elements->so == true)
		elements->duplicate = true;
	else if (str[0] == 'W' && elements->we == true)
		elements->duplicate = true;
	else if (str[0] == 'E' && elements->ea == true)
		elements->duplicate = true;
	else if (str[0] == 'C' && elements->c == true)
		elements->duplicate = true;
	else if (str[0] == 'F' && elements->f == true)
		elements->duplicate = true;
}

void	update_mapchecker(char *str, new_t_mapchecker *elements)
{
	check_duplicates(str, elements);
	if (str[0] == 'N')
		elements->no = true;
	else if (str[0] == 'S')
		elements->so = true;
	else if (str[0] == 'W')
		elements->we = true;
	else if (str[0] == 'E')
		elements->ea = true;
	else if (str[0] == 'C')
		elements->c = true;
	else if (str[0] == 'F')
		elements->f = true;
	check_all_elements(elements);
}

void	init_map_checker(new_t_mapchecker *elements)
{
	elements->no = false;
	elements->so = false;
	elements->we = false;
	elements->ea = false;
	elements->f = false;
	elements->c = false;
	elements->duplicate = false;
	elements->all_eles = false;
}
