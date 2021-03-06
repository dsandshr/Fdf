/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:57:24 by dsandshr          #+#    #+#             */
/*   Updated: 2019/12/19 21:18:06 by dmandalo         ###   ########.fr       */
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
	float z;
	float z1;
}						t_prm;

/*
** func
*/

t_fdf					*init_map(char **argv, t_fdf *fdf, t_mlx *map);
void					error(int argc);
void					fdf_affairs(t_mlx *mlx);
void					draw(t_mlx *data);
void					print_menu(t_mlx *data);
void					print_two_menu(t_mlx *data);
void					isometric(float *x, float *y, int z, t_mlx *data);
void					rot_y(float *x, float *y, int z, t_mlx *data);
void					plus_z(t_mlx *data, int x, int y);
void					rot_x(float *x, float *y, int z, t_mlx *data);
void					minus_z(t_mlx *data, int x, int y);
int						deal_key(int key, t_mlx *data);
int						many_keys(int key, t_mlx *data);
int						keys(int key, t_mlx *data);
int						check_in_map(char *str, int fd);
void					mlx_free(t_mlx **mlx);

#endif
