/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_prec_num1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 22:34:36 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 22:35:37 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		prt_prec_num1(t_arg *ele, t_out *tmp, t_out *flag)
{
	char		*ptr;
	int			len;

	ele->precision -= ele->len;
	if (flag->len > 0 && !ele->sharp && !ele->space && !ele->plus)
		ele->precision -= flag->len;
	if (tmp->len > 0 && *(tmp->out) == '-')
	{
		len = tmp->len - 1;
		ptr = ft_strndup(tmp->out + 1, len);
		ele->precision += 1;
		prt_free_out(tmp);
		prt_fill_out(tmp, "-", 1);
		while (ele->precision-- > 0)
			prt_fill_out(tmp, "0", 1);
		prt_fill_out(tmp, ptr, len);
		free(ptr);
	}
	while (ele->precision-- > 0)
		prt_join_before(tmp, "0", 1);
}
