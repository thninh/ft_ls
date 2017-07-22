/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 06:27:01 by thninh            #+#    #+#             */
/*   Updated: 2017/07/22 12:22:46 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void			error_display(char err_op)
{
	ft_dprintf(2, "ft_ls: illegal option -- %c\n", err_op);
	ft_dprintf(2, "usage: ft_ls ");
	ft_dprintf(2, "[-ACFRSTUacfglmnoprtux1] [file ...]\n");
}
