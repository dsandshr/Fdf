/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:11:30 by dmandalo          #+#    #+#             */
/*   Updated: 2019/12/14 18:47:20 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	bresenham(float x, float y, float x1, float y1, s_mlx *data)
{
	float x_step;
	float y_step;
	int	max;
	int z;
	int z1;

	z = data->map[(int)y][(int)x];
	z1 = data->map[(int)y1][(int)x1];
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	z *= data->zoom / 2;
	z1 *= data->zoom / 2;
	data->clr = (z || z1) ? data->clr1 : data->clr2;
	if (data->iso == 1)
	{
		isometric(&x, &y, z);
		isometric(&x1, &y1, z1);
	}
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		if (y > 0 && y < WIN_Y && x > 0 && x < WIN_X)
			data->imgData[((int)y * WIN_X) + (int)x] = data->clr;
		x += x_step;
		y += y_step;
	}
}

void	draw(s_mlx *data)
{
	int x;
	int y;

	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_bzero(data->imgData, WIN_X * WIN_Y * data->bpp);
	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (x < data->x)
		{
			if (x < data->x - 1)
				bresenham(x, y, x + 1, y, data);
			if (y + 1 < data->y)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->imgPtr, 0, 0);
	print_menu(data);
}
