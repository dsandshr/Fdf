/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_file_name_val.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:59:17 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:30:33 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	push_to_file(char **file_split, const char *path_name)
{
	char	**p_file_split;
	size_t	len_str;
	int		fd;

	p_file_split = file_split;
	fd = open(path_name, O_WRONLY | O_TRUNC);
	lseek(fd, 0, SEEK_SET);
	while (*p_file_split)
	{
		write(fd, *p_file_split, len_str = ft_strlen(*p_file_split));
		if (*(p_file_split + 1))
			write(fd, "\n", 1);
		++p_file_split;
	}
	close(fd);
}

static char	*push_new_value(char *parsed_string, const char *value,
	const size_t len_name)
{
	char	*tmp;
	char	*new_name_value;

	tmp = parsed_string;
	new_name_value = (char *)ft_memalloc(sizeof(char) *
		(len_name + ft_strlen(value) + 1));
	ft_memcpy(new_name_value, parsed_string, len_name);
	ft_strcat(new_name_value, value);
	ft_strdel(&tmp);
	return (new_name_value);
}

static void	swap_value(char **parsed_string,
	const char *name, const char *value)
{
	char	**p_parsed_string;
	size_t	len_name;

	p_parsed_string = parsed_string;
	len_name = ft_strlen(name);
	while (*p_parsed_string)
	{
		if (!ft_memcmp(*p_parsed_string, name, len_name) &&
			(*(*(p_parsed_string) + len_name) == '='))
		{
			*p_parsed_string = push_new_value(*p_parsed_string,
				value, len_name + 1);
			break ;
		}
		++p_parsed_string;
	}
}

char		**parse_read(const char *need_parse,
	const char *name, const char *value)
{
	char	**parsed_string;

	if (need_parse && name && value && *need_parse && *name && *value)
	{
		parsed_string = ft_strsplit(need_parse, SPLIT_SYM);
		swap_value(parsed_string, name, value);
		return (parsed_string);
	}
	else
		exit(EXIT_FAILURE);
	return (NULL);
}

int			change_the_value_by_name_in_file(const char *path_name,
	const char *name, const char *value)
{
	char		*file_content;
	char		**file_split;
	enum e_rw	rw;

	rw = FILE_ERROR;
	if (path_name && name && value && *path_name && *name)
	{
		file_content = read_file_all(path_name);
		file_split = parse_read(file_content, name, value);
		push_to_file(file_split, path_name);
		ft_strdel_split(file_split);
		free(file_split);
		ft_strdel(&file_content);
		rw = RW_SUCCESS;
	}
	return (rw);
}
