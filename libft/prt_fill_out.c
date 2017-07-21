/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_fill_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 22:44:58 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 22:46:23 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prt_fill_out(t_out *out, const char *format, int len)
{
	if (len > 0 && format)
	{
		if (out->len + len <= BUFFSIZE)
			ft_memcpy(out->out + out->len, format, len);
		else
		{
			if (out->stocked)
			{
				if (!(out->out = prt_realloc(out->out, 1 + len + out->len,
								out->len)))
					exit(EXIT_FAILURE);
			}
			else
			{
				if (!(out->out = (char *)malloc(sizeof(char)
								* (out->len + len + 1))))
					exit(EXIT_FAILURE);
				out->out = ft_memcpy(out->out, out->out1, out->len);
			}
			ft_memcpy(out->out + out->len, format, len);
			out->stocked = 1;
		}
	}
	out->len += len;
}
