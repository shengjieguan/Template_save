#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../includes/get_next_line.h"
#include "../libft/libft.h"
#include "../miniLibX/mlx.h"
#include <string.h>
#define WIN_WID 1000
#define WIN_HEI 1000

// typedef struct    s_list_map
// {
//     struct s_list_map    *next;
//     int            data;
// }                t_list_map;

// typedef	struct	s_map
// {
// 	int			x;
// 	int			y;
// 	t_list_map  **map;
// }	
// 			t_map;
// t_list_map    *ft_create_elem(int data)
// {
//     t_list_map    *temp;

//     temp = malloc(sizeof(t_list_map));
//     temp->data = data;
//     temp->next = NULL;
//     return (temp);
// }
// void    ft_list_push_back(t_list_map **begin_list, int data)
// {
//     t_list_map    *current;

//     current = *begin_list;
//     if (!current)
//     {
//         *begin_list = ft_create_elem(data);
//         return ;
//     }
//     while (current->next != 0)
//         current = current->next;
//     current->next = ft_create_elem(data);
// }
typedef struct s_map
{
	double center_x;
	double center_y;
	//double c_z;
	int		x;
	int		y;
	int		num;
}				t_map;
typedef struct s_image
{
	int bpp;
	int endian;
	int size;
//	void	*ptr;
//	char	*str;
}				t_image;
typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*data;
	t_map 	*map[99999];
	int		map_width;
	int		map_height;
	int		count_point;
	int		map_num_max;
	int		map_num_min;
//	int		window_width;
//	int		window_height;
	t_image	*image;
}				t_mlx;



void	init(t_mlx *mlx)
{
	mlx->map_width = 0;
	mlx->map_height = -1;
	mlx->map_num_max = 0;
	mlx->map_num_min = 0;
//	mlx->window_width = 1800;
//	mlx->window_height = 800;

}
// int		ft_countstr(char **s)
// {
// 	int i;
// 	int j;

// 	j = 0;
// 	i = 0;
// 	while(s[j][i])
// 	{
// 		i = 0;
// 		while(s[j][i])
// 		{
// 			if(s[j][i] == '-')
// 				i++;
// 			while(ft_isdigit(s[j][i]))
// 				i++;
// 			if(s[j][i])
// 				return (0);
// 		}
// 		j++;
// 	}
// 	return (j);
// }
// void	line(int x0, int y0, int x, int y)
// {

// }
void	move_map_to_center(t_mlx *mlx)
{
	int i;

	i = -1;
	while(++i <= mlx->count_point)
	{
		mlx->map[i]->center_x = (WIN_WID - mlx->map_width / 2) + mlx->map[i]->x;
		mlx->map[i]->center_y = (WIN_HEI - mlx->map_height / 2) + mlx->map[i]->y;

		// if(mlx->map[i]->num >= 0 && mlx->map[i]->num >= mlx->map_num_max)
		// 	mlx->map_num_max = mlx->map[i]->num;
		// if(mlx->map[i]->num < 0 && mlx->map[i]->num < mlx->map_num_max)
		// 	mlx->map_num_min = mlx->map[i]->num;
	}

}
void swap(double *x, double *y)//使用指针传递地址
{
double temp;
temp=*x;
*x=*y;
*y=temp;
}


void				plot(t_mlx *mlx, int x, int y)
{
	int				i;
	int				dest;
	unsigned int	new_color;

	if (y < 0 || x < 0)
		return ;
	new_color = mlx_get_color_value(mlx->img, 0xFFFFFF);
	dest = y * mlx->image->size + x * (mlx->image->bpp / 8);
	i = -1;
	while (++i < mlx->image->bpp / 8)
	{
		if (mlx->image->endian == 0)
			mlx->data[dest + i] = new_color >> (i * 8) & 0xFF;
		else
			mlx->data[dest + i] = new_color >> (mlx->image->bpp - (i + 1) * 8) & 0xFF;
	}
}

