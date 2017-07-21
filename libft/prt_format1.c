/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_format1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:38:39 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 21:39:17 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		prt_format1(t_arg *ele, va_list ap)
{
	if (ele->type == 'd' || ele->type == 'i')
	{
		ele->data.d = va_arg(ap, int);
		if (ele->format == 'h')
			ele->data.d = (short)ele->data.d;
		ele->format = 'd';
	}
	else if (ele->type == 'z')
	{
		ele->data.d = (signed char)va_arg(ap, int);
		ele->format = 'd';
	}
	else if (ele->type == 'D')
	{
		ele->data.ld = va_arg(ap, long int);
		ele->format = 'D';
	}
	else if (ele->type == 'L')
	{
		ele->data.ll = (long long int)va_arg(ap, long int);
		ele->format = 'L';
	}
	prt_format_u1(ap, ele);
	prt_format_alpha1(ap, ele);
}
