/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:57:24 by dsandshr          #+#    #+#             */
/*   Updated: 2019/12/14 18:35:47 by dmandalo         ###   ########.fr       */
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
# define MIN_Z(x) ((x == -1) ? -1 : (x / 2))
# define PL_Z(x) ((x == 1) ? 1 : (x / 2))
# define WIN_Y 1080
# define WIN_X 1920
# define WIN_NAME "Dsandshr's & Dmandalo's Fdf"
# define BAD_MAP 50
# define MAX(a, b) (a > b ? a : b)
# define MOD(a) ((a < 0) ? -a : a)

typedef	struct		l_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*imgPtr;
	void				*img;
	int					*imgData;
	int					bpp;
	int					size_l;
	int					endian;
	int					**map;
	int					x;
	int					y;
	int					zoom;
	int					clr;
	int					clr1;
	int					clr2;
	int					shift_x;
	int					shift_y;
	int					iso;
	double				angle;
}					s_mlx;

typedef struct		l_fdf
{
	int					x;
	int					y;
	int					z;
	struct l_fdf		*next;
}					s_fdf;
	
typedef struct		l_prm	 
{
	float x1;
	float y1;
}					s_prm;


/*
** func
*/

void				error(int argc);
s_fdf				*init_map(char **argv, s_fdf *fdf, s_mlx *map);
void				fdf_affairs(s_mlx *mlx);
void				draw(s_mlx *data);
void				print_menu(s_mlx *data);

#endif
