/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_name_val_in_file.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:59:19 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:10:10 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*pull_value(char *const *file_split, const char *name)
{
	char	*value;
	size_t	shift;

	value = NULL;
	while (*file_split)
	{
		if (!ft_memcmp(*file_split, name, shift = ft_strlen(name)) &&
			(*(*(file_split) + shift) == '='))
		{
			value = ft_skip_before(*file_split, '=');
			value = ft_strdup(value);
			return (value);
		}
		++file_split;
	}
	return (value);
}

static char		*get_value(const char *file_content, const char *name)
{
	char *value;
	char **file_split;

	value = NULL;
	if (file_content && name && *file_content && *name)
	{
		file_split = ft_strsplit(file_content, SPLIT_SYM);
		value = pull_value(file_split, name);
		ft_strdel_split(file_split);
		free(file_split);
	}
	return (value);
}

char			*get_name_value(const char *path_name, const char *name)
{
	char *file_content;
	char *value;

	value = NULL;
	if (path_name && name && *path_name && *name)
	{
		file_content = read_file_all(path_name);
		value = get_value(file_content, name);
		ft_strdel(&file_content);
	}
	return (value);
}
