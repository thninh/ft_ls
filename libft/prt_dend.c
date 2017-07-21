/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_dend.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:17:28 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 21:18:02 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prt_dend(int fd, t_out *out, t_arg **ele, va_list ap)
{
	int		len;

	len = out->len;
	write(fd, out->out, out->len);
	prt_free_ele(ele);
	prt_free_out(out);
	va_end(ap);
	return (len);
}
