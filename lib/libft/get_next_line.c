/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:53:48 by mikim             #+#    #+#             */
/*   Updated: 2019/12/06 20:21:13 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		find_newline(char *s)
{
	char *s0;

	if (s)
	{
		s0 = s;
		while (*s)
		{
			if (*s == '\n')
				return (s - s0 + 1);
			s++;
		}
	}
	return (0);
}

static t_file	*create_list(const int fd)
{
	t_file *list;

	list = (t_file *)malloc(sizeof(t_file));
	if (!list)
		return (NULL);
	list->tail = (char *)malloc(sizeof(char) * BUFF_SIZE);
	if (!list->tail)
	{
		free(list);
		return (NULL);
	}
	*list->tail = '\0';
	list->file = fd;
	list->next = NULL;
	return (list);
}

static char		*read_file(const int fd, char **s)
{
	char	*clean;
	char	*buf;
	int		n;

	if (!*s)
		return (NULL);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (NULL);
	while (!find_newline(*s))
	{
		if (!(n = read(fd, buf, BUFF_SIZE)))
			break ;
		if (n < 0)
		{
			free(buf);
			ft_strdel(s);
			return (NULL);
		}
		buf[n] = '\0';
		clean = *s;
		*s = ft_strjoin(*s, buf);
		free(clean);
	}
	free(buf);
	return (*s);
}

static int		gnl_list(const int fd, char **line, t_file **list)
{
	char	*s;
	int		n;

	if (!*list)
		if (!(*list = create_list(fd)))
			return (-1);
	if (fd != (*list)->file)
		return (gnl_list(fd, line, &(*list)->next));
	s = *(*list)->tail ? ft_strdup((*list)->tail) : ft_strnew(0);
	read_file(fd, &s);
	if (!s)
		return (-1);
	if (ft_strlen(s))
	{
		n = find_newline(s);
		*line = (n ? ft_strndup(s, n - 1) : ft_strdup(s));
		if (n)
			(*list)->tail = ft_strcpy((*list)->tail, s + n);
		else
			ft_bzero((*list)->tail, BUFF_SIZE);
		ft_strdel(&s);
		return (1);
	}
	ft_strdel(&s);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_file *list = NULL;

	if (BUFF_SIZE < 1 || !line)
		return (-1);
	return (gnl_list(fd, line, &list));
}
