/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affairs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 20:24:23 by dsandshr          #+#    #+#             */
/*   Updated: 2019/12/11 18:05:54 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void mlx_free(s_mlx *mlx)
// {
// 	free(mlx->mlxPtr);
// 	free(mlx->winPtr);
// 	free(mlx->imgPtr);
// 	free(mlx->size_l);
// 	free(mlx->endian);
// 	free(mlx->imgData);
// 	free(mlx->bpp);
// 	while (mlx->y != 0)
// 	{
// 		free(mlx->map[mlx->y]);
// 		--mlx->y;
// 	}
// 	free(mlx->map);
// 	free(mlx->x);
// 	free(mlx->y);
// 	free(mlx->zoom);
// 	free(mlx->color);
// 	free(mlx->shift_x);
// 	free(mlx->shift_y);
// 	free((int)mlx->angle);
// 	free(mlx->izo);
// 	free(mlx->color1);
// 	free(mlx->color2);
// }

static void minus_z(s_mlx *data, int x, int y)
{
	while (data->map[y] != NULL)
	{
		x = 0;
		while (x < data->x)
		{
			if (data->map[y][x] < 0)
			{	if (data->map[y][x] % 2 == 5)
					data->map[y][x] = MIN_Z(data->map[y][x]) - 1;
				else
					data->map[y][x] = MIN_Z(data->map[y][x]);
			}
			if (data->map[y][x] > 0)
			{
				if (data->map[y][x] % 2 == 5)
					data->map[y][x] = PL_Z(data->map[y][x]) + 1;
				else
					data->map[y][x] = PL_Z(data->map[y][x]);
			}
			x++;
		}
		y++;
	}
}

static void plus_z(s_mlx *data, int x, int y)
{
	while (data->map[y] != NULL)
	{
		x = 0;
		while (x < data->x)
		{
			if (data->map[y][x] < 0)
				data->map[y][x] *= 2;
			if (data->map[y][x] > 0)
				data->map[y][x] *= 2;
			x++;
		}
		y++;
	}
}

int				deal_key(int key, s_mlx *data)
{
	if (key == KEY_P)
		plus_z(data, 0, 0);
	if (key == KEY_M)
		minus_z(data, 0, 0);
	if (key == KEY_2)
		data->color1 = rand();
	if (key == KEY_1)
		data->color2 = rand();
	if (key == KEY_3)
	{
		data->color1 = rand();
		data->color2 = rand();
	}
	if (key == KEY_NUM_ENTR)
		data->izo ^= 1;
	if (key == KEY_NUM_PLS)
		data->zoom += 1;
	if (key == KEY_NUM_SUB)
		data->zoom -= 1;
	if (key == KEY_ESC)
	{
		//mlx_free(data);
		exit(-1);
	}
	if (key == KEY_UP_ARROW)
		data->shift_y -= 40;
	if (key == KEY_DOWN_ARROW)
		data->shift_y += 40;
	if (key == KEY_LEFT_ARROW)
		data->shift_x -= 40;
	if (key == KEY_RIGHT_ARROW)
		data->shift_x += 40;
	draw(data);
	return (0);
}

static s_mlx	*mlx_things_init(s_mlx *mlx)
{
	if (!(mlx->mlxPtr = mlx_init()))
		exit(-1);
	if (!(mlx->winPtr = mlx_new_window(mlx->mlxPtr, WIN_X, WIN_Y, WIN_NAME)))
		exit(-1);
	if (!(mlx->imgPtr = mlx_new_image(mlx->mlxPtr, WIN_X, WIN_Y)))
		exit(-1);
	if (!(mlx->imgData = (int*)mlx_get_data_addr(mlx->imgPtr, &mlx->bpp,\
		&mlx->size_l, &mlx->endian)))
		exit(-1);
	mlx->bpp /= 8;
	ft_bzero(mlx->imgData, WIN_X * WIN_Y * mlx->bpp);
	return (mlx);
}

void			fdf_affairs(s_mlx *mlx)
{
	mlx = mlx_things_init(mlx);
	draw(mlx);
	mlx_key_hook(mlx->winPtr, deal_key, mlx);
	mlx_loop(mlx->mlxPtr);
}
