/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strskipinv_sym.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:25:38 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:23:21 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strskipinv_sym(const char *str, char sym)
{
	if (str && *str)
	{
		while (*str && (*str < 33 || *str == sym))
			++str;
		return ((char *)str);
	}
	return (NULL);
}
