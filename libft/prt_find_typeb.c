/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_find_typeb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 22:24:25 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 22:25:09 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prt_find_typeb(const char *str, t_arg *ele, va_list ap)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (ft_strchr("hlzj0#+-", str[i]))
			prt_find_typea(ele, str, i);
		else if (str[i] == ' ')
			ele->space = 1;
		else if (str[i] == '*')
			prt_wild(str, i, ele, ap);
		else if (ft_isdigit(str[i]) && (i == 0 || str[i - 1] != '.'))
			i = prt_find_pad(ele, i, str);
		else if (str[i] == '.' && str + i + 1)
			i = prt_precision(ele, i, str);
		else
		{
			ele->type = str[i];
			return (i);
		}
	}
	ele->type = str[i];
	return (i);
}
