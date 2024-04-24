/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:42:50 by cbouwen           #+#    #+#             */
/*   Updated: 2024/04/24 16:27:08 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/Getnextline/getnextline.h"
# include "../lib/Libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../mlx_linux/mlx.h"

#define HEIGHT 1080
#define WIDTH 1980

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
}			t_color;

typedef struct s_mapinfo
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_color	f;
	t_color	c;
	int		rows;
	int		colomns;
}			t_mapinfo;

typedef struct s_map
{
	int		x;
	int		y;
	char	c;
}			t_map;

typedef struct s_mapchecker
{
	bool	no;
	bool	so;
	bool	we;
	bool	ea;
	bool	f;
	bool	c;
	bool	duplicate;
	bool	all_eles;
}			t_mapchecker;

//mlx struct for image
typedef struct	s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	endian;
	int	line_length;
}			t_data;

//mlx struct for window initialization
typedef struct	s_mlx_data
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
}			t_mlx_data;

//utils
int			map_name(char *str);
void		ft_free(void *ptr);
int			check_for_map(char *str);
int			ft_error(char *str);
void		ft_free_array(t_map **map, int count);

//parser
int			parse_cub(char *argv, t_mapinfo *mapinfo, t_map ***map);
void		init_map_checker(t_mapchecker *elements);
void		update_mapchecker(char *str, t_mapchecker *elements);
void		check_input(char *str, t_mapinfo *mapinfo, t_mapchecker *elements);
t_map		**parse_map(int fd, t_mapinfo mapinfo, t_map ***map);
int			valid_map(t_map **map, t_mapinfo mapinfo);

//mlx_ft's
void	init_window(t_mlx_data *win_data);
int		close_window(t_mlx_data *win_data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);//we need this?

//executing part
void	execute_map(t_map ***map, t_mapinfo mapinfo);


//tester ft's
void		tester(t_mapinfo mapinfo);
void		test_map(t_map **map, t_mapinfo mapinfo);

#endif
