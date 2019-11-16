/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitscpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 08:52:06 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:09:51 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned	ft_bitscpy(unsigned value, unsigned inval, unsigned num)
{
	return (value | (inval << num));
}
