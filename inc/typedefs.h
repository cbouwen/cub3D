/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:49:22 by cbouwen           #+#    #+#             */
/*   Updated: 2024/06/17 15:00:13 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

//struct for RGB
typedef struct s_color
{
    int     red;
    int     green;
    int     blue;
}           t_color;

//struct to store path names and general map info
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

//struct to parse the map[][]
typedef struct s_map
{
    int     x;  
    int     y;  
    char    c;  
}           t_map;

//struct to check if map is valid
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

//simple x,y struct
typedef struct	s_coordinates
{
	double	x;
	double	y;
}				t_coordinates;

//struct to store all relevant player data for raycasting. Position vector, direction vector, camera plane vector
typedef struct	s_player
{
	t_coordinates	position;
	t_coordinates	direction;
	t_coordinates	plane;
}			t_player;

//struct to store all raycasting calculations
typedef struct	s_raycaster
{
	double	camera_x; //what percentile of the screen are we on?
	double	raydirx; //where on the screen is the ray casting to?
	double	raydiry;
	double	sidedistx; //distance from player position to first x side encountered
	double	sidedisty;
	double	deltadistx; //distance the ray has to travel to go from one x-side of a tile to the other x-side of the tile.
	double	deltadisty;
	int		stepx; //what direction are we moving in? Left right up down? Expressed in positive or neg 1
	int		stepy;
	int		mapx; //what tile is the player position in?
	int		mapy;
	//double	PerpWallDist;
	// double time && double oldTime?
}				t_raycaster;

#endif
