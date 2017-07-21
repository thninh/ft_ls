/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 22:41:23 by thninh            #+#    #+#             */
/*   Updated: 2017/07/18 00:14:24 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			prt_num(t_out *output, t_out *tmp, t_arg *ele)
{
	t_out		flag;

	prt_init_out(&flag);
	prt_flags_num(&flag, ele);
	if (ele->format == 'd')
		prt_itoa1(ele->data.d, ele, tmp);
	else if (ele->format == 'D')
		prt_itoa1(ele->data.ld, ele, tmp);
	else if (ele->format == 'L')
		prt_itoa1(ele->data.ll, ele, tmp);
	else if (ele->format == 'U')
		prt_itoa_base1(ele->data.lu, ele, tmp);
	else if (ele->format == 'u')
		prt_itoa_base1(ele->data.u, ele, tmp);
	else if (ele->format == 'w')
		prt_itoa_base1(ele->data.uc, ele, tmp);
	else if (ele->format == 'K')
		prt_itoa_base1(ele->data.llu, ele, tmp);
	ele->nul = (tmp->len > 0 && *(tmp->out) == '0') ? 1 : 0;
	prt_make_num1(ele, tmp, &flag, output);
	prt_free_out(&flag);
	prt_free_out(tmp);
}
