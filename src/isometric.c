/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:13:51 by dmandalo          #+#    #+#             */
/*   Updated: 2019/12/23 18:22:22 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		isometric(float *x, float *y, int z, t_mlx *data)
{
	float	previous_x;
	float	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void		rot_y(float *x, float *y, int z, t_mlx *data)
{
	*x = *x * cos((M_PI_4 / 2) * data->angle) + z * \
	sin((M_PI_4 / 2) * data->angle);
	*y = *y;
	z = (*x * -1) * sin((M_PI_4 / 2) * data->angle) + z * \
	cos((M_PI_4 / 2) * data->angle);
}

void		rot_x(float *x, float *y, int z, t_mlx *data)
{
	*x = *x;
	*y = *y * cos((M_PI_4 / 2) * data->angle) + z * \
	sin((M_PI_4 / 2) * data->angle);
	z = (*y * -1) * sin((M_PI_4 / 2) * data->angle) + z * \
	cos((M_PI_4 / 2) * data->angle);
}
