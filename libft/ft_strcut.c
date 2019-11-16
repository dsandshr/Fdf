/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:43:13 by dsandshr          #+#    #+#             */
/*   Updated: 2019/08/17 14:50:09 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcut(char *s, char c)
{
	char	*p;
	char	*fresh;

	if ((p = ft_strchr(s, c)))
		fresh = ft_strndup(s, p - s);
	else
		fresh = ft_strdup(s);
	return (fresh);
}
