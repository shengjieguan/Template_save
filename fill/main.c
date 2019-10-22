#include "header.h"

int	main(int ar, char **av)
{
	int fd;
	if(ar != 2)
	{
		ft_putstr("usage: ./fillit filename\n");   //double check
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if(check_valid(fd) == 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	solve
	close(fd);
	return 0;
}
