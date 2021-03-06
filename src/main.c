/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:11:06 by dsandshr          #+#    #+#             */
/*   Updated: 2019/12/19 18:18:35 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_del(t_fdf **fdf)
{
	t_fdf *tmp;
	t_fdf *res;

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

static t_fdf	*fdf_init(t_fdf *fdf)
{
	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
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
	return (check_in_map(str, 0));
}

t_mlx			*init_mlx(t_fdf *fdf, char **str, t_mlx *mlx)
{
	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		exit(-1);
	fdf = fdf_init(fdf);
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->img_ptr = NULL;
	mlx->size_l = 0;
	mlx->endian = 0;
	mlx->img_data = 0;
	mlx->bpp = 0;
	mlx->map = NULL;
	mlx->x = 0;
	mlx->y = 0;
	mlx->zoom = 20;
	mlx->clr = 0;
	mlx->shift_x = 840;
	mlx->shift_y = 400;
	mlx->angle = 0;
	mlx->iso = 0;
	mlx->clr1 = 0x43cd3747;
	mlx->clr2 = 0x3b72f5f6;
	fdf = init_map(str, fdf, mlx);
	fdf_del(&fdf);
	return (mlx);
}

int				main(int argc, char **argv)
{
	t_mlx *mlx;
	t_fdf *fdf;

	fdf = NULL;
	mlx = NULL;
	if (argc != 2)
		error(argc);
	if (check_map(argv[1]) == 1)
	{
		mlx = init_mlx(fdf, argv, mlx);
		mlx->coss = 0;
		mlx->sins = 0.8;
		fdf_affairs(mlx);
	}
	error(BAD_MAP);
	return (0);
}
