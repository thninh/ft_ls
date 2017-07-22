/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 16:01:59 by thninh            #+#    #+#             */
/*   Updated: 2017/07/22 10:44:11 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void			op_funct_1s(char c, t_opt *opt)
{
	opt->l = 1;
	if (c == 'g')
		opt->g = 1;
	else if (c == 'o')
		opt->o = 1;
	else if (c == 'n')
		opt->n = 1;
}

int				check_param(t_opt *opt, int ac, char **av)
{
	int			i;
	int			j;

	i = 0;
	init_op(opt);
	while (++i < ac && av[i][0] == '-')
	{
		j = 1;
		if (!ft_strcmp(av[i], "--"))
			return (i + 1);
		if (!av[i][j])
			return (i);
		while (av[i][j])
		{
			if (!ft_strchr("ACFRSTUacfglmnoprtux1", av[i][j]))
			{
				error_display(av[i][j]);
				exit(1);
			}
			op_funct(av[i][j++], opt);
		}
	}
	return (i);
}
