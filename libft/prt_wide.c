/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_wide.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 23:06:46 by thninh            #+#    #+#             */
/*   Updated: 2017/07/18 00:23:02 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			prt_wide(t_out *output, t_out *tmp, t_arg *ele)
{
	wchar_t		*ls;
	int			put;

	put = 0;
	if (ele->type == 'C')
	{
		ls = &(ele->data.lc);
		ele->len = 1;
	}
	else
	{
		ls = (wchar_t *)(ele->data.p);
		if (ls)
			ele->len = prt_wide_slen(ls);
		else
			prt_fill_out(tmp, "(null)", 6);
	}
	while (ele->len > 0 && (ele->type == 'C' || (ele->type == 'S'
					&& (ele->precision < 1 || put < ele->precision))))
		prt_print_wide(tmp, ele, &ls, &put);
	if (ele->type == 'S' && ele->precision == -1)
		prt_free_out(tmp);
	if (ele->pad != 0)
		prt_pad(tmp, 0, ele);
	prt_fill_out(output, tmp->out, tmp->len);
}
