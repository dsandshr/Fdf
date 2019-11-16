/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 12:00:00 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:34:20 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isstr(const char *str, const char *check_symbols)
{
	while (*str)
	{
		if (ft_ischar(check_symbols, *str))
			return (1);
		str++;
	}
	return (0);
}
