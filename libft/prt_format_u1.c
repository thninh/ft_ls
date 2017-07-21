/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_format_u1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:35:55 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 21:36:39 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		prt_format_u1(va_list ap, t_arg *ele)
{
	if (ele->type == 'O' || ele->type == 'U')
	{
		ele->data.lu = va_arg(ap, unsigned long int);
		ele->format = 'U';
	}
	else if (ele->type == 'f' || ele->type == 'F')
		ele->data.f = va_arg(ap, double);
	else if (ft_strchr("uoxXb", ele->type))
	{
		if (ele->format == 'U')
			ele->data.lu = va_arg(ap, unsigned long int);
		else if (ele->format == 'K')
			ele->data.llu = va_arg(ap, unsigned long long int);
		else if (ele->format == 'w')
			ele->data.uc = (unsigned char)va_arg(ap, int);
		else
		{
			ele->data.u = va_arg(ap, unsigned int);
			if (ele->format == 'y')
				ele->data.u = (unsigned short)ele->data.u;
			ele->format = 'u';
		}
	}
}
