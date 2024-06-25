/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:49:22 by cbouwen           #+#    #+#             */
/*   Updated: 2024/06/21 12:48:25 by cbouwen          ###   ########.fr       */
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
typedef struct _s_mapinfo
{
    char			*no;
    char			*so;
    char			*we;
    char			*ea;
    int	f; //unsigned long
    int	c;
    int				rows;
    int				colomns;
}					_t_mapinfo;

//struct to parse the map[][]
typedef struct _s_map
{
    int     x;  
    int     y;  
    char    c;  
}           _t_map;

//struct to check if map is valid
typedef struct _s_mapchecker
{
    bool    no; 
    bool    so; 
    bool    we; 
    bool    ea; 
    bool    f;  
    bool    c;  
    bool    duplicate;
    bool    all_eles;
}           _t_mapchecker;

//mlx struct for image

//Combine this with t_mlx_data?

typedef struct  _s_data
{
    void    *img;
    //char    *addr;
    void    *addr;
    int bits_per_pixel;
    int endian;
    int line_length;
}           _t_data;

//mlx struct for window initialization

//Seems to be the main mlx struct
typedef struct  s_mlx_data
{
    void    *mlx;
    void    *mlx_win;
    _t_data  img;
}           t_mlx_data;

//simple x,y struct

//Seems to be a helper struct for s_player
typedef struct	_s_coordinates
{
	double	x;
	double	y;
}				_t_coordinates;

//struct to store all relevant player data for raycasting. Position vector, direction vector, camera plane vector

//important struct for player data
typedef struct	_s_player
{
	_t_coordinates	position;
	_t_coordinates	direction;
	_t_coordinates	plane;
}			_t_player;

//struct to store all raycasting calculations

//contains all the big data for the raycaster
typedef struct	_s_raycaster
{
	double	camera_x; //what percentile of the screen are we on?
	double	raydirx; //using camera_x, where on the screen is the ray casting to?
	double	raydiry;
	double	sidedistx; //distance from player position to first x side encountered
	double	sidedisty;
	double	deltadistx; //distance the ray has to travel to go from one x-side of a tile to the other x-side of the tile.
	double	deltadisty;
	int		stepx; //what direction are we moving in? Left or right (for y values: up or down)? Expressed in positive or neg 1
	int		stepy;
	int		mapx; //what tile is the player position in? !!different than player position. player position is position in tile. mapx is tile in map
	int		mapy;
	int		side; //what side of the wall is hit? need this to know what texture to print
	double	perpwalldist; //extra thing to avoid fisheye effect. With this we cast rays from a camera plane, ie a line instead of one point (the player position)
	int		lineheight; //calculation of the size of the line to cast by using the length of the ray
	int		drawstart;//calculate lowest and highest pixel
	int		drawend;
	int		x; //added this to use the draw ft
	// double time && double oldTime? ==> Do we want to implement FPS? I fucking think not
}				_t_raycaster;

//Combine this data in a massive struct, which can be far too difficult to use, let alone init to default
//Add all the tiny structs to the t_mlx_data struct as a reference, keeps all the struct seperate but allow them to be used everywhere else without passing more than one parameter

//Additionally, we should add a seperate variable in one of the map structs to store the actual map,
//I don't want to have to pass variables with more than 1 pointer. Passing 3 pointers is not very efficient
#endif
