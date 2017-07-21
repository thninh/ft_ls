/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_init_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:42:51 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 21:43:13 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prt_init_out(t_out *out)
{
	out->out = out->out1;
	out->stocked = 0;
	ft_bzero(out->out1, BUFFSIZE);
	out->len = 0;
}
