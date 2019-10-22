#include "header.h"

int		ft_match(char *ar)
{
	char s[8];
	s == NULL;
	(MATCH_1 > 0) && s = "00010203";
	(MATCH_2 > 0) && s = "00102030";
	(MATCH_3 > 0) && s = "00100111";
	(MATCH_4 > 0) && s = "";
	(MATCH_5 > 0) && s = "";
	(MATCH_6 > 0) && s = "";
	(MATCH_7 > 0) && s = "";
	(MATCH_8 > 0) && s = "";
	(MATCH_9 > 0) && s = "";
	(MATCH_10 > 0) && s = "";
	(MATCH_11 > 0) && s = "";
	(MATCH_12 > 0) && s = "";
	(MATCH_13 > 0) && s = "";
	(MATCH_14 > 0) && s = "";
	(MATCH_15 > 0) && s = "";
	(MATCH_16 > 0) && s = "";
	(MATCH_17 > 0) && s = "";
	(MATCH_18 > 0) && s = "";
	(MATCH_19 > 0) && s = "";
	(s == NULL) ? return (0) : return (1);
}

int		ft_check(char *b)
{
	char c[21];
	char ar[21]
	int ret;

	while(*b)
	{
		ar = ft_strsub(b, 0, 21);
		
		puts(ar);
		ret = ft_strnchr(ar, '#') - ft_strchr(ar, '#');
		printf("%d", ret);
		while(ar != '#')
			ar++;
		c = ft_strsub(ar, 0, ret);
	   	if(ft_match(c) == 0);
			return (0);
		free(ar);
		free(c);
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

