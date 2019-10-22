/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:04:43 by skoh              #+#    #+#             */
/*   Updated: 2019/10/22 15:18:41 by skoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (parse_file(argv[1]) == 0)
			ft_putstr("error\n");
	}
	else
	{
		ft_putstr("usage: ./fillit filename\n");
		return (1);
	}
	return (0);
}
