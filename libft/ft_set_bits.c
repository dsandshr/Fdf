/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_bits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 08:48:55 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:29:18 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned	ft_set_bits(unsigned val, unsigned bits, unsigned num)
{
	while (bits--)
		val = ft_set_bit(val, num--);
	return (val);
}
