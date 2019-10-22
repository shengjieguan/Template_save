#include "header.h"

int		ft_match(char **ar, int x, int y)
{
	
	while(x < 4)
	{
		if(ft_strchr(ar[x], '#') == NULL)
			i++;
		else
		{
			while(
		

int		ft_check(char *b)
{
	char c[21];
	t_xy *c;
	static char s[546];
	s = b;
	char ar[3][3]


	while(*b)
	{
		ar[0] = ft_strsub(b, 0, 4);
		ar[1] = ft_strsub(b, 5, 4);
		ar[2] = ft_strsub(b, 10, 4);
		ar[3] = ft_strsub(b, 15, 4);
	   	if(ft_match(ar, 0, 0) == 0)
			return (0);
		free(ar);
		*(b + 21);
	}
	return (1);
}

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
		if((ret + 1) % 21 == 0 || ret % 5 == 4)
			(b[ret] != '\n') && return (0);
		else if(ret % 5 < 4)
		{
			(b[ret] != '#' && b[ret] != '.' && b != '\n') && return (0);
			(b[ret] == '#') && count--;
		}
	}
	(count != 0) && return (0);
	return (ft_check(b));
}
	 
		
	
