#include "header.h"
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
int	ft_find(char **ar, int x, int y)
{

	if(MATCH_1)
		return (1);

	else if(MATCH_2)
		return (2);
	else if(MATCH_3)
		return (3);
	else if(MATCH_4)
		return (4);
	else if(MATCH_5)
		return (5);
	else if(MATCH_6)
		return (6);
	else if(MATCH_7)
		return (7);
	else
		return (0);
}

int	ft_check(char **av)
{
	int x = 0;
	int y = 0;
	int i = 1;
	while (x < 4)
	{
		if(av[x][y] == '.')
			y++;
		else if(av[x][y] == '#')
		{
			return(ft_find(av, x, y));
		}
		x++;
	}
	return 0;
}
int	main(int argu, char **av)
{
	char ar[3][3];
	int x = 0;
	int y = 0;
	char *s[255];
	char buf;
	int ret;
	int count = 0;
	int fd;
	if(argu != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	else
	{
		fd = open("av[1]", O_RDONLY);
		while((ret = read(fd, buf[5], 5) > 0))
		{
			if(ret > 5)
				return 0;
			buf[5] = '\0';
			s[fd] = ft_strdup(&buf);
			if(s[fd][4] != '\n')
				return 0;
			while(s[fd][y])
			{
				if(s[fd][y] == '#')
				{
					count++;
					ar[x][y] = '#';
				}
				else if(s[fd][y] == '.')
					ar[x][y] = '.';
				else if(s[fd][y] != '.' || s[fd][y] != '#')
					return 0;
				if(count > 4)
					return 0;
				y++;
			}
			if(x == 3 && y == 3)
			{
				if(ft_check((char**)&ar) > 0)
				{
					free(ar);
					x = -1;
				}
				else
					return 0;
			}
			x++;
			y = 0;
		}
	}
	return 0;
}
