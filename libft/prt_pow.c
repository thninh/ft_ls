/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_pow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 00:08:24 by thninh            #+#    #+#             */
/*   Updated: 2017/07/18 00:08:35 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

double	prt_pow(double pow, int nb)
{
	double	n;

	n = pow;
	if (nb > 0)
	{
		while (nb > 1)
		{
			pow = pow * n;
			nb--;
		}
	}
	else
	{
		while (nb <= 0)
		{
			pow = pow / n;
			nb++;
		}
	}
	return (pow);
}
