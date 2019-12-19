/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:15:07 by dsandshr          #+#    #+#             */
/*   Updated: 2019/12/19 17:41:41 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_fdf	check_inn(char **buf, t_fdf fdf)
{
	while (buf[fdf.x])
	{
		if ((buf[fdf.x][0] >= '0' && buf[fdf.x][0] <= '9') ||
		((buf[fdf.x][0] == '-' || buf[fdf.x][0] == '+') &&
		(buf[fdf.x][1] >= '0' && buf[fdf.x][1] <= '9')))
			fdf.x++;
		else
			error(BAD_MAP);
	}
	if (fdf.y == 0 || fdf.z == fdf.x)
		fdf.z = fdf.x;
	if (fdf.y != 0 && fdf.z != fdf.x)
		error(BAD_MAP);
	return (fdf);
}

int				check_in_map(char *str, int fd)
{
	char	*line;
	char	**buf;
	t_fdf	fdf;

	if ((fd = open(str, O_RDONLY)) == -1)
		error(BAD_MAP);
	fdf.y = 0;
	while (get_next_line(fd, &line) == 1)
	{
		buf = ft_strsplit(line, ' ');
		fdf.x = 0;
		fdf = check_inn(buf, fdf);
		fdf.y++;
		ft_strdel_split(buf);
		free(buf);
		free(line);
	}
	close(fd);
	return (1);
}

void		error(int argc)
{
	if (argc == 50)
	{
		ft_printf("%s\n", "map error");
		exit(-1);
	}
	if (argc > 2)
	{
		ft_printf("%s %s\n%s\n", "error input:", "too many arguments.", \
		"use:	./fdf 'map'.fdf");
		exit(-1);
	}
	if (argc < 2)
	{
		ft_printf("%s %s\n%s\n", "error input:", "no arguments.", \
		"use:	./fdf 'map'.fdf");
		exit(-1);
	}
}
