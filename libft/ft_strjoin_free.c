/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 10:44:41 by thninh            #+#    #+#             */
/*   Updated: 2017/07/21 12:56:14 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_free(const char *s1, const char *s2, int del)
{
	char	*str;

	str = NULL;
	if (s1 && s2)
	{
		str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) +
				ft_strlen((char *)s2)) + 1);
		if (!str)
			return (NULL);
		str = ft_strcat(ft_strcpy(str, s1), s2);
		if (del == 1)
			ft_strdel((char **)&s1);
		if (del == 2)
			ft_strdel((char **)&s2);
		if (del == 3)
		{
			ft_strdel((char **)&s1);
			ft_strdel((char **)&s2);
		}
	}
	return (str);
}
