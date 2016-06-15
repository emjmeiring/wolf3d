#include <math.h>
#include <string.h> //Remember to change this if not using it.
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "../libft/libft.h"
#include <fcntl.h>
#define map_height 24
#define map_width 24
#define SCR_H 600
#define SCR_W 900

typedef struct		s_ray_specs
{
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dx;
	double			delta_dy;
	double			norm_wall_dist;
}					t_ray;

typedef struct		s_color_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_color;

typedef struct		s_mlx_stuff
{
	void			*mlx_con;
	void			*window;
}					t_mlx;

typedef struct		s_world_map
{
	int				**world_map; //The world
	int				ctrl; //Loop control
	int				map_x; //Coordinates on the map.
	int				map_y;
	double			pos_x; //x and y start positions
	double			pos_y;
	double			dir_x; //initial direction vector
	double			dir_y;
	double			time; //time of the current frame
	double			old_time;
	double			plane_x; //camera plane
	double			plane_y;
	double			cam_x;
	double			move_speed;
	double			rot_speed;
	t_mlx			*mlx;
	t_ray			*ray;
	t_color			*color;
	int				step_x;
	int				step_y;
	int				is_wall;
	int				side_wall;
	int				start; //For drawing lines.
	int				end;
}					t_map;

void				derive_map(t_map *map);
int					init_env(t_map *map);
void				pick_wall_color(t_map *map);
void				vert_line(int x, t_map *map/*, t_color color*/);
void				play_game(t_map *map);
