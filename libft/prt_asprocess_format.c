/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_asprocess_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:05:02 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 21:10:38 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		prt_asprocess_format(t_out *output, t_arg *ele)
{
	t_out		tmp;

	prt_init_out(&tmp);
	if (ele->type == 'f' || ele->type == 'F')
		prt_float(output, &tmp, ele);
	else if (ele->format == 'c' || ele->type == 's')
		prt_asalpha(output, &tmp, ele);
	else if (ele->type == 'C' || ele->type == 'S')
		prt_aswide(output, &tmp, ele);
	else if (ele->type == 'p')
		prt_point((unsigned long int)(ele->data.p), output, &tmp, ele);
	else if (ele->type == '%')
		prt_percent(output, &tmp, ele);
	else if (ft_strchr("hydDuULwK", ele->format))
		prt_num(output, &tmp, ele);
	else
		prt_nonspec(output, &tmp, ele);
}
