/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:16:39 by dmandalo          #+#    #+#             */
/*   Updated: 2019/12/15 21:26:59 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_mlx	*mlx_things_init(t_mlx *mlx)
{
	if (!(mlx->mlx_ptr = mlx_init()))
		exit(-1);
	if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_X, WIN_Y, WIN_NAME)))
		exit(-1);
	if (!(mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_X, WIN_Y)))
		exit(-1);
	if (!(mlx->img_data = (int*)mlx_get_data_addr(mlx->img_ptr, &mlx->bpp,\
		&mlx->size_l, &mlx->endian)))
		exit(-1);
	mlx->bpp /= 8;
	ft_bzero(mlx->img_data, WIN_X * WIN_Y * mlx->bpp);
	return (mlx);
}

void			fdf_affairs(t_mlx *mlx)
{
	mlx = mlx_things_init(mlx);
	draw(mlx);
	mlx_key_hook(mlx->win_ptr, deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);
}
