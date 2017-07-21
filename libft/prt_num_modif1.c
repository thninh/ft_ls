/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_num_modif1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 22:31:10 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 23:41:18 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prt_num_modif1(t_arg *ele)
{
	if (ele->modifier == 'z')
	{
		if (ele->unsign)
			ele->format = 'U';
		else if (ele->type == 'd' || ele->type == 'i')
			ele->type = 'L';
	}
	else if (ele->modifier == 'H')
	{
		if (ele->unsign)
			ele->format = 'w';
		else if (ele->type == 'd' || ele->type == 'i')
			ele->type = 'z';
	}
	else if (ele->modifier == 'h')
	{
		if (ele->unsign)
			ele->format = 'y';
		else if (ele->type == 'd' || ele->type == 'i')
			ele->format = 'h';
	}
}
