#include "wolf3d.h"

int		main(void)
{
	printf("What up\n");
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	derive_map(map);
	printf("What up\n");
	if (!(init_env(map)))
	{
		perror("Error");
		return (1);
	}
	play_game(map);
	return (0);
}
