/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:57:24 by dsandshr          #+#    #+#             */
/*   Updated: 2019/12/18 19:55:46 by dsandshr         ###   ########.fr       */
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
# define MIN_Z(x) ((x == -1) ? -1 : (x * -0.9))
# define PL_Z(x) ((x == 1) ? 1 : (x * 0.9))
# define WIN_Y 1080
# define WIN_X 1920
# define WIN_NAME "Dsandshr's & Dmandalo's Fdf"
# define BAD_MAP 50
# define MAX(a, b) (a > b ? a : b)
# define MOD(a) ((a < 0) ? -a : a)

typedef	struct			s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	void				*img;
	int					*img_data;
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
	double				coss;
	double				sins;
}						t_mlx;

typedef struct			s_fdf
{
	int					x;
	int					y;
	int					z;
	struct s_fdf		*next;
}						t_fdf;

typedef struct			s_prm
{	float x;
	float y;
	float x1;
	float y1;
}						t_prm;

/*
** func
*/

t_fdf					*init_map(char **argv, t_fdf *fdf, t_mlx *map);
void					error(int argc);
void					fdf_affairs(t_mlx *mlx);
void					draw(t_mlx *data);
void					print_menu(t_mlx *data);
int						deal_key(int key, t_mlx *data);
int						keys(int key, t_mlx *data);
int						deal_key(int key, t_mlx *data);
void					fdf_affairs(t_mlx *mlx);
int						check_in_map(char *str, int fd);

#endif
