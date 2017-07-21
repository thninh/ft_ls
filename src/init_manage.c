/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 07:20:46 by thninh            #+#    #+#             */
/*   Updated: 2017/07/21 13:31:53 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	init_op(t_opt *opt)
{
	opt->c = 0;
	opt->n = 0;
	opt->o = 0;
	opt->g = 0;
	opt->t = 0;
	opt->up_time = 0;
	opt->u = 0;
	opt->up_u = 0;
	opt->f = 0;
	opt->one = 0;
	opt->up_c1 = 1;
	opt->up_c2 = 0;
	opt->x = 0;
	opt->up_r = 0;
	opt->m = 0;
	opt->l = 0;
	opt->up_f_or_p = 0;
	opt->up_f = 0;
	opt->a_h = 0;
	opt->a_f = 0;
	opt->r = 0;
	opt->up_s = 0;
}

void	init_format(t_format *format)
{
	format->cnt_blk = 0;
	format->uid = 0;
	format->gid = 0;
	format->link = 0;
	format->name = 0;
	format->major = 0;
	format->minor = 0;
}

void	init_elem(t_elem *new_elem)
{
	new_elem->name = NULL;
	new_elem->path = NULL;
	new_elem->name_group = NULL;
	new_elem->name_user = NULL;
	new_elem->mode = 0;
	new_elem->s_mode = 0;
	new_elem->lname = 0;
	new_elem->lpath = 0;
	new_elem->luid = 0;
	new_elem->lgid = 0;
}
