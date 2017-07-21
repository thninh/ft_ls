/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_make_num1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 22:36:52 by thninh            #+#    #+#             */
/*   Updated: 2017/07/21 12:54:22 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		prt_make_num1(t_arg *ele, t_out *tmp, t_out *flag, t_out *out)
{
	if (ele->precision != -1)
		prt_prec_num1(ele, tmp, flag);
	else if (flag->len == 0 || (ele->type != 'o' && ele->type != 'O'))
	{
		ele->padchar = ' ';
		if (ele->nul)
			prt_free_out(tmp);
	}
	ele->pad += ((ele->pad > 0) ? -flag->len : flag->len);
	if (ele->nul && (!ele->plus && !ele->space && flag->len > 0))
		prt_pad(tmp, 0, ele);
	else
		prt_pad(tmp, flag->out, ele);
	prt_fill_out(out, tmp->out, tmp->len);
}
