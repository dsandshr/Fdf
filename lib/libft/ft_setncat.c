/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:11:43 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:29:07 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_setncat(char *str, int sym, size_t size)
{
	register size_t	i;

	i = 0;
	while (*str)
		++str;
	while (i < size)
	{
		str[i] = sym;
		++i;
	}
	return (str);
}
