/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:57:24 by dsandshr          #+#    #+#             */
/*   Updated: 2019/12/07 15:37:01 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** Lib
*/

# include "mlx.h"
# include "libft.h"
# include "keymap.h"
# include <math.h>

/*
** other defines
*/
# define WIN_Y 1080
# define WIN_X 1920
# define WIN_NAME "Dsandshr's & Dmandalo's Fdf"
# define BAD_MAP 50
# define MAX(a, b) (a > b ? a : b) //тернарный оператор, находим макс.
# define MOD(a) ((a < 0) ? -a : a)

typedef struct	l_mlx
{
	void		*mlxPtr;
	void		*winPtr;
	void		*imgPtr;
	char		*imgData;
	int			bpp;
	int			size_l;
	int			endian;
	int			**map;
	int			x;
	int			y;
	int			zoom;
	int			color;
	int			shift_x;
	int			shift_y;
	double		angle;
	int			izo;
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
s_fdf 	*init_map(char **argv, s_fdf *fdf, s_mlx *map);
void	fdf_affairs(s_mlx *mlx);
void	draw(s_mlx *data);

#endif
