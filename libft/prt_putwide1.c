/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_putwide1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 23:04:26 by thninh            #+#    #+#             */
/*   Updated: 2017/07/18 00:21:15 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		prt_putwide1(t_out *output, wchar_t c, size_t size, int decalage)
{
	char		ch;

	ch = 0;
	if (size == 6)
		ch = 0xfc + ((c & 0x40000000) >> decalage);
	else if (size == 5)
		ch = 0xf8 + ((c & 0x3000000) >> decalage);
	else if (size == 4)
		ch = 0xf0 + ((c & 0x1c0000) >> decalage);
	else if (size == 3)
		ch = 0xe0 + ((c & 0xf000) >> decalage);
	else if (size == 2)
		ch = 0xc0 + ((c & 0x0fc0) >> decalage);
	else if (size == 1)
		ch = c;
	size--;
	decalage -= 6;
	prt_fill_out(output, &ch, 1);
	while (size >= 1)
	{
		prt_bit_mask1(decalage, c, &ch, size);
		prt_fill_out(output, &ch, 1);
		size--;
		decalage -= 6;
	}
}
