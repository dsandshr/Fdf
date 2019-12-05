/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:11:06 by dsandshr          #+#    #+#             */
/*   Updated: 2019/12/05 17:47:59 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		check_map(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] != 'f' || str[i - 2] != 'd'\
	|| str[i - 3] != 'f' || str[i - 4] != '.')
		error(BAD_MAP);
	return (1);
}

static s_map	*str_map_init(s_map *map)
{
	if (!(map = (s_map *)malloc(sizeof(map))))
		exit (-1);
	map->map = NULL;
	map->x = 0;
	map->y = 0;
	map->zoom = 20;
	map->color = 0;
	map->shift_x = 0;
	map->shift_y = 0;
	map->angle = 0;
	return (map);
}

static s_mlx	*mlx_sinit(s_mlx *mlx)
{
	if (!(mlx = (s_mlx *)malloc(sizeof(s_mlx))))
		exit (-1);
	mlx->mlxPtr = NULL;
	mlx->winPtr = NULL;
	mlx->imgPtr = NULL;
	mlx->imgData = NULL;
	mlx->bpp = 0;
	mlx->endian = 0;
	mlx->size_l = 0;
	mlx->map = NULL;
	return(mlx);
}

static s_fdf	*fdf_init(s_fdf *fdf)
{
	if (!(fdf = (s_fdf *)malloc(sizeof(s_fdf))))
		exit (-1);
	fdf->x = 0;
	fdf->y = 0;
	fdf->z = 0;
	fdf->next = NULL;
	return (fdf);
}

int main(int argc, char **argv)
{
	s_fdf	*fdf;
	s_mlx	*mlx;
	s_map	*map;

	map = NULL;
	mlx = NULL;
	fdf = NULL;
	if (argc != 2 || check_map(argv[1]))
		error(argc);
	fdf = fdf_init(fdf);
	map = str_map_init(map);
	mlx = mlx_sinit(mlx);
	fdf = init_map(argv, fdf, map);
	fdf_affairs(mlx, map);
	return (0);
}