/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_ladd_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 05:53:34 by thninh            #+#    #+#             */
/*   Updated: 2017/07/18 05:53:40 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		prt_ladd_back(t_mylst **list, t_mylst *add)
{
	t_mylst	*lst;

	if (!list)
		return ;
	else
	{
		lst = *list;
		if (add)
		{
			if (!*list)
				*list = add;
			else
			{
				while (lst->next)
					lst = lst->next;
				lst->next = add;
				add->prev = lst;
			}
		}
	}
}
