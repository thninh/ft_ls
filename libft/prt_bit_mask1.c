/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_bit_mask1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 23:02:42 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 23:03:20 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		prt_bit_mask1(int decalage, wchar_t c, char *ch, size_t size)
{
	if (size == 5)
		*ch = 0x80 + ((c & 0xf000000) >> decalage);
	if (size == 4)
		*ch = 0x80 + ((c & 0xfc0000) >> decalage);
	if (size == 3)
		*ch = 0x80 + ((c & 0x3f000) >> decalage);
	if (size == 2)
		*ch = 0x80 + ((c & 0x0fc0) >> decalage);
	if (size == 1)
		*ch = 0x80 + (c & 0x3f);
}
