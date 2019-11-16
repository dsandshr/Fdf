/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 00:25:02 by dsandshr          #+#    #+#             */
/*   Updated: 2019/11/16 03:09:18 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static s_fdf *next_step(s_fdf *fdf, int x, int y, int z)
{
	while (fdf->next != NULL)
		fdf = fdf->next;
	if (!(fdf->next = (s_fdf *)malloc(sizeof(s_fdf))))
		exit (-1);
	fdf->x = x;
	fdf->y = y;
	fdf->z = z;
	fdf = fdf->next;
	fdf->next = NULL;
	return (fdf);
}

s_fdf *init_map(char **argv, s_fdf *fdf)
{
	int y;
	int x;
	int z;
	int fd;
	char *line;
	char *buf;
	s_fdf *fdf_ptr;
	
	fdf_ptr = fdf;
	y = fdf->y;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		buf = line;
		x = 0;
		while (*buf != '\0')
		{
			if (!(z = ft_atoi(buf)))
				error(50);
			fdf = next_step(fdf, x, y, z);
			while (*buf != ' ' || *buf != '\0')
				buf++;
			x++;
		}
		ft_strdel(&line);
		y++;
	}
	return (fdf_ptr);
}
	