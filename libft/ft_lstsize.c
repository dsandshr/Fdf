/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 01:30:02 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:32:35 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstsize(t_list *beg)
{
	size_t	ret_size;

	ret_size = 0;
	if (beg)
	{
		while (beg)
		{
			ret_size++;
			beg = beg->next;
		}
	}
	return (ret_size);
}
