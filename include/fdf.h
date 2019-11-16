/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:57:24 by dsandshr          #+#    #+#             */
/*   Updated: 2019/11/16 03:10:53 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** Lib
*/

# include "libft.h"

/*
** other defines
*/

# define WIN_X 600
# define WIN_Y 800
# define WIN_NAME "Fdf by Dsandshr"
# define BAD_MAP 50

typedef struct	l_mlx
{
	void		*winPtr;
	void		*initPtr;
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

#endif