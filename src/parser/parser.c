#include "../../inc/cub3d.h"

int	color_range(int	x)
{
	if (x < 0)
		return (0);
	if (x > 16777215)
		return (0);
	return (1);
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
		parse_mapinfo(line, mapinfo);
		free(line);
		line = get_next_line(fd);
	}
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
	/*map_errors(elements, *mapinfo);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Error opening map.. Weird. Try again!\n");
	parse_map(fd, *mapinfo, map);
	close(fd);
	tester(*mapinfo); //remove later
	test_map(*map, *mapinfo);*/
	return (0);
}