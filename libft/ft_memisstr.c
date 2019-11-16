/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memisstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:36:55 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:31:36 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memisstr(const char *str, const char *chek_format, size_t size)
{
	if (size <= ft_strlen(str) && size > 0)
	{
		while (*str && size--)
		{
			if (ft_ischar(chek_format, *str))
				return (1);
			str++;
		}
	}
	return (0);
}
