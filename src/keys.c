/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:24:00 by dmandalo          #+#    #+#             */
/*   Updated: 2019/12/19 21:02:45 by dmandalo         ###   ########.fr       */
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
	return (0);
}

int				many_keys(int key, t_mlx *data)
{
	if (key == KEY_W)
	{
		data->iso = 2;
		data->angle -= 0.1;
	}
	if (key == KEY_S)
	{
		data->iso = 2;
		data->angle += 0.1;
	}
	if (key == KEY_A)
	{
		data->iso = 3;
		data->angle -= 0.1;
	}
	if (key == KEY_D)
	{
		data->iso = 3;
		data->angle += 0.1;
	}
	deal_key(key, data);
	return (0);
}
