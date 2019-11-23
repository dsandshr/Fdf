/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 01:22:58 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:09:40 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_arrfind(int *arr, int data, size_t size)
{
	size_t i;

	if (size > 0 && arr)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == data)
				return (i);
			i++;
		}
	}
	return (-1);
}
