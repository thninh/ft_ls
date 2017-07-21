/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_in_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 12:08:01 by thninh            #+#    #+#             */
/*   Updated: 2017/07/16 12:08:03 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_char_in_arg(char c, char *str)
{
	int		index;

	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			return (1);
		index++;
	}
	return (0);
}
