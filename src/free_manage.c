/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 10:37:14 by thninh            #+#    #+#             */
/*   Updated: 2017/07/22 15:12:18 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void		free_file(t_elem *file)
{
	free(file->name);
	free(file->path);
	if (file->name_user)
		free(file->name_user);
	if (file->name_group)
		free(file->name_group);
	free(file);
}

void		free_manage(t_ls **lst)
{
	t_ls		*tmp;

	tmp = *lst;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free_file(((t_elem *)tmp->data));
		free(tmp);
	}
	*lst = NULL;
}
