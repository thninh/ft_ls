/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_wild.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:29:54 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 21:30:16 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prt_wild(const char *str, int i, t_arg *ele, va_list ap)
{
	if (i == 0 || str[i - 1] != '.')
		ele->pad = va_arg(ap, int);
	else
	{
		ele->precision = va_arg(ap, int);
		if (ele->precision == 0)
			ele->precision = -1;
	}
	ele->wild = 1;
}
