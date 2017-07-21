/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_flags_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:33:18 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 21:33:56 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prt_flags_num(t_out *output, t_arg *ele)
{
	if (ele->hash && (ele->type == 'o' || ele->type == 'O'))
		prt_fill_out(output, "0", 1);
	else if (ele->hash && ((ele->format == 'u' && ele->data.u > 0)
				|| (ele->format == 'U' && ele->data.lu > 0)
				|| (ele->format == 'K' && ele->data.llu > 0)))
	{
		prt_fill_out(output, "0", 1);
		prt_fill_out(output, &ele->type, 1);
		ele->sharp = 1;
	}
	else if (((ele->type == 'i' || ele->type == 'd') && ele->data.d >= 0)
				|| (ele->type == 'D' && ele->data.ld >= 0)
				|| (ele->type == 'f' && ele->data.f >= 0.0))
	{
		if (ele->plus)
			prt_fill_out(output, "+", 1);
		else if (ele->space)
			prt_fill_out(output, " ", 1);
	}
}
