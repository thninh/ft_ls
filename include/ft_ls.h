/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 00:50:28 by thninh            #+#    #+#             */
/*   Updated: 2017/07/22 13:35:28 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/errno.h>
# include <sys/acl.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

# define CHECK(x) if(!x) exit(1)

# define MAJOR ft_len_grid(major(((t_elem *)l->data)->stt.st_rdev))
# define MINOR ft_len_grid(minor(((t_elem *)l->data)->stt.st_rdev))

typedef struct s_mylst	t_ls;

typedef struct			s_format
{
	size_t				uid;
	size_t				gid;
	size_t				name;
	size_t				link;
	size_t				minor;
	size_t				major;
	long long			cnt_blk;
}						t_format;

typedef struct			s_opt
{
	int					up_c1;
	int					up_c2;
	int					up_f;
	int					up_r;
	int					up_s;
	int					up_time;
	int					up_u;
	int					a_f;
	int					a_h;
	int					c;
	int					f;
	int					g;
	int					l;
	int					m;
	int					n;
	int					o;
	int					r;
	int					t;
	int					u;
	int					x;
	int					one;
	int					up_f_or_p;
}						t_opt;

typedef struct			s_elem
{
	char				*name;
	char				*path;
	char				*name_group;
	char				*name_user;
	char				mode;
	char				s_mode;
	size_t				lname;
	size_t				luid;
	size_t				lgid;
	size_t				lpath;
	struct stat			stt;
}						t_elem;

void					init_op(t_opt *opt);
void					init_elem(t_elem *new_elem);
void					init_format(t_format *format);
void					error_display(char err_op);
char					check_mode_elem(struct stat stt);
int						check_param(t_opt *opt, int ac, char **av);
void					op_funct(char c, t_opt *opt);
void 					op_funct_1s(char c, t_opt *opt);
void					listing_file(t_ls **begin, t_ls *lnew, t_opt opt);
t_ls					*files_manage(t_ls *lst, int ac, char **av, t_opt opt);
void					display_manage(t_ls *lst, t_opt *opt, int x);
void					permission_handler(t_elem *f, t_format format);
void					display_info_elem(t_ls *lst, t_opt *opt);
void					format_manage(t_ls *l, t_format *format);
void					display_info_elem(t_ls *lst, t_opt *opt);
void					display_column(struct winsize ws, t_ls *lst, t_opt *opt);
void					dirs_manage(int ac, char **av, t_opt opt, int x);
void					free_manage(t_ls **lst);
void					sort_list_elem(t_ls **begin, t_opt opt);
void					ft_readlist(t_ls *lst, t_opt opt);
t_elem					*create_new_elem(char *name, char *path, t_opt *opt);
char					check_mode_elem(struct stat stt);
void					option_manage(t_elem *f, t_opt *opt);

#endif
