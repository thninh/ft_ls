/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 06:07:06 by thninh            #+#    #+#             */
/*   Updated: 2017/07/21 11:47:50 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_len_grid(int nb)
{
	size_t	cnt;

	cnt = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		cnt++;
	}
	cnt++;
	return (cnt);
}