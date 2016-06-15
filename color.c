#include "wolf3d.h"

static void		set_color(t_map *map, int r, int g, int b)
{
		map->color->r = (unsigned int)r;
		map->color->g = (unsigned int)g;
		map->color->b = (unsigned int)b;
}

t_color			*some_color(int picker, t_map *map)
{
	if (picker == 1)
		set_color(map, 255, 0, 0);
	else if (picker == 2)
		set_color(map, 0, 255, 0);
	else if (picker == 3)
		set_color(map, 0, 0, 255);
	else if (picker == 4)
		set_color(map, 255, 255, 255);
	return (map->color);
}

void			pick_wall_color(t_map *map)
{
	if (map->world_map[map->map_x][map->map_y] == 1)
		map->color = some_color(1, map);
	else if (map->world_map[map->map_x][map->map_y] == 2)
		map->color = some_color(2, map);
	else if (map->world_map[map->map_x][map->map_y] == 3)
		map->color = some_color(3, map);
	else if (map->world_map[map->map_x][map->map_y] == 4)
		map->color = some_color(4, map);
	else
		set_color(map, 255, 255, 0);
	if (map->is_wall == 1)
		map->color->r = map->color->r / 2; 
}
