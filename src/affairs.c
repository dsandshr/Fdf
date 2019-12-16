/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affairs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:35:56 by dsandshr          #+#    #+#             */
/*   Updated: 2019/12/16 17:59:50 by dsandshr         ###   ########.fr       */
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
	mlx_destroy_image((*mlx)->mlx_ptr, (*mlx)->img_ptr);
	mlx_destroy_window((*mlx)->mlx_ptr, (*mlx)->win_ptr);
	free((*mlx)->mlx_ptr);
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
				if (data->map[y][x] % 2 >= 5)
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
