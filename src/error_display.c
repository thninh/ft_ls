/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 06:27:01 by thninh            #+#    #+#             */
/*   Updated: 2017/07/21 16:25:42 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void			error_arg(char *arg, char *err)
{
	ft_putstr_fd("./ft_ls: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err, 2);
}

void			error_display(char err_op)
{
	ft_putstr_fd("./ft_ls: illegal option -- ", 2);
	ft_putchar_fd(err_op, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: ./ft_ls [-ACFRSTUacfglmnoprtux1] [file ...]", 2);
}
