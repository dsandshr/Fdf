/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lineslen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:16:53 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:33:58 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lineslen(char *const lines[])
{
	size_t	ret_len;

	ret_len = 0;
	if (lines && *lines)
	{
		while (*lines)
		{
			++ret_len;
			++lines;
		}
	}
	return (ret_len);
}
