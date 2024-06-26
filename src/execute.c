#include "../inc/cub3d.h"

void execute_map(new_t_data *data)
{
	parse_player(data);
	init_raycasting(data);
	/*prep_dda(raycaster, *map);

	update_player(raycaster, mapinfo);//Final step*/
}