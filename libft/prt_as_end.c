/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_as_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:02:56 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 21:16:11 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prt_as_end(char **strp, t_out *out, t_arg **ele, va_list ap)
{
	int			len;

	len = out->len;
	if (out->len > 0 && !(*strp = ft_memalloc(out->len + 1)))
		exit(EXIT_FAILURE);
	*strp = ft_memcpy(*strp, out->out, out->len);
	prt_free_ele(ele);
	prt_free_out(out);
	va_end(ap);
	return (len);
}
