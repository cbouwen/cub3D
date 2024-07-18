#include "../../inc/cub3d.h"

//void	text_file_error_check(t_data *data)
//{
	/*do something*/
	/*check notes, you dingus*/
//}

/*image maken met xpm_file_to_image + texture size check + destroy image*/
	/*over elke texture, init_mlx_img*/
	/*
		maak een image aan met mlx_xpm_file_to_image
		als de image niet aangemaakt kan worden, geef een error
		als de image wel aangemaakt kan worden, check de grootte van de image
		als de grootte van de image niet klopt, geef een error
		als de grootte van de image wel klopt, maak een mlx_img aan met mlx_get_data_addr
		slaag de addr op in een temp variable
		calloc de image in de data struct (H * W * sizeof(int))
		loop over height
		loop over width
		data->img.addr[y * width + x] = temp[y * (line_length / 4) + x]
	*/

void	parse_texture(t_data *data)
{
	parse_texture_helper(data, NORTH, data->mapinfo.no);
	parse_texture_helper(data, EAST, data->mapinfo.ea);
	parse_texture_helper(data, SOUTH, data->mapinfo.so);
	parse_texture_helper(data, WEST, data->mapinfo.we);	
}

void	parse_texture_helper(t_data *data, int dir, char *path)
{
	int	*temp;
	int x;
	int y;
	
	data->text[dir].img = mlx_xpm_file_to_image(data->mlx, path, &data->text[dir].width, &data->text[dir].height);
	if (!data->text[dir].img)
		ft_error("Error\nTexture not found");
	if (data->text[dir].width != 128 || data->text[dir].height != 128) //nog aanpassen naar de juiste check (check tegen elkaar niet gewoon de size) || also voeg define toe aan header voor de grootte
		ft_error("Error\nTexture size not 64x64");
	temp = (int *)(mlx_get_data_addr(data->text[dir].img, &data->text[dir].bits_per_pixel, &data->text[dir].line_length, &data->text[dir].endian));
	if (!temp)
		ft_error("Error\nTexture not found");
	data->text[dir].addr = (int *)ft_calloc(data->text[dir].width * data->text[dir].height, sizeof(int));
	if (!data->text[dir].addr)
		ft_error("Error\nCalloc failed");
	y = -1;
	while (++y < data->text[dir].height)
	{
		x = -1;
		while (++x < data->text[dir].width)
			data->text[dir].addr[y * data->text[dir].width + x] = temp[y * (data->text[dir].line_length / 4) + x];
	}
}

