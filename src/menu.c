/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:57:50 by dmandalo          #+#    #+#             */
/*   Updated: 2019/12/12 17:34:36 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_menu(s_mlx *data)
{
	int	y;
	char *color1;
	char *color2;

	color1 = ft_itoa_base(data->color2, 16, 1);
	color2 = ft_itoa_base(data->color1, 16, 1);
	y = 0;
	mlx_string_put(data->mlxPtr, data->winPtr, 10,  y += 35, 0xffffff, "Button control");
	mlx_string_put(data->mlxPtr, data->winPtr, 10,  y += 35, 0x90ee90, "Moving: up, down, left, right");
	mlx_string_put(data->mlxPtr, data->winPtr, 10,  y += 35, 0x90ee90, "2D / 3D : Num_Enter");
	mlx_string_put(data->mlxPtr, data->winPtr, 10,  y += 35, 0x90ee90, "Colors: 1, 2, 3");
	mlx_string_put(data->mlxPtr, data->winPtr, 10,  y += 35, 0x90ee90, "Colors grid: ");
	mlx_string_put(data->mlxPtr, data->winPtr, 140,  y, data->color2, color1);
	mlx_string_put(data->mlxPtr, data->winPtr, 10,  y += 35, 0x90ee90, "Colors scale: ");
	mlx_string_put(data->mlxPtr, data->winPtr, 150,  y, data->color1, color2);
	mlx_string_put(data->mlxPtr, data->winPtr, 10,  y += 35, 0x90ee90, "Zoom: +/-");
	mlx_string_put(data->mlxPtr, data->winPtr, 10,  y += 35, 0x90ee90, "Scale: P, M");
	mlx_string_put(data->mlxPtr, data->winPtr, 10,  y += 35, 0x90ee90, "Exit : Esc");
	free(color1);
	free(color2);
}
