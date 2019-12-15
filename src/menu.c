/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:57:50 by dmandalo          #+#    #+#             */
/*   Updated: 2019/12/15 19:55:46 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_menu(t_mlx *data)
{
	char	*clr1;
	char	*clr2;

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	clr1 = ft_itoa_base(data->clr2, 16, 1);
	clr2 = ft_itoa_base(data->clr1, 16, 1);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 35, 0xffffff, "Controls:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 70, 0x90ee90, \
	"Moving: up, down, left, right");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 105, 0x90ee90, \
	"2D / 3D: Num_Enter");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 140, 0x90ee90, \
	"Colors: 1, 2, 3");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 175, 0x90ee90, \
	"Colors grid: ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 135, 175, data->clr2, clr1);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 210, 0x90ee90, \
	"Colors scale: ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 145, 210, data->clr1, clr2);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 245, 0x90ee90, "Zoom:+/-");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 280, 0x90ee90, \
	"Scale: P, M");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 315, 0x90ee90, "Ex :Esc");
	free(clr1);
	free(clr2);
}
