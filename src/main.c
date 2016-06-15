#include "wolf3d.h"

int		main(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	derive_map(map);
	if (!(init_env(map)))
	{
		perror("Error");
		return (1);
	}
	play_game(map);
	return (0);
}
