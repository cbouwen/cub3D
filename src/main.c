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

static void default(t_test *test)
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

	default(&test);

	print_test(&test);

	test.mlx = mlx_init();

	print_test(&test);

	return (0);
}