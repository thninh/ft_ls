/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_manage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 07:08:42 by thninh            #+#    #+#             */
/*   Updated: 2017/07/22 10:30:28 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void			name_mode(t_ls *lst)
{
	int			i;
	char		*s;
	t_ls		*l;

	i = 0;
	l = lst;
	while (lst)
	{
		s = ((t_elem *)lst->data)->name;
		((t_elem *)lst->data)->lname =
			ft_asprintf(&((t_elem *)lst->data)->name, "%s%c",
			((t_elem *)lst->data)->name, ((t_elem *)lst->data)->s_mode);
		if (((t_elem *)lst->data)->s_mode)
			((t_elem *)lst->data)->lname += 1;
		lst = lst->next;
		free(s);
	}
	if (i)
	{
		while (l)
		{
			((t_elem *)l->data)->lname += 1;
			l = l->next;
		}
	}
}

void			display_m_option(t_ls *lst, struct winsize ws, int x)
{
	int			len;

	len = 0;
	while (lst != NULL)
	{
		if (lst->next)
			len += ft_printf("%s, ", ((t_elem *)lst->data)->name);
		else
			ft_printf("%s", ((t_elem *)lst->data)->name);
		lst = lst->next;
		if (len >= ws.ws_col
			|| (lst && len + ((t_elem *)lst->data)->lname + 1 >= ws.ws_col - 1))
		{
			write(1, "\n", 1);
			len = 0;
		}
	}
	if (x == 2)
		write(1, ",", 1);
}

void			display_manage(t_ls *lst, t_opt *opt, int x)
{
	struct winsize	ws;

	if (!lst)
		return ;
	name_mode(lst);
	if (opt->l)
		display_info_elem(lst, opt);
	else if ((isatty(1) || opt->up_c2 || opt->m) && !opt->one)
	{
		ioctl(0, TIOCGWINSZ, &ws);
		if (opt->m)
			display_m_option(lst, ws, x);
		else if (opt->up_c1 || opt->x)
			display_column(ws, lst, opt);
		write(1, "\n", 1);
	}
	else if ((!isatty(1) && !opt->up_c2 && !opt->m)
			|| opt->one)
	{
		while (lst != NULL)
		{
			ft_printf("%s\n", ((t_elem *)lst->data)->name);
			lst = lst->next;
		}
	}
}
