/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 00:25:02 by dsandshr          #+#    #+#             */
/*   Updated: 2019/12/15 17:28:41 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static		t_mlx	*create_map(t_fdf *fdf, t_mlx *map)
{
	if (!(map->map = (int **)malloc(sizeof(int *) * (fdf->y + 1))))
		exit(-1);
	map->map[fdf->y] = NULL;
	while (map->y != fdf->y)
	{
		if (!(map->map[map->y] = (int *)malloc(sizeof(int) * (fdf->x + 1))))
			exit(-1);
		map->map[map->y][fdf->x] = -1;
		map->y++;
	}
	map->y = 0;
	return (map);
}

static		t_fdf	*write_map(t_fdf *fdf, t_mlx *map)
{
	t_fdf	*fdf_ptr;

	fdf_ptr = fdf;
	while (fdf->next != NULL)
		fdf = fdf->next;
	map = create_map(fdf, map);
	fdf = fdf_ptr;
	while (map->map[map->y] != NULL)
	{
		map->x = 0;
		while (map->map[map->y][map->x] != -1)
		{
			map->map[map->y][map->x] = fdf->z;
			fdf = fdf->next;
			map->x++;
		}
		map->y++;
	}
	return (fdf_ptr);
}

static		t_fdf	*next_step(t_fdf *fdf)
{
	while (fdf->next != NULL)
		fdf = fdf->next;
	if (!(fdf->next = (t_fdf *)malloc(sizeof(t_fdf))))
		exit(-1);
	fdf->next->x = fdf->x;
	fdf->next->y = fdf->y;
	fdf->next->z = fdf->z;
	fdf = fdf->next;
	fdf->next = NULL;
	return (fdf);
}

t_fdf				*init_map(char **argv, t_fdf *fdf, t_mlx *map)
{
	int		fd;
	char	*line;
	char	**buf;
	t_fdf	*fdf_ptr;

	fdf_ptr = fdf;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		error(BAD_MAP);
	while (get_next_line(fd, &line) == 1)
	{
		buf = ft_strsplit(line, ' ');
		fdf->x = 0;
		while (buf[fdf->x])
		{
			fdf->z = ft_atoi(buf[fdf->x]);
			fdf = next_step(fdf);
			fdf->x++;
		}
		fdf->y++;
		ft_strdel_split(buf);
		buf = NULL;
		ft_strdel(&line);
	}
	close(fd);
	return (write_map(fdf_ptr, map));
}
