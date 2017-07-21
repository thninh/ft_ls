/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:19:23 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 21:20:12 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_dprintf(int fd, const char *format, ...)
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
			prt_dprocess_format(&output, ele);
		++format;
		prt_free_ele(&ele);
	}
	return (prt_dend(fd, &output, &ele, ap));
}
