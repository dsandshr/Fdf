/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:58:05 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:32:05 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *num1;
	const unsigned char *num2;

	num1 = s1;
	num2 = s2;
	while (n--)
	{
		if (*num1 != *num2)
			return (*num1 - *num2);
		num1++;
		num2++;
	}
	return (0);
}
