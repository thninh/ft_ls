/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:42:29 by thninh            #+#    #+#             */
/*   Updated: 2017/07/21 15:26:41 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

size_t			info_link(t_ls *lst, char link[1024])
{
	size_t		ret;

	ret = 0;
	if (((t_elem *)lst->data)->mode == 'l')
	{
		ret = readlink(((t_elem *)lst->data)->path, link + 1, 1023);
		link[0] = '/';
		link[ret + 1] = '\0';
	}
	return (ret);
}

char			*time_info(t_opt *opt, time_t *tm_spec, t_elem *f, int *t)
{
	char		*tm;

	if (opt->c)
		*tm_spec = f->stt.st_ctimespec.tv_sec;
	else if (opt->u)
		*tm_spec = f->stt.st_atimespec.tv_sec;
	else if (opt->up_u)
		*tm_spec = f->stt.st_birthtimespec.tv_sec;
	else
		*tm_spec = f->stt.st_mtimespec.tv_sec;
	tm = ctime(tm_spec);
	if (tm[25])
	{
		ft_memmove(tm + 20, tm + 24, 5);
		*t = 6;
	}
	else if (opt->up_time)
		*t = 8;
	else
		*t = 5;
	return (tm);
}

void			info_elem(t_elem *f, t_opt *opt)
{
	int			t;
	char		*tm;
	time_t		tm_loc;
	time_t		tm_spec;

	tm = time_info(opt, &tm_spec, f, &t);
	ft_printf(" %.3s %.2s %.*s %-*.4s%s", tm + 4, tm + 8, t, ((tm_spec
			< time(&tm_loc) - 15768000 || tm_spec > time(&tm_loc) + 15768000)
				? tm + 19 : tm + 11), ((opt->up_time) ? 5 : 0),
				((opt->up_time) ? tm + 20 : ""), f->name);
}

void			display_info_elem(t_ls *lst, t_opt *opt)
{
	size_t		i;
	t_format	format;
	char		link[1024];

	init_format(&format);
	format_manage(lst, &format);
	if (lst && ((t_elem *)lst->data)->lpath > ((t_elem *)lst->data)->lname)
		ft_printf("total %lu\n", format.cnt_blk);
	while (lst)
	{
		i = 0;
		permission_handler(((t_elem *)lst->data), format);
		i = info_link(lst, link);
		if (ft_strchr("bc", ((t_elem *)lst->data)->mode))
			ft_printf("%*d, %*d", format.major,
					major(((t_elem *)lst->data)->stt.st_rdev), format.minor,
					minor(((t_elem *)lst->data)->stt.st_rdev));
		else
			ft_printf("%*u", format.name, ((t_elem *)lst->data)->stt.st_size);
		info_elem((t_elem *)lst->data, opt);
		if (i)
			ft_printf(" -> %s", link + 1);
		write(1, "\n", 1);
		lst = lst->next;
	}
}
