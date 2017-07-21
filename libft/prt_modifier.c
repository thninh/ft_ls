/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_modifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 22:32:56 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 22:33:31 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		prt_modifier(t_arg *ele)
{
	if (ele->modifier == 'l')
	{
		if (ele->unsign)
			ele->format = 'U';
		else if (ele->type == 'd' || ele->type == 'i')
			ele->type = 'D';
		else if (ele->type == 's' || ele->type == 'c')
		{
			ele->type = (ele->type == 's') ? 'S' : 'C';
			ele->format = (ele->type == 'C') ? 'C' : ele->format;
		}
	}
	else if (ele->modifier == 'L')
	{
		if (ele->unsign)
			ele->format = 'K';
		else if (ele->type == 'd' || ele->type == 'i')
			ele->type = 'L';
	}
	else if (ele->modifier == 'j' && (ele->type == 'd' || ele->type == 'i'))
		ele->type = 'D';
	else if (ele->modifier == 'j' && ele->unsign)
		ele->format = 'U';
	prt_num_modif1(ele);
}
