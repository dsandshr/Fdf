/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affairs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 20:24:23 by dsandshr          #+#    #+#             */
/*   Updated: 2019/12/15 21:09:49 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		mlx_free(t_mlx **mlx)
{
	while ((*mlx)->y >= 0)
	{
		free((*mlx)->map[(*mlx)->y]);
		--(*mlx)->y;
	}
	(*mlx)->map = NULL;
	free(mlx);
	mlx = NULL;
}

static void		minus_z(t_mlx *data, int x, int y)
{
	while (data->map[y] != NULL)
	{
		x = 0;
		while (x < data->x)
		{
			if (data->map[y][x] < 0)
			{
				if (data->map[y][x] % 2 == 5)
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

static void		plus_z(t_mlx *data, int x, int y)
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

int				keys(int key, t_mlx *data)
{
	if (key == KEY_P)
		plus_z(data, 0, 0);
	if (key == KEY_M)
		minus_z(data, 0, 0);
	if (key == KEY_2)
		data->clr1 = rand();
	if (key == KEY_1)
		data->clr2 = rand();
	if (key == KEY_3)
	{
		data->clr1 = rand();
		data->clr2 = rand();
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_bzero(data->img_data, WIN_X * WIN_Y * data->bpp);
	draw(data);
	return (0);
}

int				deal_key(int key, t_mlx *data)
{
	if (key == KEY_NUM_ENTR)
		data->iso ^= 1;
	if (key == KEY_NUM_PLS)
		data->zoom += 1;
	if (key == KEY_NUM_SUB)
		data->zoom -= 1;
	if (key == KEY_ESC)
	{
		mlx_free(&data);
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
	keys(key, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_bzero(data->img_data, WIN_X * WIN_Y * data->bpp);
	draw(data);
	return (0);
}

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
