/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:04:09 by thninh            #+#    #+#             */
/*   Updated: 2017/07/22 13:38:11 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void		format_manage(t_ls *l, t_format *format)
{
	size_t	tmp;

	tmp = 0;
	while (l)
	{
		format->cnt_blk += ((t_elem *)l->data)->stt.st_blocks;
		if (format->uid < ((t_elem *)l->data)->luid)
			format->uid = ((t_elem *)l->data)->luid;
		if (format->gid < ((t_elem *)l->data)->lgid)
			format->gid = ((t_elem *)l->data)->lgid;
		tmp = ft_len_grid(((t_elem *)l->data)->stt.st_nlink);
		if (format->link < tmp)
			format->link = tmp;
		tmp = ft_len_grid(((t_elem *)l->data)->stt.st_size);
		if (format->name < tmp)
			format->name = tmp;
		if (ft_strchr("bc", ((t_elem *)l->data)->mode))
		{
			if (format->major < MAJOR)
				format->major = MAJOR;
			if (format->minor < MINOR)
				format->minor = MINOR;
		}
		l = l->next;
	}
}
