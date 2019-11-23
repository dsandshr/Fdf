/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_skip_space.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:39:51 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:23:19 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_num_str(const char *p_str, char sym)
{
	int		ret;

	ret = 0;
	if (p_str && *p_str)
	{
		while (p_str && *p_str)
		{
			p_str = ft_skiptabs(p_str);
			if (p_str && *p_str && (*p_str != sym))
				++ret;
			p_str = ft_skip_before(p_str, sym);
		}
	}
	return (ret);
}

static int		ft_num_space_end(const char *str, char sym)
{
	size_t		spaces;
	const char	*p_str;

	spaces = 0;
	if (str && *str)
	{
		p_str = ft_strmoveptr_end(str, sym);
		while (p_str && *p_str && TABS(*p_str))
		{
			spaces++;
			p_str--;
		}
	}
	return (spaces);
}

static char		*ft_alloc_before(char **str, char sym)
{
	size_t		len;
	size_t		end_spaces;
	char		*ret_str;

	ret_str = NULL;
	if (*str && **str)
	{
		len = ft_strnlen(*str, sym);
		end_spaces = ft_num_space_end(*str, sym);
		len -= end_spaces;
		ret_str = (char *)ft_strnew(sizeof(char) * len);
		ft_memcpy(ret_str, *str, len);
		(*str) = *(str) + len;
		*str = ft_skipfirst(*str, sym);
	}
	return (ret_str);
}

static void		push_str(char *str, char *str_ret[], size_t size_str, char sym)
{
	size_t		i;

	i = 0;
	while (i < (size_str - 1))
	{
		str = ft_skiptabs_sym(str, sym);
		str_ret[i] = ft_alloc_before(&str, sym);
		++i;
	}
	str_ret[size_str - 1] = NULL;
}

char			**ft_strsplit_skip_space(char *str, char sym)
{
	char	**ret_str;
	int		num_str;

	ret_str = NULL;
	num_str = ft_num_str(str, sym);
	ret_str = (char **)ft_memalloc(sizeof(char *) * (num_str + 1));
	if (!ret_str)
		exit(EXIT_FAILURE);
	push_str(str, ret_str, num_str + 1, sym);
	return (ret_str);
}
