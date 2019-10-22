/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:02:48 by skoh              #+#    #+#             */
/*   Updated: 2019/10/22 15:19:50 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_tetri
{
	char	letter;
	struct	s_tetri *next;
}				t_tetri;

/* line */
# define MATCH_1 (ar == "####")
# define MATCH_2 (ar == "#...#...#...#")

/* square */
# define MATCH_3 (ar == "##..##")

/* Z */
# define MATCH_4 (ar == "#...##...#")
# define MATCH_5 (ar == "##.##")
# define MATCH_6 (ar == "#..##..#")
# define MATCH_7 (ar == "##...##")

/* _|_ */
# define MATCH_8 (ar == "#..###")
# define MATCH_9 (ar == "###..#")
# define MATCH_10 (ar == "#...##..#")
# define MATCH_11 (ar == "#..##...#")

/* L */
# define MATCH_12 (ar == "##..#...#")
# define MATCH_13 (ar == "###...#")
# define MATCH_14 (ar == "#...#..##")
# define MATCH_15 (ar == "#...###")
# define MATCH_16 (ar == "##...#...#")
# define MATCH_17 (ar == "###.#")
# define MATCH_18 (ar == "#...#...##")
# define MATCH_19 (ar == "#.###")

int		file_is_valid(int fd);
int		parse_file(char *file);
void	ft_putchar(char c);
void	ft_putstr(const char *s);

#endif
