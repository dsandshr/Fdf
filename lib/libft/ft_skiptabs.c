/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skiptabs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:53:35 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:28:21 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_skiptabs(const char *str)
{
	if (str && *str)
	{
		while (str && TABS(*str))
			++str;
	}
	return ((char *)str);
}
