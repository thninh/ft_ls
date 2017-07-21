/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_itoa_base1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:51:48 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 22:19:57 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			prt_itoa_base1(unsigned long int nb, t_arg *ele, t_out *tmp)
{
	char			num[100];
	int				i;
	char			*base_str;
	size_t			base;

	base_str = prt_init_base(ele->type, &base);
	i = 98;
	num[99] = '\0';
	while (nb >= base)
	{
		num[i] = base_str[nb % base];
		nb = nb / base;
		--i;
	}
	num[i] = base_str[nb];
	ele->len = 98 - i + 1;
	prt_fill_out(tmp, num + i, ele->len);
}
