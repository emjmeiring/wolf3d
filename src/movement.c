#include "wolf3d.h"

void		move_up(t_map *map)
{
	if (map->world_map[(int)(map->map_x + map->dir_x * map->move_speed)][(int)map->pos_y] == 0)
	{
		map->pos_x += map->dir_x * map->move_speed;
	}
	if (map->world_map[(int)map->pos_x][(int)(map->map_y + map->dir_y * map->move_speed)] == 0)
	{
		map->pos_y += map->dir_y * map->move_speed;
	}
}

//Both camera dir and plane must be rotated.
void		rot_right(t_map *map)
{
	double		prev_dir_x;
	double		prev_plane_x;

	prev_dir_x = map->dir_x;
	prev_plane_x = map->plane_x;
	map->dir_x = map->dir_x * cos(map->rot_speed) - map->dir_y *
									sin(map->rot_speed);
	map->dir_y = prev_dir_x * sin(map->rot_speed) + map->dir_y *
															cos(map->rot_speed);
	prev_plane_x = map->plane_x;
	map->plane_x = map->plane_x * cos(map->rot_speed) - map->plane_y *
															sin(map->rot_speed);
	map->plane_y = prev_plane_x * sin(map->rot_speed) + map->plane_y *
															cos(map->rot_speed);
}
