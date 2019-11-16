/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:11:06 by dsandshr          #+#    #+#             */
/*   Updated: 2019/11/16 02:37:19 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static s_fdf	*fdf_init(s_fdf *fdf)
{
	if (!(fdf = (s_fdf *)malloc(sizeof(s_fdf))))
		exit (-1);
	fdf->x = 0;
	fdf->y = 0;
	fdf->z = 0;
	fdf->next = NULL;
	return (fdf);
}

int main(int argc, char **argv)
{
	s_fdf	*fdf;
	
	fdf = NULL;
	if (argc != 2)
		error(argc);
	fdf = fdf_init(fdf);
	fdf = init_map(argv, fdf);
	return (0);
}