#include "../../inc/cub3d.h"

int	color_range(int	x)
{
	if (x < 0)
		return (0);
	if (x > 16777215)
		return (0);
	return (1);
}

void	map_errors(t_mapchecker *elements, new_t_data *data)
{
	if (elements->all_eles == false)
		ft_error("Not all elements are defined before map initialization.\n");
	if (elements->duplicate == true)
		ft_error("Duplicate map arguments.\n");
	if (!color_range(data->mapinfo.c))
		ft_error("Wrong color ranges for ceiling\n");
	if (!color_range(data->mapinfo.f))
		ft_error("Wrong color ranges for floor\n");
}

void	parse_mapinfo(char *str, new_t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (data->mapinfo.columns < i - 1)
		data->mapinfo.columns = i - 1;
	data->mapinfo.rows++;
}

void	parse_input(int fd, new_t_data *data, new_t_mapchecker *elements)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (check_for_map(line) == 1)
			break ;
		check_input(line, data, elements);
		free(line);
		line = get_next_line(fd);
	}
	while (line && check_for_map(line) == 1)
	{
		parse_mapinfo(line, data);
		free(line);
		line = get_next_line(fd);
	}
}

void print_mapchecker(new_t_mapchecker elements)
{
	printf("no: %d\n", elements.no);
	printf("so: %d\n", elements.so);
	printf("we: %d\n", elements.we);
	printf("ea: %d\n", elements.ea);
	printf("c: %d\n", elements.c);
	printf("f: %d\n", elements.f);
	printf("all_eles: %d\n", elements.all_eles);
	printf("duplicate: %d\n", elements.duplicate);
}

int	parse_cub(char *argv, new_t_data *data)
{
	new_t_mapchecker	elements;
	int				fd;

	init_map_checker(&elements); //keep the same, mapchecker is seperate from the main struct
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Error opening map.. Weird. Try again!\n");
	parse_input(fd, data, &elements);
	close(fd);
	map_errors(&elements, data);
	print_mapchecker(elements);
	/*fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Error opening map.. Weird. Try again!\n");
	parse_map(fd, *mapinfo, map);
	close(fd);
	tester(*mapinfo); //remove later
	test_map(*map, *mapinfo);*/
	return (0);
}