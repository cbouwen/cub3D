#include "../../inc/cub3d.h"

void	map_errors(t_mapchecker *elements)
{
	if (elements->all_eles == false)
		ft_error("Not all elements are defined before map initialization.\n");
	if (elements->duplicate == true)
		ft_error("Duplicate map arguments.\n");
}

void	parse_mapinfo(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (data->mapinfo.columns < i - 1)
		data->mapinfo.columns = i - 1;
	data->mapinfo.rows++;
}

void	parse_input(int fd, t_data *data, t_mapchecker *elements)
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

void print_mapchecker(t_mapchecker elements) //debug
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

int	parse_cub(char *argv, t_data *data)
{
	t_mapchecker	elements;
	int				fd;

	init_map_checker(&elements);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Error opening map.. Weird. Try again!\n");
	parse_input(fd, data, &elements);
	close(fd);
	map_errors(&elements);

	print_mapchecker(elements); //debug

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Error opening map.. Weird. Try again!\n");
	parse_map(fd, data);
	close(fd);
	return (0);
}
