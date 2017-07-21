/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 22:54:07 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 22:55:19 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		prt_init_arg(t_arg *new_ele)
{
	new_ele->nul = 0;
	new_ele->precision = 0;
	new_ele->padleft = 0;
	new_ele->pad = 0;
	new_ele->len = 0;
	new_ele->padchar = ' ';
	new_ele->hash = 0;
	new_ele->plus = 0;
	new_ele->space = 0;
	new_ele->wild = 0;
	new_ele->zero = 0;
	new_ele->unsign = 0;
	new_ele->sharp = 0;
	new_ele->modifier = 0;
}

t_arg			*prt_arg(void)
{
	t_arg		*new_ele;

	if (!(new_ele = malloc(sizeof(t_arg))))
		exit(EXIT_FAILURE);
	prt_init_arg(new_ele);
	return (new_ele);
}
