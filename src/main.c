/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:11:06 by dsandshr          #+#    #+#             */
/*   Updated: 2019/12/14 17:23:25 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_del(s_fdf **fdf)
{
	s_fdf *tmp;
	s_fdf *res;

	if (fdf)
	{
		if ((*fdf))
		{
			res = (*fdf);
			while (res)
			{
				tmp = res->next;
				free(res);
				res = tmp;
			}
			(*fdf) = NULL;
		}
	}
}

static s_fdf	*fdf_init(s_fdf *fdf)
{
	if (!(fdf = (s_fdf *)malloc(sizeof(s_fdf))))
		exit(-1);
	fdf->x = 0;
	fdf->y = 0;
	fdf->z = 0;
	fdf->next = NULL;
	return (fdf);
}

static int		check_map(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] != 'f' || str[i - 2] != 'd'\
	|| str[i - 3] != 'f' || str[i - 4] != '.')
		error(BAD_MAP);
	return (1);
}

s_mlx			*init_mlx(s_fdf *fdf, char **str, s_mlx *mlx)
{
	if (!(mlx = (s_mlx *)malloc(sizeof(s_mlx))))
		exit(-1);
	fdf = fdf_init(fdf);
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->imgPtr = NULL;
	mlx->size_l = 0;
	mlx->endian = 0;
	mlx->imgData = 0;
	mlx->bpp = 0;
	mlx->map = NULL;
	mlx->x = 0;
	mlx->y = 0;
	mlx->zoom = 20;
	mlx->clr = 0;
	mlx->shift_x = 840;
	mlx->shift_y = 400;
	mlx->angle = 0.523599;
	mlx->iso = 0;
	mlx->clr1 = 0x43cd3747;
	mlx->clr2 = 0x3b72f5f6;
	fdf = init_map(str, fdf, mlx);
	fdf_del(&fdf);
	return (mlx);
}

int				main(int argc, char **argv)
{
	s_mlx *mlx;
	s_fdf *fdf;

	fdf = NULL;
	mlx = NULL;
	if (argc != 2)
		error(argc);
	if (check_map(argv[1]) == 1)
	mlx = init_mlx(fdf, argv, mlx);
	fdf_affairs(mlx);
	return (0);
}
