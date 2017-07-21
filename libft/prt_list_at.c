/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_list_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 08:01:24 by thninh            #+#    #+#             */
/*   Updated: 2017/07/18 08:02:52 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_mylst	*prt_list_at(t_mylst *lst, int i)
{
	while (lst)
	{
		if (lst->i == i)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
