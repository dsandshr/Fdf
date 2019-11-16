/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:57:24 by dsandshr          #+#    #+#             */
/*   Updated: 2019/11/17 00:16:13 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** Lib
*/

# include "mlx.h"
# include "libft.h"
# include <math.h>

/*
** other defines
*/

# define WIN_X 600
# define WIN_Y 800
# define WIN_NAME "Fdf by Dsandshr"
# define BAD_MAP 50

typedef struct	l_mlx
{
	void		*mlxPtr;
	void		*winPtr;
}				s_mlx;

typedef struct	l_fdf
{
	int					x;
	int					y;
	int					z;
	struct l_fdf		*next;
}				s_fdf;



/*
** func
*/

void	error(int argc);
s_fdf 	*init_map(char **argv, s_fdf *fdf);
void	draw(s_mlx *mlx, s_fdf *fdf);
#endif