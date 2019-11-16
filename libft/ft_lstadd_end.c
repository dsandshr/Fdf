/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 10:46:34 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:33:50 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list **begin_list, t_list *elem)
{
	t_list *res;

	if (begin_list)
	{
		if (!(*begin_list))
			(*begin_list) = elem;
		else
		{
			res = (*begin_list);
			while (res->next)
				res = res->next;
			res->next = elem;
		}
	}
}
