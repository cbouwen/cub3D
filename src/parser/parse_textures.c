#include "../../inc/cub3d.h"

//void	text_file_error_check(t_data *data)
//{
	/*do something*/
	/*check notes, you dingus*/
//}

void	parse_texture(t_data *data)
{
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
	
	printf("%s", data->mapinfo.no);
	printf("1\n");
	//data->text[NORTH].img = 
	mlx_xpm_file_to_image(data->mlx, data->mapinfo.no, &data->text[NORTH].width, &data->text[NORTH].height);
	printf("2\n");
	int fd = open(data->mapinfo.no + 3, O_RDONLY);
	if (fd == -1)
		ft_error("Error opening texture... Weird. Try again!\n");
	if (!data->text[NORTH].img)
		ft_error("Error\nTexture not found");
	printf("3\n");
	if (data->text[NORTH].width != 64 || data->text[NORTH].height != 64)
		ft_error("Error\nTexture size not 64x64");
	printf("4\n");
	data->text[NORTH].addr = (int *)(mlx_get_data_addr(data->text[NORTH].img, &data->text[NORTH].bits_per_pixel, &data->text[NORTH].line_length, &data->text[NORTH].endian));
	printf("5\n");

	data->text[EAST].img = mlx_xpm_file_to_image(data->mlx, data->mapinfo.ea, &data->text[EAST].width, &data->text[EAST].height);
	if (!data->text[EAST].img)
		ft_error("Error\nTexture not found");
	if (data->text[EAST].width != 64 || data->text[EAST].height != 64)
		ft_error("Error\nTexture size not 64x64");
	data->text[EAST].addr = (int *)(mlx_get_data_addr(data->text[EAST].img, &data->text[EAST].bits_per_pixel, &data->text[EAST].line_length, &data->text[EAST].endian));

	data->text[SOUTH].img = mlx_xpm_file_to_image(data->mlx, data->mapinfo.so, &data->text[SOUTH].width, &data->text[SOUTH].height);
	if (!data->text[SOUTH].img)
		ft_error("Error\nTexture not found");
	if (data->text[SOUTH].width != 64 || data->text[SOUTH].height != 64)
		ft_error("Error\nTexture size not 64x64");
	data->text[SOUTH].addr = (int *)(mlx_get_data_addr(data->text[SOUTH].img, &data->text[SOUTH].bits_per_pixel, &data->text[SOUTH].line_length, &data->text[SOUTH].endian));

	data->text[WEST].img = mlx_xpm_file_to_image(data->mlx, data->mapinfo.we, &data->text[WEST].width, &data->text[WEST].height);
	if (!data->text[WEST].img)
		ft_error("Error\nTexture not found");
	if (data->text[WEST].width != 64 || data->text[WEST].height != 64)
		ft_error("Error\nTexture size not 64x64");
	data->text[WEST].addr = (int *)(mlx_get_data_addr(data->text[WEST].img, &data->text[WEST].bits_per_pixel, &data->text[WEST].line_length, &data->text[WEST].endian));	
}

