#include "wolf3d.h"

void	vert_line(int x, t_map *map/*, t_color color*/)
{
	while (map->start <= map->end)
	{
		mlx_pixel_put(map->mlx->mlx_con, map->mlx->window, x, map->start++, 255);   
	}
}