void	line(t_map *cur, t_map *next, t_mlx *mlx)
//oid	line(t_map *cur, t_map *next)
{
	double	dx;
	double dy;
	double error;
	//double ystep;
	double y;
	double x;
	int steep;


	dx = ft_abs(next->center_x - cur->center_x);
	dy = ft_abs(next->center_y - cur->center_y);
	steep = (dy > dx ? 1 : 0);
	if (steep)
	{
		swap(&cur->center_x, &cur->center_y);
		swap(&next->center_x, &next->center_y);
	}
	// if(next->center_x < cur->center_x)
	// {
	// 	swap(next->center_x, cur->center_x);
	// 	swap(next->center_y, cur->center_y);
	// }
	dx = next->center_x - cur->center_x;
	dy = next->center_y - cur->center_y;
	error = dx / 2;
	y = cur->center_y;
	x = cur->center_x;
	//ystep = (next->center_y > cur->center_y ? 1 : -1);
	while(next->center_x >= ++x)
	{
		(steep) ? plot(mlx, y, x) : plot(mlx, x, y);
		error -= dy;
		if(error < 0)
		{
		//	y += ystep;
			y += 1;
			error +=dx;
		}
	}
}
void	draw_line(t_mlx *mlx)
{
	// int x;
	// int y;
	// t_map p1;
	// t_map p2;
	// int
	// x = 0;
	// y = 0;
	int i;

	i = 0;
	move_map_to_center(mlx);
	// while(y <= mlx->map_height)
	// {
	// 	x = 0;
	// 	while(x <= mlx->map_width)
	// 	{
	// 		if (x + 1 <= mlx->map_width)
	// 			line(mlx->map[y * mlx->map_height + x], );
	// 		else if(y + 1 <= mlx->map_height)
	// 			line(x, y, 0, y + 1);
	// 	}
	// 	y++;
	// }
	while (i <= mlx->count_point)
	{
		if(mlx->map[i]->x + 1 <= mlx->map_width)
			line(mlx->map[i], mlx->map[i + 1], mlx);
		if(mlx->map[i]->y + 1 <= mlx->map_height)
			line(mlx->map[i], mlx->map[i + mlx->map_width + 1], mlx);			
		i++;
	}
}
t_map	*add_to_map(int num, int x, int y, t_map *map)
{
	map->x = x;
	map->y = y;
	map->num = num;
	return (map);
}
int		read_file(t_mlx *mlx, int fd)
{
	char *line;
	char **s;
	int i;
	int j;
	t_map map;

	j = -1;
	mlx->map_width = 0;
	while(get_next_line(fd, &line) == 1)
	{
		 i = -1;
		mlx->map_height++;
		if(!*(s = ft_strsplit(line, ' ')))
			return (0);
		while(s[++i])
		{
			mlx->map[++j] = add_to_map(atoi(s[i]), i, mlx->map_height, &map);
			printf("%d", map.num);
		}
		if(mlx->map_width == 0)
			mlx->map_width = i;
		else if (mlx->map_width != 0 && mlx->map_width != i )
			return 0;
		
	}
	mlx->count_point = j;
	return (1);
}

int		main(int	ar, char **av)
{
	t_mlx	mlx;
	int fd;

	init(&mlx);
	printf("%d", mlx.map_height);
	if (ar < 2)
	{
		puts("not enough arguments");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if(fd < 0 || !read_file(&mlx, fd))
	{
		puts("Invaild file");
		return (1);
	}
	if (!(mlx.mlx = mlx_init())
		|| !(mlx.window = mlx_new_window(mlx.mlx, WIN_HEI, WIN_WID, "FDF"))
		|| !(mlx.image = ft_memalloc(sizeof(t_image)))
		|| !(mlx.img = mlx_new_image(mlx.mlx, WIN_HEI, WIN_WID))
		|| !(mlx.data = mlx_get_data_addr(mlx.img, &mlx.image->bpp, 
			&mlx.image->size, &mlx.image->endian)))
		exit(EXIT_FAILURE);
	draw_line(&mlx);
	mlx_loop(mlx.mlx);
	return (0);
}

