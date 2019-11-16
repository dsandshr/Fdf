/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_word_sym.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:40:57 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:28:48 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_skip_word_sym(const char *str, char sym)
{
	if (str && *str)
	{
		while (str && ((*str > 32) || *str == sym))
			++str;
	}
	return ((char *)str);
}
