#include "wolf3d.h"

void				derive_map(t_map *map)
{
	int		i;
	int		j;
	char	**str;
	int		fd;

	str = NULL;
	fd = open("map.txt", O_RDONLY);
		if (fd < 0)
			return ;
	while (get_next_line(fd, str))
	{
		j = 0;
		while (str[j] != '\0')
		{
			if (ft_isdigit(*str[j]))
			{
				map->world_map[i][j] = ft_atoi(&(*str[j]));
				j++;
			}
		}
		i++;
	}
}

int					init_env(t_map *map)
{
	map->pos_x = 22;
	map->pos_y = 12;
	map->dir_x = -1;
	map->dir_y = 0;
	map->plane_x = 0;
	map->plane_y = 0.66;
	map->time = 0;
	map->old_time = 0;
	map->ctrl = -1;
	if (!(map->mlx->mlx_con = mlx_init()))
		return (-1);
	map->mlx->window = mlx_new_window(map->mlx->mlx_con, SCR_W, SCR_H, "The Wolf");
	return (1);
}
