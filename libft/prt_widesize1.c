/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_widesize1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 23:01:26 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 23:44:43 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prt_widesize1(wchar_t c)
{
	wchar_t		lu;

	lu = 0;
	if (c < 0x80)
		return (1);
	if (c < 0x800)
		return (2);
	if (c < 0x10000)
		return (3);
	if (c <= 0x1FFFFF)
		return (4);
	if (c <= 0x3FFFFFF)
		return (5);
	if (c <= 0x7FFFFFFF)
		return (6);
	return (0);
}
