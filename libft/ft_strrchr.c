/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:04:49 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:23:33 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *p_str;

	p_str = NULL;
	while (*s)
	{
		if (*s == c)
			p_str = (char *)s;
		s++;
	}
	if (*s == c)
		p_str = (char *)s;
	return (p_str);
}
