#include "../../inc/cub3d.h"

void	parse_path(char *str, new_t_data *data)
{
	size_t	i;

	i = 0;
	while (str[i + 3] && (str[i + 3] != 32 && str[i + 3] != '\n'))
		i++;
	if (str[0] == 'N')
		data->mapinfo.no = ft_strndup(str + 3, i);
	else if (str[0] == 'S')
		data->mapinfo.so = ft_strndup(str + 3, i);
	else if (str[0] == 'W')
		data->mapinfo.we = ft_strndup(str + 3, i);
	else if (str[0] == 'E')
		data->mapinfo.ea = ft_strndup(str + 3, i);
}

void	parse_color_values(int *X, char *str, int i)
{
	int	red;
	int	green;
	int	blue;

	red = ft_atoi(str + i);
	while (str[i] != 44)
		i++;
	green = ft_atoi(str + ++i);
	while (str[i] != 44)
		i++;
	blue = ft_atoi(str + ++i);
	*X = (red << 16) | (green << 8) | blue;
}

void	parse_color(char *str, new_t_data *data)
{
	int	i;

	i = 2;
	while (str[i] == 32)
		i++;
	if (str[0] == 'F')
		parse_color_values(&data->mapinfo.f, str, i);
	else
		parse_color_values(&data->mapinfo.c, str, i);
}

void	check_input(char *str, new_t_data *data, t_mapchecker *elements)
{
	int	i;

	i = 0;
	while (str[i] == 32)
		i++;
	while (str[i])
	{
		if (!ft_strncmp(str + i, "F ", 2) || !ft_strncmp(str + i, "C ", 2))
		{
			parse_color(str + i, data);
			update_mapchecker(str + i, elements);
		}
		/*if (!ft_strncmp(str + i, "NO ", 3) || !ft_strncmp(str + i, "SO ", 3)
			|| !ft_strncmp(str + i, "WE ", 3) || !ft_strncmp(str + i, "EA ", 3))
		{
			parse_path(str + i, data);
			update_mapchecker(str + i, elements);
		}*/
		i++;
	}
}