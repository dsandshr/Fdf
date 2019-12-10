/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:57:50 by dmandalo          #+#    #+#             */
/*   Updated: 2019/12/10 17:16:10 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_menu(s_mlx *data)
{
	int	y;
	
	y = 0;
	mlx_string_put(data->mlxPtr, data->winPtr, 10,  y += 35, 0xffffff, "dfsfdf");
	mlx_string_put(data->mlxPtr, data->winPtr, 10,  y += 35, 0x90ee90, "sdffdsfds");
	mlx_string_put(data->mlxPtr, data->winPtr, 10,  y += 35, 0x90ee90, "sdffdsfds");
	mlx_string_put(data->mlxPtr, data->winPtr, 10,  y += 35, 0x90ee90, "sdffdsfds");
	mlx_string_put(data->mlxPtr, data->winPtr, 10,  y += 35, 0x90ee90, "sdffdsfds");
	mlx_string_put(data->mlxPtr, data->winPtr, 10,  y += 35, 0x90ee90, "sdffdsfds");
}
