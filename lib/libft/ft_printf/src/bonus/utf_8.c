/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf_8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 09:35:12 by ksharlen          #+#    #+#             */
/*   Updated: 2019/10/12 16:35:34 by dsandshr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned			set_mask_10(unsigned val, unsigned t_bytes)
{
	--t_bytes;
	while (t_bytes)
	{
		SET_BIT(val, (t_bytes * 8) - 1);
		t_bytes--;
	}
	return (val);
}

static unsigned char	get_6_bits(unsigned unicode)
{
	unsigned char		buf;

	buf = unicode;
	buf <<= 2;
	buf >>= 2;
	return (buf);
}

t_utf					push_unicode(t_utf utf)
{
	int					index;
	unsigned			t_bytes;

	t_bytes = utf.t_bytes;
	index = 0;
	if (t_bytes > 1)
	{
		while (t_bytes)
		{
			utf.utf_sym = ft_bitscpy(utf.utf_sym,\
			get_6_bits(utf.unicode), index);
			utf.unicode >>= 6;
			index += 8;
			--t_bytes;
		}
	}
	else
		utf.utf_sym = utf.unicode;
	return (utf);
}

unsigned				def_num_t_bytes(wchar_t unicode)
{
	unsigned			t_bytes;

	t_bytes = 0;
	if (unicode >= 0 && unicode < 128)
		t_bytes = 1;
	else if (unicode >= 128 && unicode < 2048)
		t_bytes = 2;
	else if (unicode >= 2048 && unicode < 65536)
		t_bytes = 3;
	else if (unicode >= 65536 && unicode < 1114112)
		t_bytes = 4;
	return (t_bytes);
}

unsigned				inst_mask(t_utf utf)
{
	unsigned			mask;

	mask = 0;
	utf.utf_sym = 0;
	if (utf.t_bytes > 1)
	{
		mask = ft_set_bits(mask, utf.t_bytes, utf.t_bytes - 1);
		utf.utf_sym = ft_bitscpy(utf.utf_sym, mask,\
			(utf.t_bytes * 8) - utf.t_bytes);
		utf.utf_sym = set_mask_10(utf.utf_sym, utf.t_bytes);
	}
	return (utf.utf_sym);
}
