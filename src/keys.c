/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:24:00 by dmandalo          #+#    #+#             */
/*   Updated: 2019/12/23 19:02:54 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			mlx_free(t_mlx **mlx)
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
	free(*mlx);
	mlx = NULL;
}

int				keys(int key, t_mlx *data)
{
	if (key == 112)
		plus_z(data, 0, 0);
	if (key == 109)
		minus_z(data, 0, 0);
	if (key == 50)
		data->clr1 = rand();
	if (key == 49)
		data->clr2 = rand();
	if (key == 51)
	{
		data->clr1 = rand();
		data->clr2 = rand();
	}
	if (key == KEY_SPACE)
	{
		data->iso = 0;
		data->angle = 0;
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	ft_bzero(data->img_data, WIN_X * WIN_Y * data->bpp);
	draw(data);
	return (0);
}

int				deal_key(int key, t_mlx *data)
{
	if (key == 13)
		data->iso ^= 1;
	if (key == 112)
		data->zoom += 1;
	if (key == 109)
		data->zoom -= 1;
	if (key == 27)
	{
		mlx_free(&data);
		exit(-1);
	}
	if (key == KEY_NUMERIC_A)
		data->shift_y -= 40;
	if (key == KEY_NUMERIC_B)
		data->shift_y += 40;
	if (key == KEY_NUMERIC_D)
		data->shift_x -= 40;
	if (key == KEY_NUMERIC_C)
		data->shift_x += 40;
	keys(key, data);
	return (0);
}

int				many_keys(int key, t_mlx *data)
{
	if (key == 119)
	{
		data->iso = 2;
		data->angle -= 0.1;
	}
	if (key == 115)
	{
		data->iso = 2;
		data->angle += 0.1;
	}
	if (key == 97)
	{
		data->iso = 3;
		data->angle -= 0.1;
	}
	if (key == 100)
	{
		data->iso = 3;
		data->angle += 0.1;
	}
	deal_key(key, data);
	return (0);
}
