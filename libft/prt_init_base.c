/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_init_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:44:48 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 21:45:07 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*prt_init_base(char type, size_t *base)
{
	char	*base_str;

	*base = 16;
	if (type != 'x')
		base_str = "0123456789ABCDEF";
	else
		base_str = "0123456789abcdef";
	if (type == 'o' || type == 'O')
		*base = 8;
	else if (type == 'b')
		*base = 2;
	else if (type != 'x' && type != 'X')
		*base = 10;
	return (base_str);
}
