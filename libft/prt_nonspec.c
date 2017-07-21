/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_nonspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:45:57 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 21:46:37 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			prt_nonspec(t_out *output, t_out *tmp, t_arg *ele)
{
	char		c[2];

	c[1] = '\0';
	c[0] = ele->type;
	if (ele->pad != 0)
	{
		if (ele->pad > 0)
			ele->pad -= 1;
		else
			ele->pad += 1;
	}
	prt_pad(tmp, c, ele);
	prt_fill_out(output, tmp->out, tmp->len);
	prt_free_out(tmp);
}
