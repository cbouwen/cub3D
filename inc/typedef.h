/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:18:28 by cbouwen           #+#    #+#             */
/*   Updated: 2024/07/22 17:19:25 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

# include "cub3d.h"

# define WIDTH 1920

//enum for direction
typedef enum e_direction
{
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3,
}					t_direction;

//struct to check if map is valid
typedef struct s_mapchecker
{
	bool			no;
	bool			so;
	bool			we;
	bool			ea;
	bool			f;
	bool			c;
	bool			duplicate;
	bool			all_eles;
}					t_mapchecker;

//struct to parse the map[][]
typedef struct s_map
{
	int				x;
	int				y;
	char			c;
}					t_map;

//struct to store path names and general map info
typedef struct s_mapinfo
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	int		c;
	int		rows;
	int		columns;
	t_map	**map;
}					t_mapinfo;

//simple x,y struct
typedef struct s_coordinates
{
	double			x;
	double			y;
}					t_coordinates;

//important struct for player data
typedef struct s_player
{
	t_coordinates	position;
	t_coordinates	direction;
	t_coordinates	plane;
}					t_player;

//struct to store all raycasting calculations
typedef struct s_raycaster
{
	double			camera_x;
	double			raydirx;
	double			raydiry;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	int				stepx;
	int				stepy;
	int				mapx;
	int				mapy;
	int				side;
	double			perpwalldist;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				x;
}					t_raycaster;

//struct to store texture data
typedef struct s_text_mlx
{
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_text_mlx;

//mlx struct for image & window initialization
typedef struct s_data
{
	void			*mlx;
	void			*mlx_win;
	void			*img;
	void			*addr;
	int				bits_per_pixel;
	int				endian;
	int				line_length;
	double			pos;
	int				rc_x;
	t_player		player;
	t_raycaster		rc[WIDTH];
	t_mapinfo		mapinfo;
	t_text_mlx		text[4];
}					t_data;

#endif
