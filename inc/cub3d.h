/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:42:50 by cbouwen           #+#    #+#             */
/*   Updated: 2024/04/22 15:39:57 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../lib/Libft/libft.h"
#include "../lib/Getnextline/getnextline.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct	s_color
{
	int	red;
	int	green;
	int	blue;
}				t_color;

typedef struct	s_mapinfo
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	t_color	F;
	t_color	C;
}				t_mapinfo;

typedef struct s_mapchecker
{
	bool	NO;
	bool	SO;
	bool	WE;
	bool	EA;
	bool	F;
	bool	C;
	bool	duplicate;
	bool	all_eles;
}			t_mapchecker;

int     map_name(char *str);
void	ft_free(void *ptr);
int		ft_error(char *str);
int		parse_cub(char *argv, t_mapinfo *mapinfo);
void	init_map_checker(t_mapchecker *elements);
void	update_mapchecker(char *str, t_mapchecker *elements);

//tester ft's
void	tester(t_mapinfo mapinfo);

# endif
