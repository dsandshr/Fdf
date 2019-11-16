/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:23:15 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:09:56 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t t_byte_shift;

	t_byte_shift = 0;
	while (t_byte_shift < n)
	{
		*((unsigned char *)s + t_byte_shift) = 0;
		t_byte_shift++;
	}
}
