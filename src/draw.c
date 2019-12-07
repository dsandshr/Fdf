/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:11:30 by dmandalo          #+#    #+#             */
/*   Updated: 2019/12/07 15:57:10 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z)//заменить цифры и вернуть значения;принимать по памяти и заменить эти значения
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	bresenham(float x, float y, float x1, float y1, s_mlx *data) //[1:1] [3:12]
{
	float x_step;
	float y_step;
	int	max;
	int z;
	int z1;

	z = data->map[(int)y][(int)x]; //матрица z (округляем до int)
	z1 = data->map[(int)y1][(int)x1];

	x *= data->zoom; //zoom
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	z *= data->zoom / 4;
	z1 *= data->zoom / 4;

	data->color = (z || z1) ? 0x00FF00 : 0xD0D0D0;//цвет зависит от z координаты

	if (data->izo == 1)
	{
		isometric(&x, &y, z); //3D
		isometric(&x1, &y1, z1);
	}
	x += data->shift_x;//сдвиг
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;

	x_step = x1 - x; //3 - 1 = 2
	y_step = y1 - y; //12 -1 = 11

	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1)) //округл. до int чтобы разница доходила точно до 0
	{
		mlx_pixel_put(data->mlxPtr, data->winPtr, x, y, data->color);
		x += x_step; //увеличивать каждый ход x и y
		y += y_step;
	}
}

void	draw(s_mlx *data) //функция которая будет адрессовать карту
{
	int x;
	int y;

	y = 0;
	ft_printf("%i\n", data->y);
	while (data->map[y] != NULL)
	{
		x = 0;
		while (x < data->x)
		{
			if (x < data->x - 1) //-1 чтобы не вылазить за пределы карты
			bresenham(x, y, x + 1, y, data); //рис.горизонтально
			if (y + 1 < data->y)
			bresenham(x, y, x, y + 1, data); //рис.вертикально
			x++;
		}
		y++;
	}
}
