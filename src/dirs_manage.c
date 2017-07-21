/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirs_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 08:11:25 by thninh            #+#    #+#             */
/*   Updated: 2017/07/21 14:02:38 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_ls			*ft_open_dir(DIR *rep, char *dname, t_opt opt, int x)
{
	t_d			*file;
	t_ls		*lst;
	t_elem		*ele;
	char		*path;

	lst = NULL;
	path = NULL;
	while ((file = readdir(rep)))
	{
		if ((opt.a_h || *(file->d_name) != '.')
				&& (opt.a_f || (ft_strcmp(".", file->d_name)
						&& ft_strcmp("..", file->d_name))))
		{
			if (!ft_strcmp(dname, "/"))
				ft_asprintf(&path, "%s%s", dname, file->d_name);
			else
				ft_asprintf(&path, "%s/%s", dname, file->d_name);
			ele = create_new_elem(file->d_name, path, &opt);
			listing_file(&lst, prt_mylstnew(ele, sizeof(ele)), opt);
			free(path);
		}
	}
	sort_list_elem(&lst, opt);
	display_manage(lst, &opt, x);
	return (lst);
}

void			read_dir(t_ls *lst, char *dname, t_opt opt, int x)
{
	DIR			*rep;
	char		*tmp;

	if (x == 1)
		ft_printf("\n%s:\n", dname);
	else if (x == 2)
		ft_printf("%s:\n", dname);
	if (!(rep = opendir(dname)))
	{
		tmp = ft_strrchr(dname, '/');
		error_arg(((tmp) ? tmp + 1 : dname), strerror(errno));
	}
	else
	{
		lst = ft_open_dir(rep, dname, opt, x);
		read_list(lst, opt);
		if (closedir(rep) == -1)
		{
			tmp = ft_strrchr(dname, '/');
			error_arg(((tmp) ? tmp + 1 : dname), strerror(errno));
		}
	}
}

void			read_list(t_ls *lst, t_opt opt)
{
	t_ls		*sub;
	t_ls		*ptr;

	ptr = lst;
	while (lst != NULL)
	{
		sub = NULL;
		if (opt.up_r && (opt.a_h || *((((t_elem *)lst->data)->name)) != '.')
				&& ((t_elem *)lst->data)->mode == 'd'
				&& ft_strcmp(".", ((t_elem *)lst->data)->name)
				&& ft_strcmp("..", ((t_elem *)lst->data)->name)
				&& ft_strcmp("./", ((t_elem *)lst->data)->name)
				&& ft_strcmp("../", ((t_elem *)lst->data)->name))
			read_dir(sub, ((t_elem *)lst->data)->path, opt, 1);
		lst = lst->next;
	}
	free_manage(&ptr);
}

void			dirs_manage(int ac, char **av, t_opt opt, int x)
{
	int			i;
	char		type;
	t_stt		stt;
	t_ls		*lst;

	lst = NULL;
	i = 0;
	if (i + 1 == ac)
		read_dir(lst, ".", opt, x);
	if (!x && i + 2 < ac)
		x = 2;
	while (++i < ac)
	{
		if (av[i] && lstat(av[i], &stt) != -1)
		{
			type = check_mode_elem(stt);
			if (type == 'd')
				read_dir(lst, av[i], opt, x);
			else if ((type == 'l' && !opt.l) && (stat(av[i], &stt) != -1
						&& (check_mode_elem(stt) == 'd')))
				read_dir(lst, av[i], opt, x);
			x = 1;
		}
	}
}
