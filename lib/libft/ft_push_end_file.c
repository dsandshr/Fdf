/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_end_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:29:13 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:30:46 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	open_file(const char *path_name)
{
	int		fd;
	mode_t	st_mode;

	st_mode = 0;
	st_mode = S_IRWXU | S_IRGRP | S_IROTH;
	fd = open(path_name, O_CREAT | O_WRONLY | O_APPEND, st_mode);
	return (fd);
}

static int	push_end_file_internal(const int fd, const char *date)
{
	int ret_write;

	ret_write = write(fd, date, ft_strlen(date));
	return (ret_write);
}

int			ft_push_end_file(const char *path_name, const char *data)
{
	int			fd;
	enum e_rw	rw;

	rw = FILE_ERROR;
	if (path_name && *path_name && data && *data)
	{
		fd = open_file(path_name);
		if (fd != -1)
		{
			rw = RW_SUCCESS;
			if (push_end_file_internal(fd, data) == -1)
				rw = FILE_ERROR;
			close(fd);
		}
	}
	return (rw);
}
