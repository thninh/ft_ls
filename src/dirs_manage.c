/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirs_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 08:11:25 by thninh            #+#    #+#             */
/*   Updated: 2017/07/22 12:36:44 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_ls			*ft_opendir(DIR *dir, char *dname, t_opt opt, int x)
{
	t_ls			*lst;
	t_elem			*ele;
	char			*path;
	struct dirent	*file;

	lst = NULL;
	path = NULL;
	while ((file = readdir(dir)))
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

void			ft_readdir(t_ls *lst, char *dname, t_opt opt, int x)
{
	DIR			*dir;
	char		*tmp;

	if (x == 1)
		ft_printf("\n%s:\n", dname);
	else if (x == 2)
		ft_printf("%s:\n", dname);
	if (!(dir = opendir(dname)))
	{
		tmp = ft_strrchr(dname, '/');
		ft_dprintf(2, "ft_ls: %s: %s\n", ((tmp) ? tmp + 1 : dname),
				strerror(errno));
	}
	else
	{
		lst = ft_opendir(dir, dname, opt, x);
		ft_readlist(lst, opt);
		if (closedir(dir) == -1)
		{
			tmp = ft_strrchr(dname, '/');
			ft_dprintf(2, "ft_ls: %s: %s\n", ((tmp) ? tmp + 1 : dname),
					strerror(errno));
		}
	}
}

void			ft_readlist(t_ls *lst, t_opt opt)
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
			ft_readdir(sub, ((t_elem *)lst->data)->path, opt, 1);
		lst = lst->next;
	}
	free_manage(&ptr);
}

void			dirs_manage(int ac, char **av, t_opt opt, int x)
{
	int				i;
	char			type;
	t_ls			*lst;
	struct stat		stt;

	i = 0;
	lst = NULL;
	if (i + 1 == ac)
		ft_readdir(lst, ".", opt, x);
	if (!x && i + 2 < ac)
		x = 2;
	while (++i < ac)
	{
		if (av[i] && lstat(av[i], &stt) != -1)
		{
			type = check_mode_elem(stt);
			if (type == 'd')
				ft_readdir(lst, av[i], opt, x);
			else if ((type == 'l' && !opt.l) && (stat(av[i], &stt) != -1
						&& (check_mode_elem(stt) == 'd')))
				ft_readdir(lst, av[i], opt, x);
			x = 1;
		}
	}
}
