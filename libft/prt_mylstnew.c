/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_mylstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 06:02:02 by thninh            #+#    #+#             */
/*   Updated: 2017/07/18 06:02:55 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_mylst		*prt_mylstnew(void *data, size_t ldata)
{
	t_mylst	*ad;

	ad = (t_mylst *)ft_memalloc(sizeof(t_mylst));
	if (!data || !ad)
		return (NULL);
	ad->data = data;
	ad->ldata = ldata;
	ad->next = NULL;
	ad->prev = NULL;
	return (ad);
}
