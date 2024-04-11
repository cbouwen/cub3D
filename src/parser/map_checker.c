/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:24:28 by cbouwen           #+#    #+#             */
/*   Updated: 2024/04/11 16:52:11 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	all_elements_found(t_mapchecker *elements)
{
	elements->all_eles = true;
	if (elements->NO = false)
		elements->all_eles = false;
	if (elements->SO = false)
		elements->all_eles = false;
	if (elements->WE = false)
		elements->all_eles = false;
	if (elements->EA = false)
		elements->all_eles = false;
	if (elements->F = false)
		elements->all_eles = false;
	if (elements->C = false)
		elements->all_eles = false;
	if (elements->duplicate = true)
		elements->all_eles = false;
}

void	look_for_elements(char *str, t_mapchecker *elements) //what if element has different name? If there is something different than NO and C like R?
{
	int	i;
	int	a;

	i = 0;
	while (str[i])
	{
		a = 0;
		if (str[i] == 'F' || str[i] == 'C')
			a = correct_color_parse(str + i, str[i]); //maybe add address to i? Or maybe rewrite this whole clusterfuck
		if (ft_strncmp(str + i, "NO", 2)) 
			a = correct_path(str + i, "NO", 3); //write as well.
		if (ft_strncmp(str + i, "SO", 2)) 
			a = correct_path(str + i, "SO", 4);
		if (ft_strncmp(str + i, "WE", 2)) 
			a = correct_path(str + i, "WE", 5);
		if (ft_strncmp(str + i, "EA", 2)) 
			a = correct_path(str + i, "EA", 6);
		i++;
		set_element_boolean(a, elements); //a will tell us what flag will be set to true. in here we can check if it's duplicate or not.
	}	
	all_elements_found(elements);
}

void	init_map_checker(t_mapchecker elements)  //utils?
{
	elements.NO = false;
	elements.SO = false;
	elements.WE = false;
	elements.EA = false;
	elements.F = false;
	elements.C = false;
	elements.duplicate = false;
	elements.all_eles = false;
}

int	parse_map_info(int fd) //char ***mapinfo)
{
	char	*line;
	char	*str;
	t_mapchecker	elements;

	str = malloc(sizeof(char));
	if (!str)
		ft_error("Malloc failure? Wtf");
	str[0] = '\0';
	line = get_next_line(fd);
	init_map_checker(&elements);
	while (line)
	{
		str = ft_strjoin(str, line);
		free(line);
		line = get_next_line(fd);
	}
	look_for_elements(str, &elements);
	free(str);
	if (elements.all_eles == true)
		return (1);
	return (0);
}


int	parse_cub(char *argv, char ***mapinfo)
{
	int	fd;

	if (!(fd = open(argv, O_RDONLY)))
		ft_error ("Error opening map.. Weird. Try again!");
	if (!(parse_map_info(fd, mapinfo)))//Step 1
	{
		close(fd);
		ft_error("Incorrect elements. Try again!");
	}
	parse_map(fd, map); //map?    Let's start with check here to determine if the map is really the last element
	close(fd);


}
