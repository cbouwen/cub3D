/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:49:22 by cbouwen           #+#    #+#             */
/*   Updated: 2024/05/08 17:52:43 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef struct s_color
{
    int     red;
    int     green;
    int     blue;
}           t_color;

typedef struct s_mapinfo
{
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
    t_color f;
    t_color c;
    int     rows;
    int     colomns;
}           t_mapinfo;

typedef struct s_map
{
    int     x;  
    int     y;  
    char    c;  
}           t_map;

typedef struct s_mapchecker
{
    bool    no; 
    bool    so; 
    bool    we; 
    bool    ea; 
    bool    f;  
    bool    c;  
    bool    duplicate;
    bool    all_eles;
}           t_mapchecker;

//mlx struct for image
typedef struct  s_data
{
    void    *img;
    char    *addr;
    int bits_per_pixel;
    int endian;
    int line_length;
}           t_data;

//mlx struct for window initialization
typedef struct  s_mlx_data
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
}           t_mlx_data;

typedef struct	s_coordinates
{
	double	x;
	double	y;
}				t_coordinates;

typedef struct	s_player
{
	t_coordinates	position;
	t_coordinates	direction;
	t_coordinates	plane;
}			t_player;

typedef struct	s_raycaster
{
	double	camera_x;
	//double	camera_y;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;



}				t_raycaster;

#endif
