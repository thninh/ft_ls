/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_column.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:06:41 by thninh            #+#    #+#             */
/*   Updated: 2017/07/22 10:30:48 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void			display_coldown(t_ls *lst, int col, int elem, size_t size)
{
	int			i;
	int			j;
	t_ls		*p;
	int			ele_col;

	i = -1;
	j = 1;
	ele_col = elem / col + ((elem % col > 0) ? 1 : 0);
	while (elem > 0)
	{
		p = prt_list_at(lst, j + (++i * ele_col));
		if (p)
		{
			ft_printf("%-*s",
					((i < col - 1) ? size : 0), ((t_elem *)p->data)->name);
			--elem;
		}
		if ((i >= col - 1 && elem != 0) || !p)
		{
			write(1, "\n", 1);
			i = -1;
			++j;
		}
	}
}

void			display_colacross(t_ls *lst, int col, int elem, size_t size)
{
	int			i;

	while (elem > 0)
	{
		i = col;
		while (elem > 0 && i > 0)
		{
			ft_printf("%-*s ", size - 1, ((t_elem *)lst->data)->name);
			lst = lst->next;
			--i;
			--elem;
		}
		if (i == 0)
			write(1, "\n", 1);
	}
}

void			display_column(struct winsize ws, t_ls *lst, t_opt *opt)
{
	int			col;
	int			elem;
	size_t		size;
	t_ls		*l;

	l = lst;
	size = 0;
	prt_ilist(&lst);
	while (l != NULL)
	{
		if (((t_elem *)l->data)->lname + 1 > size)
			size = ((t_elem *)l->data)->lname + 1;
		if (!l->next)
			elem = l->i;
		l = l->next;
	}
	col = ws.ws_col / size;
	if (opt->up_c1)
		display_coldown(lst, col, elem, size);
	else
		display_colacross(lst, col, elem, size);
}
