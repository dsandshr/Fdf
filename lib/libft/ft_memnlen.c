/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:46:14 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:31:16 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_memnlen(const void *s, int n, size_t size)
{
	size_t	len;
	size_t	i;

	len = 0;
	if (s)
	{
		i = 0;
		while (i < size)
		{
			if (((unsigned char *)s)[i] == n)
				return (len);
			++len;
			++i;
		}
	}
	return (len);
}
