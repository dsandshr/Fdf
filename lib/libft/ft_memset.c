/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:30:30 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:31:10 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int value, size_t num)
{
	size_t	t_byte_shift;

	t_byte_shift = 0;
	while (t_byte_shift < num)
		*((unsigned char *)buf + t_byte_shift++) = (int)value;
	return (buf);
}
