/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:41:59 by cbouwen           #+#    #+#             */
/*   Updated: 2024/07/22 19:45:13 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	_main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_error("Wrong number of arguments. Try again!\n", &data);
	else if (!(map_name(argv[1])))
		ft_error("Map doesn't end with .cub\n", &data);
	else
	{
		init_data_default(&data);
		parse_cub(argv[1], &data);
		execute_map(&data);
		//free_all(&data);
		free_cond(&data);
	}
	return (0);
}

typedef struct s_test
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*addr;
}				t_test;

static void default_init(t_test *test)
{
	test->mlx = NULL;
	test->mlx_win = NULL;
	test->img = NULL;
	test->addr = NULL;
}

static void print_test(t_test *test)
{
	if (test->mlx != NULL)
		printf("mlx is not NULL\n");
	else
		printf("mlx is NULL\n");
	if (test->mlx_win != NULL)
		printf("mlx_win is not NULL\n");
	else
		printf("mlx_win is NULL\n");
	if (test->img != NULL)
		printf("img is not NULL\n");
	else
		printf("img is NULL\n");
	if (test->addr != NULL)
		printf("addr is not NULL\n");
	else
		printf("addr is NULL\n");
}

int main(void)
{
	t_test test;

	default_init(&test);

	print_test(&test);
	printf("\n");

	//change is detected, test_mlx is no longer NULL
	test.mlx = mlx_init();
	print_test(&test);
	printf("\n");

	//change is detected, test_mlx_win is no longer NULL
	test.mlx_win = mlx_new_window(test.mlx, 1920, 1080, "Hello world!");
	print_test(&test);
	printf("\n");

	test.img = mlx_new_image(test.mlx, 1920, 1080);
	print_test(&test);
	printf("\n");


	mlx_loop(test.mlx);

	//this combination is needed to free the mlx pointer.
	//if you only free mlx, it will still leak
	//order of operations is also important
	//if you destroy the display first, or free mlx first, it will crash
	mlx_loop_end(test.mlx);
	mlx_destroy_window(test.mlx, test.mlx_win);
	mlx_destroy_image(test.mlx, test.img);

	mlx_destroy_display(test.mlx);
	free(test.mlx);

	return (0);
}