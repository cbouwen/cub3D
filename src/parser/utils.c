/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:15:02 by cbouwen           #+#    #+#             */
/*   Updated: 2024/04/11 16:21:16 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int  counter(const char *s) 
{
    int i;
	int	j;

    i = 0;
	j = 0;
    while (s[i])
	{	
		if (s[i] == 32 || s[i] == '\n')
			j++;
        i++;
		if (ft_isdigit(s[i]))
			break;
	}
    return (i - j);
}

char    *ft_strdup_no_space(const char *s) 
{
    char    *t; 
    int     len;
    int     i;  

    i = 0;
    len = counter(s);
    t = malloc(sizeof(char) * (len + 1));
    if (!t)
        return (NULL);
    while (s[i])
    {   
		if (s[i] == 32 || s[i] == '\n')
		{
			i++;
			continue;
		}
        t[i] = s[i];
        i++;
		if (ft_isdigit(s[i]))
			break;
    }   
    t[i] = '\0';
    return (t);
}
