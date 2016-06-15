#include "wolf3d.h"

static void		calculate_line_height_to_draw(t_map *map)
{
	int		i;
	//Calculate height of line to draw on screen
	i = (int)(map_height / map->ray->norm_wall_dist);
	//calculate lowest and highest pixel to fill in current stripe
	map->start = -i / 2 + map_height / 2;
	if (map->start < 0)
		map->start = 0;
	map->end = i / 2 + map_height / 2;
	if (map->end >= map_height)
		map->end = map_height - 1;
}

static void		perform_dda(t_map *map)
{
	while (map->is_wall == 0)
	{
		//jump to next map square is x or y dir.
		if (map->ray->side_dist_x < map->ray->side_dist_y)
		{
			map->ray->side_dist_x += map->ray->delta_dx;
			map->map_x += map->step_x;
			map->is_wall = 0;
		}
		else
		{
			map->ray->side_dist_y += map->ray->delta_dy;
			map->map_y += map->step_y;
			map->is_wall = 0;
		}
		//Check if ray has hit a wall
		if (map->world_map[map->map_x][map->map_y] > 0)
			map->is_wall = 1;
		//Calculate distance projected in the cam dir.
		if (map->is_wall == 0)
			map->ray->norm_wall_dist = (map->map_x - map->ray->ray_pos_x +
								(1 - map->step_x) / 2 ) / map->ray->ray_dir_x;
		else
			map->ray->norm_wall_dist = (map->map_y - map->ray->ray_pos_y +
								(1 - map->step_y) / 2 ) / map->ray->ray_dir_y;
	}
	calculate_line_height_to_draw(map);
	
}
static void		ray_len_from_curr_pos(t_map *map, double dx, double dy)
{
	map->ray->delta_dx = sqrt(1 + (map->ray->ray_dir_y * map->ray->ray_dir_y) /
								(map->ray->ray_dir_x * map->ray->ray_dir_x));
	map->ray->delta_dy = sqrt(1 + (map->ray->ray_dir_x * map->ray->ray_dir_x) /
								(map->ray->ray_dir_y * map->ray->ray_dir_y));
	if (map->ray->ray_dir_x < 0)
	{
		map->step_x = -1;
		map->ray->side_dist_x = (map->ray->ray_pos_x - map->map_x) * dx;
	}
	else
	{
		map->step_x = 1;
		map->ray->side_dist_x = (map->map_x + 1.0 - map->ray->ray_pos_x) * dx;
	}
	if (map->ray->ray_dir_y < 0)
	{
		map->step_y = -1;
		map->ray->side_dist_y = (map->ray->ray_pos_y - map->map_y) * dy;
	}
	else
	{
		map->step_y = 1;
		map->ray->side_dist_y = (map->map_y + 1.0 - map->ray->ray_pos_y) * dx;
	}
	perform_dda(map);
}

static void		calculate_ray_pos_and_dir(t_map *map, int ctrl)
{
	map->cam_x = 2 * ctrl / (double)map_width - 1; //x in cam space
	map->ray->ray_pos_x = map->pos_x;
	map->ray->ray_pos_y = map->pos_y;
	map->ray->ray_dir_x = map->dir_x + map->plane_x * map->cam_x;
	map->ray->ray_dir_y = map->dir_y + map->plane_y * map->cam_x;
	map->map_x = (int)map->ray->ray_pos_x;
	map->map_y = (int)map->ray->ray_pos_y;
	ray_len_from_curr_pos(map, map->ray->delta_dx, map->ray->delta_dy);
}

void			play_game(t_map *map)
{
	while (1)
	{
		while ((++map->ctrl) < map_width)
		{
			calculate_ray_pos_and_dir(map, map->ctrl);
		//TODO: To be continued...
		}
	}
}
