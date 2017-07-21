/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorter_comparator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 15:25:52 by thninh            #+#    #+#             */
/*   Updated: 2017/07/18 06:45:26 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_sorter_comparator(char **arg)
{
	int		i;
	char	*is_sort;
	char	**tmp;

	i = 1;
	while (i)
	{
		tmp = arg;
		i = 0;
		while (*tmp && *(tmp + 1))
		{
			if (ft_strcmp(*tmp, *(tmp + 1)) > 0)
			{
				i = 1;
				is_sort = *tmp;
				*tmp = *(tmp + 1);
				*(tmp + 1) = is_sort;
			}
			tmp++;
		}
	}
}
