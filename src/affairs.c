/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affairs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 20:24:23 by dsandshr          #+#    #+#             */
/*   Updated: 2019/11/22 20:54:25 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_affairs(s_fdf *fdf, s_mlx *mlx, s_map *map)
{
	if (!(mlx->mlxPtr = mlx_init()))
		exit (-1);
	if (!(mlx->winPtr = mlx_new_window(mlx->mlxPtr, WIN_X, WIN_Y,\
		"Dsandshr's & Dmandalo's filler")))
		exit (-1);
	mlx_loop(mlx->mlxPtr);
}