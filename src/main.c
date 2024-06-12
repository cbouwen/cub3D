	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:41:59 by cbouwen           #+#    #+#             */
/*   Updated: 2024/06/12 18:00:01 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_mlx;

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 600, 600, "cub3d");
	mlx->img = mlx_new_image(mlx->mlx, 600, 6000);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_len, &mlx->endian);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	t_mlx *mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (-1);
	init_mlx(mlx);
	mlx_loop(mlx->mlx);	

	/*t_mapinfo		mapinfo;
	t_map			**map;

	//	int		fd;
	if (argc != 2)
		ft_error("Wrong number of arguments. Try again!");
	else if (!(map_name(argv[1])))
		ft_error("Hmmmm. Map should end with .cub. Can you make sure of that please?");
	else
	{
		mapinfo.rows = 0;
		mapinfo.colomns = 0;
		parse_cub(argv[1], &mapinfo, &map);//error exit check?
		execute_map(&map, mapinfo);
	}
	//	if (!(valid_map(fd, &map)))
	//		ft_error("Invalid map. Try again!");
	//run_cub3d(map);
	//	close(fd);
	*/
}
