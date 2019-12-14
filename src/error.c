/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandalo <dmandalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:15:07 by dsandshr          #+#    #+#             */
/*   Updated: 2019/12/14 17:52:59 by dmandalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(int argc)
{
	if (argc == 50)
	{
		ft_printf("%s\n", "map error");
		exit(-1);
	}
	if (argc > 2)
	{
		ft_printf("%s %s\n%s\n", "error input:", "too many arguments.", \
		"use:	./fdf 'map'.fdf");
		exit(-1);
	}
	if (argc < 2)
	{
		ft_printf("%s %s\n%s\n", "error input:", "no arguments.", \
		"use:	./fdf 'map'.fdf");
		exit(-1);
	}
}
