/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_chr_clr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:45:21 by dsandshr          #+#    #+#             */
/*   Updated: 2019/08/17 14:50:28 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_str_chr_clr(char *s, char c)
{
	char	*p;

	if ((p = ft_strchr(s, c)))
		ft_strcpy(s, p + 1);
	else
		ft_strclr(s);
}
