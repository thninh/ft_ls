/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 06:21:00 by thninh            #+#    #+#             */
/*   Updated: 2017/07/21 16:29:37 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void			tri_size(t_ls **begin, t_opt opt)
{
	int			i;
	t_ls		*lst;
	void		*tmp;

	i = 1;
	while (i)
	{
		lst = *begin;
		i = 0;
		while (lst && lst->next)
		{
			if ((opt.r && ((t_elem *)lst->data)->stt.st_size
						> ((t_elem *)lst->next->data)->stt.st_size)
					|| ((!opt.r) && ((t_elem *)lst->data)->stt.st_size
						< ((t_elem *)lst->next->data)->stt.st_size))
			{
				i = 1;
				tmp = lst->data;
				lst->data = lst->next->data;
				lst->next->data = tmp;
			}
			lst = lst->next;
		}
	}
}

time_t			get_time(time_t *s2, t_opt opt, t_stt st1, t_stt st2)
{
	time_t		s1;

	if (opt.up_u)
	{
		s1 = st1.st_birthtimespec.tv_sec;
		*s2 = st2.st_birthtimespec.tv_sec;
	}
	else if (opt.u)
	{
		s1 = st1.st_atimespec.tv_sec;
		*s2 = st2.st_atimespec.tv_sec;
	}
	else if (opt.c)
	{
		s1 = st1.st_ctimespec.tv_sec;
		*s2 = st2.st_ctimespec.tv_sec;
	}
	else
	{
		s1 = st1.st_mtimespec.tv_sec;
		*s2 = st2.st_mtimespec.tv_sec;
	}
	return (s1);
}

void			tri_time(t_ls **begin, t_opt opt)
{
	int			i;
	t_ls		*lst;
	void		*tmp;
	time_t		s1;
	time_t		s2;

	i = 1;
	while (i)
	{
		lst = *begin;
		i = 0;
		while (lst && lst->next)
		{
			s1 = get_time(&s2, opt, ((t_elem *)lst->data)->stt,
					((t_elem *)lst->next->data)->stt);
			if ((opt.r && s1 > s2) || (!opt.r && s1 < s2))
			{
				i = 1;
				tmp = lst->data;
				lst->data = lst->next->data;
				lst->next->data = tmp;
			}
			lst = lst->next;
		}
	}
}

void			sort_list_elem(t_ls **begin, t_opt opt)
{
	if (!(*begin) || opt.f || (!opt.t && !opt.up_s))
		return ;
	if (opt.up_s)
		tri_size(begin, opt);
	else
		tri_time(begin, opt);
}

t_ls			*files_manage(t_ls *lst, int ac, char **av, t_opt opt)
{
	int			i;
	t_stt		stt;

	i = 0;
	while (i < ac - 1)
	{
		if (av[i] && lstat(av[i], &stt) == -1)
		{
			CHECK(ft_strcmp(av[i], ""));
			error_arg(av[i], strerror(errno));
		}
		else if ((check_mode_elem(stt) == 'l' && ((stat(av[i], &stt) != -1
			&& (check_mode_elem(stt) != 'd' || opt.l)) ||
				(stat(av[i], &stt) == -1)))
			|| check_mode_elem(stt) == 'f')
			listing_file(&lst, prt_mylstnew(create_new_elem(av[i], av[i], &opt),
						sizeof(t_elem *)), opt);
		i++;
	}
	sort_list_elem(&lst, opt);
	display_manage(lst, &opt, 2);
	return (lst);
}
