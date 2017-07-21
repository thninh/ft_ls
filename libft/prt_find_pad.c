/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_find_pad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 22:49:51 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 22:50:06 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				prt_find_pad(t_arg *ele, int i, const char *str)
{
	ele->pad = ft_atoi(str + i);
	while (str[i] && ft_isdigit(str[i]))
		++i;
	--i;
	return (i);
}
