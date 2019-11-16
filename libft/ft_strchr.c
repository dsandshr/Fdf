/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:00:09 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:25:21 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*p_str;

	p_str = NULL;
	while (*s && (*s != c))
		s++;
	if (*s == c)
		p_str = s;
	return ((char *)p_str);
}
