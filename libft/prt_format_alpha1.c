/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_format_alpha1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:37:26 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 21:37:54 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		prt_format_alpha1(va_list ap, t_arg *ele)
{
	if (ele->type == 'c')
	{
		ele->data.c = (char)va_arg(ap, int);
		ele->format = 'c';
	}
	else if (ele->type == 'C')
		ele->data.lc = (wchar_t)va_arg(ap, wint_t);
	else if (ele->type == 's' || ele->type == 'S' || ele->type == 'p')
	{
		ele->format = 'p';
		if (ele->type == 's')
			ele->data.p = va_arg(ap, char *);
		else if (ele->type == 'S')
			ele->data.p = va_arg(ap, wchar_t *);
		else if (ele->type == 'p')
			ele->data.p = va_arg(ap, void *);
	}
}
