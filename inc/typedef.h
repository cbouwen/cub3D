
#ifndef TYPEDEF_H
# define TYPEDEF_H

# include "cub3d.h"

#define WIDTH 1920

//struct to check if map is valid
typedef struct	s_mapchecker
{
	bool	no; 
	bool	so; 
	bool	we; 
	bool	ea; 
	bool	f;  
	bool	c;  
	bool	duplicate;
	bool	all_eles;
}				t_mapchecker;

//struct to parse the map[][]
typedef struct	s_map
{
	int		x;
	int		y;
	char	c;
}				t_map;

//struct to store path names and general map info
typedef struct	s_mapinfo
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f; //unsigned long
	int		c;
	int		rows;
	int		columns;
	t_map	**map;
}				t_mapinfo;

//simple x,y struct
typedef struct	s_coordinates
{
	double	x;
	double	y;
}				t_coordinates;

//important struct for player data
typedef struct	s_player
{
	t_coordinates	position;
	t_coordinates	direction;
	t_coordinates	plane;
}				t_player;

//struct to store all raycasting calculations
typedef struct	s_raycaster
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
}				t_raycaster;

//struct to store texture data
typedef struct s_text_mlx
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_text_mlx;


//mlx struct for image & window initialization
typedef struct	s_data
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			endian;
	int			line_length;
	t_player	player;
	t_raycaster	rc[WIDTH];
	t_mapinfo	mapinfo;
	t_text_mlx	text[5];
}				t_data;

#endif
