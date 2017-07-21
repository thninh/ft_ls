/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_print_wide.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 23:05:36 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 23:06:18 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			prt_print_wide(t_out *tmp, t_arg *ele, wchar_t **ls, int *put)
{
	int			decalage;
	int			size;

	size = prt_widesize1(**ls);
	*put += size;
	if (ele->type == 'C' || (ele->type == 'S' && (ele->precision < 1
					|| *put <= ele->precision)))
	{
		decalage = 6 * (size - 1);
		prt_putwide1(tmp, **ls, size, decalage);
	}
	ele->len -= 1;
	*ls += 1;
}
