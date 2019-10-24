
int		x_bounds(char *space, int size)
{
	return (space[0] + x < size &&
				space[2] + x < size &&
				space[4] + x < size &&
				space[6] + x < size);	
}
int		y_bounds(char *space, int size)
{
	return (space[1] + y < size &&
				space[3] + y < size &&
				space[5] + y < size &&
				space[7] + y < size);	
}
int recursion(char **shape, char **map, int size,)
{
	int = x;
	int = y
	x = 0;
	y = 0;

	while(y_bounds(*space, size))
	{
		while(x_bounds(*space, size)
		{
			if(overlap(map, *space, x, y)  == 1)
			{
				place(map, *space, x, y);
				if (recursion(*(space + 1), map) == 1)
					return (1);
				else
					remove_tetri(map, *space);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}


char	**set_board(int size)
{
	char **map;
	int x;
	int y;
	y = -1;
	while(++y < size)
	{
		x = -1;
		while(++x < size)
			map[y][x] = '.';
	}
	return (map);
}

void	solve(char **shapes, int shapes_count )
{
	char **map;
	int size;

	size = 2;
	while(size * size < shapes_count * 4)
		size++;
	map = set_board(size);
	while(recursion(shapes, map,size) == 0)
	{
		size++;
		delete_map(map);
		map = set_board(size);
	}
	print_map(map, size);
	delete_map(map);
}

