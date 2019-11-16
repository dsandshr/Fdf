/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:11:06 by dsandshr          #+#    #+#             */
/*   Updated: 2019/11/17 01:02:10 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static s_mlx	*mlx_sinit(s_mlx *mlx)
{
	if (!(mlx = (s_mlx *)malloc(sizeof(s_mlx))))
		exit (-1);
	mlx->mlxPtr = NULL;
	mlx->winPtr = NULL;
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

	mlx = NULL;
	fdf = NULL;
	if (argc != 2)
		error(argc);
	fdf = fdf_init(fdf);
	mlx = mlx_sinit(mlx);
	fdf = init_map(argv, fdf);
	draw(mlx, fdf);
	return (0);
}