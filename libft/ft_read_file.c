/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:37:36 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:29:35 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*read_file(int fd, size_t size_file_content)
{
	char	*file_content;

	file_content = ft_strnew(sizeof(char) * size_file_content);
	if (!file_content)
		return (NULL);
	read(fd, file_content, size_file_content);
	return (file_content);
}

static size_t	lenfile_content(int fd)
{
	size_t	size_file_content;
	ssize_t	ret_read;
	char	sym;

	size_file_content = 0;
	while ((ret_read = read(fd, &sym, 1)) != -1 && ret_read)
		size_file_content += ret_read;
	lseek(fd, 0, SEEK_SET);
	return (size_file_content);
}

char			*read_file_all(const char *path_name)
{
	size_t	size_file_content;
	char	*file_content;
	int		fd;

	if (path_name && *path_name)
	{
		file_content = NULL;
		fd = open(path_name, O_RDWR);
		if (fd != -1)
		{
			size_file_content = lenfile_content(fd);
			file_content = read_file(fd, size_file_content);
		}
		close(fd);
		return (file_content);
	}
	else
		exit(EXIT_FAILURE);
	return (NULL);
}
