/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_join_before.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 22:48:42 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 22:49:09 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prt_join_before(t_out *out, const char *s, int len)
{
	char	*new_str;
	int		nlen;

	if (len > 0)
	{
		if (!s)
			return ;
		else
		{
			if (!(new_str = (char *)malloc(sizeof(char)
							* (out->len + len + 1))))
				exit(EXIT_FAILURE);
			new_str = ft_memcpy(new_str, s, len);
			ft_memcpy(new_str + len, out->out, out->len);
			nlen = out->len + len;
			prt_free_out(out);
			prt_fill_out(out, new_str, nlen);
			free(new_str);
		}
	}
}
