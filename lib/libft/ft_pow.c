/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 10:18:52 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:30:57 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_pow(int number, int level)
{
	ssize_t	res;

	res = 1;
	while (level)
	{
		if (level & 1)
			res *= number;
		number *= number;
		level >>= 1;
	}
	return (res);
}
