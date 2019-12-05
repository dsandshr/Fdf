/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:57:24 by dsandshr          #+#    #+#             */
/*   Updated: 2019/12/05 17:46:38 by dmandalo         ###   ########.fr       */
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

# define WIN_Y 600
# define WIN_X 800
# define WIN_NAME "Dsandshr's & Dmandalo's filler"
# define BAD_MAP 50
# define MAX(a, b) (a > b ? a : b) //тернарный оператор, находим макс.
# define MOD(a) ((a < 0) ? -a : a)

typedef struct	l_fdf
{
	int					x;
	int					y;
	int					z;
	struct l_fdf		*next;
}				s_fdf;

typedef struct l_map
{
	int					**map;
	int					x;
	int					y;
	int					zoom;
	int					color;
	int					shift_x;
	int					shift_y;
	double				angle;
}				s_map;

typedef struct	l_mlx
{
	void		*mlxPtr;
	void		*winPtr;
	void		*imgPtr;
	char		*imgData;
	int			bpp;
	int			size_l;
	int			endian;
	s_map		*map;
}				s_mlx;


/*
** func
*/

void	error(int argc);
s_fdf 	*init_map(char **argv, s_fdf *fdf, s_map *map);
void	fdf_affairs(s_mlx *mlx, s_map *map);
void	draw(s_mlx *data);

#endif
