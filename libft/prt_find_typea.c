/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_find_typea.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 22:23:08 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 22:23:41 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prt_find_typea(t_arg *ele, const char *str, int i)
{
	if (str[i] == 'h')
	{
		if (!ft_strchr("jzlL", ele->modifier))
		{
			ele->modifier = str[i];
			if (str[i - 1] && str[i - 1] == 'h')
				ele->modifier = 'H';
		}
	}
	else if (ft_strchr("lzj", str[i]))
	{
		ele->modifier = str[i];
		if (str[i] == 'l' && ((str[i - 1] && str[i - 1] == 'l')))
			ele->modifier = 'L';
	}
	else if (str[i] == '#')
		ele->hash = 1;
	else if (str[i] == '+')
		ele->plus = 1;
	else if (str[i] == '-')
		ele->padleft = 1;
	else if (str[i] == '0')
		if (i == 0 || ft_isdigit(str[i - 1]) == 0)
			ele->zero = 1;
}
