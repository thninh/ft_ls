/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permission_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:45:58 by thninh            #+#    #+#             */
/*   Updated: 2017/07/22 10:27:16 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void		stt_user(char *per, t_elem *f)
{
	per[0] = (f->mode == 'f') ? '-' : f->mode;
	if (f->stt.st_mode & S_IRUSR)
		per[1] = 'r';
	else
		per[1] = '-';
	if (f->stt.st_mode & S_IWUSR)
		per[2] = 'w';
	else
		per[2] = '-';
	if (!(f->stt.st_mode & S_IXUSR) && (f->stt.st_mode & S_ISUID))
		per[3] = 'S';
	else if (f->stt.st_mode & S_IXUSR)
	{
		if (f->stt.st_mode & S_ISUID)
			per[3] = 's';
		else
			per[3] = 'x';
	}
	else
		per[3] = '-';
}

void		stt_group(struct stat stt, char *per)
{
	if (stt.st_mode & S_IRGRP)
		per[4] = 'r';
	else
		per[4] = '-';
	if (stt.st_mode & S_IWGRP)
		per[5] = 'w';
	else
		per[5] = '-';
	if (!(stt.st_mode & S_IXGRP) && (stt.st_mode & S_ISGID))
		per[6] = 'S';
	else if (stt.st_mode & S_IXGRP)
	{
		if (stt.st_mode & S_ISGID)
			per[6] = 's';
		else
			per[6] = 'x';
	}
	else
		per[6] = '-';
}

void		stt_other(struct stat stt, char *per)
{
	if (stt.st_mode & S_IROTH)
		per[7] = 'r';
	else
		per[7] = '-';
	if (stt.st_mode & S_IWOTH)
		per[8] = 'w';
	else
		per[8] = '-';
	if ((stt.st_mode & S_IXOTH) && (stt.st_mode & (S_ISVTX)))
		per[9] = 't';
	else if (stt.st_mode & S_IXOTH)
		per[9] = 'x';
	else if (stt.st_mode & S_ISVTX)
		per[9] = 'T';
	else
		per[9] = '-';
}

char		list_attribut(char *path, ssize_t attribut)
{
	int		i;
	acl_t	acl;

	i = 0;
	if ((acl = acl_get_file(path, ACL_TYPE_EXTENDED)))
		i = 1;
	acl_free((void *)acl);
	if (attribut > 0)
		return ('@');
	else if (i)
		return ('+');
	return (0);
}

void		permission_handler(t_elem *f, t_format format)
{
	char	per[12];

	per[11] = '\0';
	stt_user(per, f);
	stt_group(f->stt, per);
	stt_other(f->stt, per);
	per[10] = list_attribut(f->path, listxattr(f->path, NULL, 0, \
															XATTR_NOFOLLOW));
	ft_printf("%-11s %*lu %-*s%-*s", per, format.link, f->stt.st_nlink,
			format.uid + ((format.gid && format.uid) ? 2 : 0),
			f->name_user, format.gid + 2, f->name_group);
}
