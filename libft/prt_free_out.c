/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_free_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:43:43 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 21:44:08 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prt_free_out(t_out *out)
{
	if (out->stocked)
	{
		free(out->out);
		out->out = out->out1;
	}
	out->stocked = 0;
	out->len = 0;
}
