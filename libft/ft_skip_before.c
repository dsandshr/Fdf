/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_before.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:32:45 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:28:55 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_skip_before(const char *str, char sym)
{
	if (str && *str && sym > 0)
	{
		while (str && *str && (*str != sym))
			++str;
		if (str && *str && (*str == sym))
			++str;
	}
	return ((char *)str);
}
