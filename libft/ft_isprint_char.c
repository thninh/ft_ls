/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:52:40 by thninh            #+#    #+#             */
/*   Updated: 2017/06/08 14:52:46 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isprint_char(char *str, int len)
{
	int		i;

	i = 0;
	while (i < len && str[i] != '\0')
	{
		if (!ft_isprint_charact(str[i]))
			return (0);
		i++;
	}
	return (1);
}
