/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affairs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 19:47:49 by dsandshr          #+#    #+#             */
/*   Updated: 2019/12/19 20:55:43 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		minus_z(t_mlx *data, int x, int y)
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

void		plus_z(t_mlx *data, int x, int y)
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
