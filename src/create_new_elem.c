/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 16:12:12 by thninh            #+#    #+#             */
/*   Updated: 2017/07/21 16:18:43 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

char			check_mode_elem(t_stt stt)
{
	if ((stt.st_mode & S_IFMT) == S_IFREG)
		return ('f');
	if ((stt.st_mode & S_IFMT) == S_IFDIR)
		return ('d');
	if ((stt.st_mode & S_IFMT) == S_IFLNK)
		return ('l');
	if ((stt.st_mode & S_IFMT) == S_IFIFO)
		return ('p');
	if ((stt.st_mode & S_IFMT) == S_IFSOCK)
		return ('s');
	if ((stt.st_mode & S_IFMT) == S_IFBLK)
		return ('b');
	if ((stt.st_mode & S_IFMT) == S_IFCHR)
		return ('c');
	if ((stt.st_mode & S_IFMT) == S_IFWHT)
		return ('W');
	return (0);
}

void			print_mode_elem(t_elem *f, t_opt *opt)
{
	if (opt->up_f)
	{
		if (f->mode == 'd')
			f->s_mode = '/';
		else if (f->mode == 'l')
			f->s_mode = '@';
		else if (f->mode == 's')
			f->s_mode = '=';
		else if (f->mode == 'W')
			f->s_mode = '%';
		else if (f->mode == 'p')
			f->s_mode = '|';
		else if (f->stt.st_mode & S_IXUSR || f->stt.st_mode & S_IXGRP
			|| f->stt.st_mode & S_IXOTH)
			f->s_mode = '*';
	}
	else if (opt->up_f_or_p && f->mode == 'd')
		f->s_mode = '/';
	if (!opt->l)
		return ;
}

void			option_manage(t_elem *f, t_opt *opt)
{
	t_pwd		*pwd;
	t_gr		*grp;

	if (!opt->g)
	{
		if (opt->n || (pwd = getpwuid(f->stt.st_uid)) == NULL)
			f->luid = ft_asprintf(&(f->name_user), "%u", f->stt.st_uid);
		else
			f->luid = ft_asprintf(&(f->name_user), "%s", pwd->pw_name);
	}
	else
		f->name_user = ft_strdup("");
	if (!opt->o)
	{
		if (opt->n || (grp = getgrgid(f->stt.st_gid)) == NULL)
			f->lgid = ft_asprintf(&(f->name_group), "%u", f->stt.st_gid);
		else
			f->lgid = ft_asprintf(&(f->name_group), "%s", grp->gr_name);
	}
	else
		f->name_group = ft_strdup("");
}

t_elem			*create_new_elem(char *name, char *path, t_opt *opt)
{
	t_elem		*elem;

	if (!(elem = malloc(sizeof(t_elem))))
		return (NULL);
	init_elem(elem);
	lstat(path, &(elem->stt));
	if (check_mode_elem(elem->stt) != 'l')
	{
		if (stat(path, &(elem->stt)) == -1)
		{
			error_arg(name, strerror(errno));
			free(elem);
			return (NULL);
		}
	}
	elem->lpath = ft_asprintf(&(elem->path), "%s", path);
	elem->mode = check_mode_elem(elem->stt);
	if (opt)
		option_manage(elem, opt);
	elem->name = ft_strdup(name);
	return (elem);
}
