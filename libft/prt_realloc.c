/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_realloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 22:46:51 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 22:47:16 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*prt_realloc(void *ptr, size_t size, size_t old_size)
{
	void	*dup;

	dup = NULL;
	if (size)
		if (!(dup = (char *)malloc(size)))
			return (NULL);
	if (ptr && dup)
	{
		ft_memcpy(dup, ptr, old_size);
		ft_memdel(&ptr);
	}
	(*(char *)(dup + size - 1)) = '\0';
	return (dup);
}
