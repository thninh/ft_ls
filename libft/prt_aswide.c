/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_aswide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:01:49 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 23:50:13 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			prt_aswide(t_out *output, t_out *tmp, t_arg *ele)
{
	wchar_t		*ls;
	int			size;
	int			put;

	put = 0;
	size = 0;
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
			return ;
	}
	while (ele->len > 0 && (ele->type == 'C' || (ele->type == 'S'
					&& (ele->precision < 1 || put < ele->precision))))
		prt_print_wide(tmp, ele, &ls, &put);
	(ele->type == 'S' && ele->precision == -1) ? prt_free_out(tmp) : 0;
	(ele->pad != 0) ? prt_pad(tmp, 0, ele) : 0;
	prt_fill_out(output, tmp->out, tmp->len);
}
