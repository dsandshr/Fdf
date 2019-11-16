/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 01:46:18 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:23:44 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strnlen(const char *str, int n)
{
	size_t len;

	len = 0;
	if (str)
	{
		while (*str && *str++ != n)
			len++;
	}
	return (len);
}
