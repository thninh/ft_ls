/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_pad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 22:51:03 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 22:52:19 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		prt_padright(t_arg *ele, char *flag, t_out *output)
{
	int		i;
	char	*ptr;
	int		len;

	i = -1;
	ptr = NULL;
	if (flag && *flag)
	{
		while (++i < ele->pad)
			prt_join_before(output, &(ele->padchar), 1);
		prt_join_before(output, flag, ft_strlen(flag));
	}
	else if (ele->pad > 0 && output->len > 0 && ft_strchr("dDifF", ele->type)
			&& *(output->out) == '-' && ele->padchar == '0')
	{
		ptr = ft_strndup(output->out + 1, output->len - 1);
		len = output->len - 1;
		prt_free_out(output);
		prt_fill_out(output, "-", 1);
		while (++i < ele->pad)
			prt_fill_out(output, &(ele->padchar), 1);
		prt_fill_out(output, ptr, len);
		free(ptr);
	}
	return (i);
}

void			prt_pad(t_out *output, char *flag, t_arg *ele)
{
	int		i;

	i = -1;
	if (ele->padleft != 1)
		ele->padleft = (ele->pad < 0) ? 1 : 0;
	ele->pad = ((ele->pad < 0) ? -(ele->pad) : ele->pad) - output->len;
	if (ele->padleft == 1)
	{
		if (flag && *flag)
			prt_join_before(output, flag, ft_strlen(flag));
		while (++i < ele->pad)
			prt_fill_out(output, &(ele->padchar), 1);
	}
	else
	{
		if ((ele->padchar == ' ' || ele->type == 'Z') && flag && *flag)
			prt_join_before(output, flag, ft_strlen(flag));
		else
			i = prt_padright(ele, flag, output);
	}
	while (++i < ele->pad)
		prt_join_before(output, &(ele->padchar), 1);
}
