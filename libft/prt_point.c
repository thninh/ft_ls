/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:49:57 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 22:20:04 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			prt_point(unsigned long int nb, t_out *output, t_out *tmp,
					t_arg *ele)
{
	t_out		flag;

	prt_init_out(&flag);
	prt_fill_out(&flag, "0x", 2);
	ele->type = 'x';
	prt_itoa_base1(nb, ele, tmp);
	if (*(tmp->out) == '0')
		ele->nul = 1;
	if (ele->precision == -1)
	{
		ele->padchar = ' ';
		if (ele->nul)
			prt_free_out(tmp);
	}
	prt_point_b1(output, ele, tmp, &flag);
	prt_free_out(&flag);
	prt_free_out(tmp);
}
