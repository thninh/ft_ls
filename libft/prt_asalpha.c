/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_asalpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 20:58:06 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 20:59:43 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			prt_asalpha(t_out *output, t_out *tmp, t_arg *ele)
{
	char		*s;

	s = ele->data.p;
	if (ele->type == 'c')
	{
		if (!(ele->data.c))
			return ;
		prt_fill_out(tmp, &(ele->data.c), 1);
	}
	else if (ele->type == 's' && ele->precision != -1)
	{
		if (s)
		{
			ele->len = ft_strlen(s);
			if (ele->len > ele->precision && ele->precision > 0)
				ele->len = ele->precision;
			prt_fill_out(tmp, s, ele->len);
		}
		else
			return ;
	}
	if (ele->pad != 0)
		prt_pad(tmp, 0, ele);
	prt_fill_out(output, tmp->out, tmp->len);
	prt_free_out(tmp);
}
