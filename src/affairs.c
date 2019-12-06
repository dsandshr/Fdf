/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affairs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 20:24:23 by dsandshr          #+#    #+#             */
/*   Updated: 2019/12/06 21:34:13 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, s_mlx *data)
{
	printf("d\n, key");

	if (key == KEY_UP_ARROW)
		data->shift_y -= 40;
	if (key == KEY_DOWN_ARROW)
		data->shift_y += 40;
	if (key == KEY_LEFT_ARROW)
		data->shift_x -= 40;
	if (key == KEY_RIGHT_ARROW)
		data->shift_x += 40;
	mlx_clear_window(data->mlxPtr, data->winPtr);
	draw(data);
	return (0);
}

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
	mlx->bpp /= 8;// pixel put | put image
	ft_bzero(mlx->imgData, WIN_X * WIN_Y * mlx->bpp);//
	return (mlx);//
}

void	fdf_affairs(s_mlx *mlx)
{
	mlx = mlx_things_init(mlx);
	draw(mlx);
	mlx_key_hook(mlx->winPtr, deal_key, mlx);
	mlx_loop(mlx->mlxPtr);
}