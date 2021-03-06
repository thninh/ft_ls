/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_charact.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:09:42 by thninh            #+#    #+#             */
/*   Updated: 2017/06/08 15:09:47 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isprint_charact(char c)
{
	return ((c <= ' ' && c >= '~') ? 0 : 1);
}
