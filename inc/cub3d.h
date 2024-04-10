/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:42:50 by cbouwen           #+#    #+#             */
/*   Updated: 2024/04/10 16:55:02 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../lib/Libft/libft.h"
#include "../lib/Getnextline/getnextline.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_mapinfo
{
	int	rows;
}				t_mapinfo;

void	ft_free(void *ptr);
int		ft_error(char *str);
int		valid_map(int fd, char ***map);

# endif
