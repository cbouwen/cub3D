/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:30:01 by cbouwen           #+#    #+#             */
/*   Updated: 2024/04/22 15:37:01 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void    check_duplicates(char *str, t_mapchecker *elements)
{
    if (str[0] == 'N' && elements->NO == true)
        elements->duplicate = true;
    else if (str[0] == 'S'&& elements->SO == true)
        elements->duplicate = true;
    else if (str[0] == 'W' && elements->WE == true)
        elements->duplicate = true;
    else if (str[0] == 'E' && elements->EA == true)
        elements->duplicate = true;
    else if (str[0] == 'C' && elements->C == true)
        elements->duplicate = true;
    else if (str[0] == 'F' && elements->F == true)
        elements->duplicate = true;
}

void    update_mapchecker(char *str, t_mapchecker *elements)
{
    check_duplicates(str, elements);
    if (str[0] == 'N')
        elements->NO = true;
    else if (str[0] == 'S')
        elements->SO = true;
    else if (str[0] == 'W')
        elements->WE = true;
    else if (str[0] == 'E')
        elements->EA = true;
    else if (str[0] == 'C')
        elements->C = true;
    else if (str[0] == 'F')
        elements->F = true;
}

void    init_map_checker(t_mapchecker *elements)  //utils?
{
    elements->NO = false;
    elements->SO = false;
    elements->WE = false;
    elements->EA = false;
    elements->F = false;
    elements->C = false;
    elements->duplicate = false;
    elements->all_eles = false;
}
