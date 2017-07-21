/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 16:09:46 by thninh            #+#    #+#             */
/*   Updated: 2017/07/21 16:23:44 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void		listing_file1(t_ls **begin, t_ls *lnew,
		int (*f)(const char *, const char *))
{
	t_ls	*lst;

	lst = *begin;
	if (ft_strcmp(((t_elem *)lst->data)->name,
				((t_elem *)lnew->data)->name) < 0)
	{
		lnew->next = lst;
		lst->prev = lnew;
		*begin = lnew;
	}
	else
	{
		while (lst->next && (f)(((t_elem *)lst->next->data)->name,
					((t_elem *)lnew->data)->name) >= 0)
			lst = lst->next;
		lnew->next = lst->next;
		lst->next = lnew;
		lnew->prev = lst;
	}
}

void		listing_file2(t_ls **begin, t_ls *lnew,
		int (*f)(const char *, const char *))
{
	t_ls	*lst;

	lst = *begin;
	if ((f)(((t_elem *)lst->data)->name, ((t_elem *)lnew->data)->name) > 0)
	{
		lnew->next = lst;
		lst->prev = lnew;
		*begin = lnew;
	}
	else
	{
		while (lst->next && (f)(((t_elem *)lst->next->data)->name,
					((t_elem *)lnew->data)->name) <= 0)
			lst = lst->next;
		lnew->next = lst->next;
		lst->next = lnew;
		lnew->prev = lst;
	}
}

void		listing_file(t_ls **begin, t_ls *lnew, t_opt opt)
{
	if (begin && lnew)
	{
		if (!*begin)
			*begin = lnew;
		else if (opt.f)
			prt_ladd_back(begin, lnew);
		else if (opt.r)
			listing_file1(begin, lnew, &ft_strcmp);
		else
			listing_file2(begin, lnew, &ft_strcmp);
	}
}
