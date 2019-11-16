/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 10:10:52 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:33:32 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *res;
	t_list *tmp;

	if (alst && del)
	{
		if ((*alst))
		{
			res = (*alst);
			while (res)
			{
				tmp = res->next;
				(*del)(res->content, res->content_size);
				free(res);
				res = tmp;
			}
			(*alst) = NULL;
		}
	}
}
