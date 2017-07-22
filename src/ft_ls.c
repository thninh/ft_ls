/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 00:49:38 by thninh            #+#    #+#             */
/*   Updated: 2017/07/22 12:33:14 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int				main(int argc, char **argv)
{
	int			i;
	int			x;
	t_ls		*lst;
	t_opt		opt;

	x = 0;
	lst = NULL;
	i = check_param(&opt, argc, argv);
	if (argv[i] && !opt.f)
		ft_sorter_comparator(argv + i);
	i--;
	if ((lst = files_manage(lst, argc - i, argv + i, opt)))
		x = 1;
	dirs_manage(argc - i, argv + i, opt, x);
	free_manage(&lst);
	return (0);
}
