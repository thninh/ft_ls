/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 00:49:38 by thninh            #+#    #+#             */
/*   Updated: 2017/07/21 16:41:15 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void			check_deux_tiret(int argc, char **argv)
{
	int			i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			if (argv[i] && (argv[i] = "--") && argv[i + 1])
			{
				ft_putstr_fd("./ft_ls: ", 2);
				ft_putstr_fd(argv[i + 1], 2);
				ft_putendl_fd(": No such file or directory", 2);
				exit(EXIT_FAILURE);
			}
			i++;
		}
	}
}

void			check_tiret(int argc, char **argv)
{
	int			i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			if (argv[i] && argv[i][0] == '-' && argv[i][1] == '\0')
			{
				ft_putstr_fd("./ft_ls: -: No such file or directory\n", 2);
				exit(EXIT_FAILURE);
			}
			i++;
		}
	}
}

int				main(int argc, char **argv)
{
	int			i;
	int			code;
	t_ls		*lst;
	t_opt		opt;

	code = 0;
	lst = NULL;
	check_tiret(argc, argv);
	check_deux_tiret(argc, argv);
	i = check_param(&opt, argc, argv);
	if (argv[i] && !opt.f)
		ft_sorter_comparator(argv + i);
	i--;
	if ((lst = files_manage(lst, argc - i, argv + i, opt)))
		code = 1;
	dirs_manage(argc - i, argv + i, opt, code);
	free_manage(&lst);
	return (0);
}
