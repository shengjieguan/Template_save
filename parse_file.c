/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:19:33 by skoh              #+#    #+#             */
/*   Updated: 2019/10/22 15:19:19 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

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
/*
int		ft_check(char *b)
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
//	   	if(ft_match(c) == 0);
//			return (0);
		free(ar);
		free(c);
		b += 21;
	}
	return (1);
}
*/
int		tetri_are_valid(int ret, int hash_count, char *buf)
{
	while (ret > 0)
	{
		if (((ret + 1) % 21 == 0 || ret % 5 == 4) && buf[ret] != '\n')
			return (0);
		else if (ret % 5 < 4)
		{
			if (buf[ret] != '#' && buf[ret] != '.' && buf[ret] != '\n')
				return (0);
			if (buf[ret] == '#')
				hash_count--;
		}
		ret--;
	}
	if (hash_count == 0)
		return(check_valid_shapes(buf));
	return (0);
}

int		file_is_valid(int fd)
{
	if (fd < 0 || fd > OPEN_MAX)
		return (0);
	return (1);
}

int		parse_file(char *file)
{
	int			fd;
	int			ret;
	int			hash_count;
	static char	buf[545];

	fd = open(file, O_RDONLY);
	if (file_is_valid(fd) == 0)
		return (0);
	ret = read(fd, buf, 545);
	buf[ret] = '\0';
	close(fd);
	if (ret < 19 || ret > 544)
		return (0);
	if ((ret + 1) % 21 != 0)
		return (0);
	hash_count = ((ret + 1) / 21 * 4);
	printf("line count is %d\n", hash_count);
	if (tetri_are_valid(ret, hash_count, buf) == 0)
		return (0);
	ft_putstr(buf);
	return (1);
}

//char	*build_list(char *buf)
//{
	// build linked lists of structs
		// match and return type of tetrimino into a struct
	// return head of linked list to solver
//}
