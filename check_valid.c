#include "header.h"

int		check_valid_shapes(char *ar)
{
	char *tetri_str;
	tetri_str = NULL;

	(MATCH_1 > 0) && (tetri_str = "00010203");
	(MATCH_2 > 0) && (tetri_str = "00102030");
	(MATCH_3 > 0) && (tetri_str = "00100111");
	(MATCH_4 > 0) && (tetri_str = "00011112");
	(MATCH_5 > 0) && (tetri_str = "10200111");
	(MATCH_6 > 0) && (tetri_str = "10011102");
	(MATCH_7 > 0) && (tetri_str = "00101121");
	(MATCH_8 > 0) && (tetri_str = "10011121");
	(MATCH_9 > 0) && (tetri_str = "00102011");
	(MATCH_10 > 0) && (tetri_str = "00011102");
	(MATCH_11 > 0) && (tetri_str = "10011112");
	(MATCH_12 > 0) && (tetri_str = "00100102");
	(MATCH_13 > 0) && (tetri_str = "00102021");
	(MATCH_14 > 0) && (tetri_str = "10110212");
	(MATCH_15 > 0) && (tetri_str = "00011121");
	(MATCH_16 > 0) && (tetri_str = "00101112");
	(MATCH_17 > 0) && (tetri_str = "00102001");
	(MATCH_18 > 0) && (tetri_str = "00010212");
	(MATCH_19 > 0) && (tetri_str = "20011121");
	if (tetri_str == NULL)
		return (0);
	return (1);
}
int		check_valid(char *b)
{
	char *c;
	char *ar;
	int ret;

	while(*b)
	{
		ar = ft_strsub(b, 0, 21);
		
		puts(ar);
		ret = ft_strrchr(ar, '#') - ft_strchr(ar, '#');
		printf("%d", ret);
		while(*ar != '#')
			ar++;
		c = ft_strsub(ar, 0, ret);
	   	if(check_valid_shapes(c) == 0)
			return (0);
		free(ar);
		free(c);
		b += 21;
	}
	return (1);
}
int		tetri_are_valid(int ret, int hash_count, char *buf)
{
	while (ret > 0)
	{
		if (((ret + 1) % 21 == 0 || ret % 5 == 4) && buf[ret] != '\n')
			return (0);
		else if (ret % 5 < 4)
		{
			if (buf[ret] != '#' && buf[ret] != '.')
				return (0);
			if (buf[ret] == '#')
				hash_count--;
		}
		ret--;
	}
	printf("%d", hash_count);
	if (hash_count == 0)
		return(check_valid(buf));
	return (0);
}
int		parse_file(int fd)
{
	int			ret;
	int			hash_count;
	char	buf[545];

	if (fd < 0 || fd > OPEN_MAX)
		return (0);
	ret = read(fd, buf, 546);
	buf[ret] = '\0';
	if (ret < 19 || ret > 544)
		return (0);
	if ((ret + 1) % 21 != 0)
		return (0);
	hash_count = ((ret + 1) / 21 * 4);
	printf("line count is %d\n", hash_count);
	if (tetri_are_valid(ret, hash_count, buf) == 0)
		return (0);
	return (1);
}

