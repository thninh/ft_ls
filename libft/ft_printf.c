/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 22:55:40 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 22:59:23 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		prt_process_format(t_out *output, t_arg *ele)
{
	t_out		tmp;

	prt_init_out(&tmp);
	if (ele->type == 'f' || ele->type == 'F')
		prt_float(output, &tmp, ele);
	else if (ele->format == 'c' || ele->type == 's')
		prt_alpha(output, &tmp, ele);
	else if (ele->type == 'C' || ele->type == 'S')
		prt_wide(output, &tmp, ele);
	else if (ele->type == 'p')
		prt_point((unsigned long int)(ele->data.p), output, &tmp, ele);
	else if (ele->type == '%')
		prt_percent(output, &tmp, ele);
	else if (ft_strchr("hydDuULwK", ele->format))
		prt_num(output, &tmp, ele);
	else
		prt_nonspec(output, &tmp, ele);
}

static int		prt_end(t_out *out, t_arg **ele, va_list ap)
{
	int		len;

	len = out->len;
	write(1, out->out, out->len);
	prt_free_ele(ele);
	prt_free_out(out);
	va_end(ap);
	return (len);
}

int				ft_printf(const char *format, ...)
{
	t_arg		*ele;
	va_list		ap;
	int			i;
	t_out		output;

	i = 0;
	prt_init_out(&output);
	va_start(ap, format);
	while ((ele = prt_print(&output, &format, ap)) != NULL)
	{
		if (ele->type != 'n')
			prt_process_format(&output, ele);
		++format;
		prt_free_ele(&ele);
	}
	return (prt_end(&output, &ele, ap));
}
