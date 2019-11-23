/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmoveptr_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:18:58 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:24:11 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmoveptr_end(const char *str, char sym)
{
	if (str && *str && *(str + 1))
	{
		while (str && *str && (*str != sym))
			++str;
		--str;
	}
	return ((char *)str);
}
