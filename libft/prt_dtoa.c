/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_dtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 23:10:41 by thninh            #+#    #+#             */
/*   Updated: 2017/07/17 23:57:42 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*prt_itoa(long long int n)
{
	int					is_neg;
	unsigned long long	nb_cpy;
	char				inv[100];
	int					i;

	i = 98;
	is_neg = 0;
	if (n < 0)
		is_neg = 1;
	nb_cpy = (n < 0) ? (unsigned long long)-n : (unsigned long long)n;
	inv[99] = '\0';
	while (nb_cpy >= 10)
	{
		inv[i] = nb_cpy % 10 + 48;
		nb_cpy = nb_cpy / 10;
		--i;
	}
	inv[i] = nb_cpy + 48;
	if (is_neg == 1)
		inv[--i] = '-';
	return (ft_strdup(inv + i));
}

void			prt_dtoa(double n, int prec, t_arg *ele, t_out *tmp)
{
	int		i;
	char	*floor;
	char	*after;

	i = 0;
	if (prec == -1)
		prt_itoa1((long long int)n, ele, tmp);
	else
	{
		floor = prt_itoa((long long int)n);
		n = (n < 0) ? -(n - (long long int)n) : (n - (long long int)n);
		if (!(after = ft_memalloc(prec + 2)))
			exit(EXIT_FAILURE);
		after[0] = '.';
		while (++i <= prec)
		{
			after[i] = (int)(n * 10) + 48;
			n = n * 10 - (int)(n * 10);
		}
		ele->len += ft_strlen(floor) + ft_strlen(after);
		prt_fill_out(tmp, floor, ft_strlen(floor));
		prt_fill_out(tmp, after, ft_strlen(after));
		free(after);
		free(floor);
	}
}
