/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 00:16:33 by dsandshr          #+#    #+#             */
/*   Updated: 2019/11/17 01:41:16 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void drawLine(s_fdf *fdf, s_mlx *mlx) {
	int x1, x2, y1, y2;
	x1 = fdf->x;
	x2 = fdf->next->x;
	y1 = fdf->y;
	y2 = fdf->next->y;
	const int deltaX = abs(x2 - x1);
    const int deltaY = abs(y2 - y1);
    const int signX = x1 < x2 ? 1 : -1;
    const int signY = y1 < y2 ? 1 : -1;
    //
    int error = deltaX - deltaY;
    mlx_pixel_put(mlx->mlxPtr, mlx->winPtr, 255 + x2 * 20, 255 + y2 * 20, 255);
    while(x1 != x2 || y1 != y2) 
   {
        mlx_pixel_put(mlx->mlxPtr, mlx->winPtr, 255 + x1 * 20, 255 + y1 * 20, 255);
        const int error2 = error * 2;
        //
        if(error2 > -deltaY) 
        {
            error -= deltaY;
            x1 += signX;
        }
        if(error2 < deltaX) 
        {
            error += deltaX;
            y1 += signY;
        }
    }
}
 
void	draw(s_mlx *mlx, s_fdf *fdf)
{
	//s_fdf *fdf_ptr;

	//fdf_ptr = fdf;
	mlx->mlxPtr = mlx_init();
	mlx->winPtr = mlx_new_window(mlx->mlxPtr, WIN_X, WIN_Y, WIN_NAME);
	while (fdf->next != NULL)
	{
		drawLine(fdf, mlx);
		fdf = fdf->next;
	}
	mlx_loop(mlx->mlxPtr);
}