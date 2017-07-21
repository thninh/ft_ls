/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 22:20:40 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 22:21:27 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			prt_percent(t_out *output, t_out *tmp, t_arg *ele)
{
	prt_fill_out(tmp, "%", 1);
	if (ele->pad != 0)
		prt_pad(tmp, 0, ele);
	prt_fill_out(output, tmp->out, tmp->len);
	prt_free_out(tmp);
}
