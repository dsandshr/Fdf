/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affairs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 20:24:23 by dsandshr          #+#    #+#             */
/*   Updated: 2019/11/24 00:50:44 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static s_mlx	*mlx_things_init(s_mlx *mlx)
{
	if (!(mlx->mlxPtr = mlx_init()))
		exit (-1);
	if (!(mlx->winPtr = mlx_new_window(mlx->mlxPtr, WIN_X, WIN_Y, WIN_NAME)))
		exit (-1);
	if (!(mlx->imgPtr = mlx_new_image(mlx->mlxPtr, WIN_X, WIN_Y)))
		exit (-1);
	if (!(mlx->imgData = mlx_get_data_addr(mlx->imgPtr, &mlx->bpp,\
		&mlx->size_l, &mlx->endian)))
		exit (-1);
	return (mlx);
	
}

void	fdf_affairs(s_fdf *fdf, s_mlx *mlx, s_map *map)
{
	mlx = mlx_things_init(mlx);
	
	mlx_loop(mlx->mlxPtr);
}