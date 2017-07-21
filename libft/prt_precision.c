/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:31:17 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 21:32:25 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prt_precision(t_arg *ele, int i, const char *str)
{
	if (ft_isdigit(str[i + 1]))
	{
		ele->precision = ft_atoi(str + i + 1);
		if (ele->precision == 0)
			ele->precision = -1;
		while (str[++i] && ft_isdigit(str[i]))
			;
		--i;
	}
	else
		ele->precision = -1;
	return (i);
}
