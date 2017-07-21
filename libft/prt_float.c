/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 22:38:38 by thninh            #+#    #+#             */
/*   Updated: 2017/07/18 00:10:29 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			prt_float(t_out *output, t_out *tmp, t_arg *ele)
{
	t_out		flag;

	prt_init_out(&flag);
	prt_flags_num(&flag, ele);
	if (ele->data.f != ele->data.f)
		prt_fill_out(tmp, "NaN", 3);
	else
	{
		if (ele->precision != -1 && ele->precision != 0)
			ele->data.f += ((ele->data.f < 0) ? -1 : 1)
				* prt_pow(10.0, -ele->precision) * 0.5;
		else if (!ele->hash && ele->precision != -1)
			ele->data.f += ((ele->data.f < 0) ? -1 : 1) * prt_pow(10.0, -6)
				* 0.5;
		else
			ele->data.f += ((ele->data.f < 0) ? -1 : 1) * 0.5;
		prt_dtoa(ele->data.f, (ele->precision > 0
					|| ele->precision == -1) ? ele->precision : 6, ele, tmp);
		if (ele->hash && ele->precision == -1)
			prt_fill_out(tmp, ".", 1);
	}
	prt_make_num1(ele, tmp, &flag, output);
	prt_free_out(&flag);
	prt_free_out(tmp);
}
