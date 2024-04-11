/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:45:32 by cbouwen           #+#    #+#             */
/*   Updated: 2024/04/11 16:58:22 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	correct_color_parse(char *str, char c)
{
	int	i;
	int	commas;
	int	digits;
	char	str2;

	str2 = ft_strdup_no_space(str);
	digits = 0;
	commas = 0;
	i = 1;
	while (str2[i])
	{
		while (ft_isdigit(str2[i]))
			i++;
		digits++;
		while (str[i] == 44)
			commas++;
		i++;
	}
	free(str2);
	if (digits == 3 && commas == 2 && c == 'F')
		return (1);
	if (digits == 3 && commas == 2 && c == 'C')
		return (2);
	return (0);
}


int	correct_path(char *str, char *path, t_mapchecker *elements)
{
	int i;

	i = 0;


}

void	find_duplicate(int a, t_mapchecker *elements)
{
	if (a == 1 && elements->F == true)
		elements->duplicate = true;
	if (a == 2 && elements->C == true)
		elements->duplicate = true;
	if (a == 3 && elements->NO == true)
		elements->duplicate = true;
	if (a == 4 && elements->SO == true)
		elements->duplicate = true;
	if (a == 5 && elements->WE == true)
		elements->duplicate = true;
	if (a == 6 && elements->EA == true)
		elements->duplicate = true;
}

void	set_element_boolean(int a, t_mapchecker *elements)
{
	if (a == 0)
		return ();
	find_duplicate(a, elements);
	if (a == 1)
		elements->F = true;
	if (a == 2)
		elements->C = true;
	if (a == 3)
		elements->NO = true;
	if (a == 4)
		elements->SO= true;
	if (a == 5)
		elements->WE = true;
	if (a == 6)
		elements->EA = true;
}
