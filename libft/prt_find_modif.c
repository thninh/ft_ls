/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_find_modif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 22:29:36 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 22:30:12 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg		*prt_find_modif(const char **str, va_list ap)
{
	t_arg	*ele;
	int		i;

	*str += 1;
	ele = prt_arg();
	i = prt_find_typeb(*str, ele, ap);
	*str = *str + i;
	if (ele->type == '\0')
	{
		free(ele);
		return (NULL);
	}
	if (ft_strchr("uoxXb", ele->type))
		ele->unsign = 1;
	ele->format = ele->type;
	prt_modifier(ele);
	if (ele->zero && (((ft_strchr("scSC%Z", ele->type) || ele->precision == 0)
					&& !ele->padleft) || (ele->precision != 0 && ele->wild)))
		ele->padchar = '0';
	return (ele);
}
