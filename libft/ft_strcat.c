/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:59:51 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:34:58 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *dest, const char *src)
{
	int		len;
	char	*p_str;

	p_str = dest;
	len = ft_strlen(dest);
	dest = dest + len;
	ft_strcpy(dest, src);
	return (p_str);
}
