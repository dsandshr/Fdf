/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 19:48:06 by dsandshr          #+#    #+#             */
/*   Updated: 2019/12/19 20:49:05 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		primary(t_prm m, t_mlx *data)
{
	int		max;
	float	x_step;
	float	y_step;

	m.x += data->shift_x;
	m.y += data->shift_y;
	m.x1 += data->shift_x;
	m.y1 += data->shift_y;
	x_step = m.x1 - m.x;
	y_step = m.y1 - m.y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(m.x - m.x1) || (int)(m.y - m.y1))
	{
		if (m.y > 0 && m.y < WIN_Y && m.x > 0 && m.x < WIN_X)
			data->img_data[((int)m.y * WIN_X) + (int)m.x] = data->clr;
		m.x += x_step;
		m.y += y_step;
	}
}

void		lapse(t_mlx *data, t_prm m)
{
	if (data->iso == 1)
	{
		isometric(&m.x, &m.y, m.z, data);
		isometric(&m.x1, &m.y1, m.z1, data);
	}
	if (data->iso == 2)
	{
		rot_x(&m.x, &m.y, m.z, data);
		rot_x(&m.x1, &m.y1, m.z1, data);
	}
	if (data->iso == 3)
	{
		rot_y(&m.x, &m.y, m.z, data);
		rot_y(&m.x1, &m.y1, m.z1, data);
	}
	primary(m, data);
}

void		prime(t_prm m, t_mlx *data)
{
	float	x_step;
	float	y_step;
	int		max;

	m.z = data->map[(int)m.y][(int)m.x];
	m.z1 = data->map[(int)m.y1][(int)m.x1];
	m.x *= data->zoom;
	m.y *= data->zoom;
	m.x1 *= data->zoom;
	m.y1 *= data->zoom;
	m.z *= data->zoom / 3;
	m.z1 *= data->zoom / 3;
	data->clr = (m.z || m.z1) ? data->clr1 : data->clr2;
	lapse(data, m);
}

void		draw(t_mlx *data)
{
	t_prm	xy;

	xy.y = 0.0;
	while (data->map[(int)xy.y] != NULL)
	{
		xy.x = 0.0;
		while ((int)xy.x < data->x)
		{
			if ((int)xy.x < data->x - 1)
			{
				xy.y1 = xy.y;
				xy.x1 = xy.x + 1;
				prime(xy, data);
			}
			if ((int)xy.y + 1 < data->y)
			{
				xy.y1 = xy.y + 1;
				xy.x1 = xy.x;
				prime(xy, data);
			}
			xy.x++;
		}
		xy.y++;
	}
	print_menu(data);
}
