/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:39:54 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 21:40:44 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg			*prt_print(t_out *out, const char **str, va_list ap)
{
	t_arg	*ele;

	ele = NULL;
	while (*str && **str && **str != '%')
	{
		prt_fill_out(out, *str, 1);
		*str += 1;
	}
	if (*str && **str != '\0')
	{
		if (!(ele = prt_find_modif(str, ap)))
			return (NULL);
		if (ele->type == 'n')
			*(va_arg(ap, int *)) = out->len;
		else
			prt_format1(ele, ap);
	}
	return (ele);
}
