/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skiptabs_sym.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:00:11 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:28:28 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_skiptabs_sym(const char *str, char sym)
{
	if (str && *str)
	{
		while (str && *str && (TABS(*str) || *str == sym))
			++str;
	}
	return ((char *)str);
}
