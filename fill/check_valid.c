#include "header.h"

int	check_valid(int fd)
{
	int ret;
	char b[546];
	int count;
	int i = -1;

	(fd < 0) ? return (0) : ret = read(fd, b, 546);
	(ret > 545 || ret < 19) && return (0);
	((ret + 1) % 21) ? return (0) : count = ((ret + 1) / 21) * 4;
	while (ret--)
	{
		(b[ret] != '#' && b[ret] != '.' && b != '\n') && return (0);
		(b[ret] == '#') && count--;
	}
	(count != 0) && return (0);
	 
		
	
