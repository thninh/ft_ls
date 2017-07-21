/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_point_b1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:47:35 by thninh            #+#    #+#             */
/*   Updated: 2017/07/21 12:53:28 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		prt_point_b1(t_out *output, t_arg *ele, t_out *tmp, t_out *flag)
{
	t_out		prec;

	prt_init_out(&prec);
	if (ele->precision != -1)
	{
		ele->precision -= ele->len;
		while (--ele->precision >= 0)
			prt_fill_out(&prec, "0", 1);
		prt_join_before(tmp, prec.out, prec.len);
	}
	if (ele->pad != 0)
	{
		ele->pad += (ele->pad > 0) ? -(flag->len) : flag->len;
		prt_pad(tmp, flag->out, ele);
	}
	else
		prt_fill_out(output, flag->out, flag->len);
	prt_fill_out(output, tmp->out, tmp->len);
	prt_free_out(&prec);
}
