/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 08:01:02 by thninh            #+#    #+#             */
/*   Updated: 2017/07/21 16:06:20 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void		op_funct_1(char c, t_opt *opt)
{
	opt->l = 0;
	opt->x = 0;
	opt->m = 0;
	opt->one = 0;
	opt->up_c1 = 0;
	if (c == 'C')
	{
		opt->up_c2 = 1;
		opt->up_c1 = 1;
	}
	else if (c == 'x')
		opt->x = 1;
	else if (c == 'l' || c == 'g' || c == 'o' || c == 'n')
		op_funct_1s(c, opt);
	else if (c == 'm')
		opt->m = 1;
	else if (c == '1')
		opt->one = 1;
}

void		op_funct_2(char c, t_opt *opt)
{
	if (c == 'r')
		opt->r = 1;
	else if (c == 'c' || c == 'u' || c == 'U')
	{
		opt->u = 0;
		opt->c = 0;
		opt->up_u = 0;
		if (c == 'c')
			opt->c = 1;
		else if (c == 'u')
			opt->u = 1;
		else if (c == 'U')
			opt->up_u = 1;
	}
	else
		opt->up_s = 1;
}

void		op_funct_3(char c, t_opt *opt)
{
	opt->up_f_or_p = 1;
	if (c == 'F')
		opt->up_f = 1;
	else
		opt->up_f = 0;
}

void		op_funct_4(char c, t_opt *opt)
{
	if (c == 't')
		opt->t = 1;
	else if (c == 'T')
		opt->up_time = 1;
	else if (c == 'R')
		opt->up_r = 1;
}

void		op_funct(char c, t_opt *opt)
{
	if (c == 'a' || c == 'A' || c == 'f')
	{
		if (c == 'a' || c == 'f')
			opt->a_f = 1;
		if (c == 'f')
			opt->f = 1;
		opt->a_h = 1;
	}
	else if (ft_strchr("Cglmnox1", c))
		op_funct_1(c, opt);
	else if (c == 'l')
		opt->l = 1;
	else if (ft_strchr("SUcru", c))
		op_funct_2(c, opt);
	else if (c == 'r')
		opt->r = 1;
	else if (c == 'F' || c == 'p')
		op_funct_3(c, opt);
	else if (ft_strchr("RTdnt", c))
		op_funct_4(c, opt);
	else if (c == 't')
		opt->t = 1;
	else
		opt->up_r = 1;
}
