/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 20:44:01 by thninh            #+#    #+#             */
/*   Updated: 2017/07/21 12:52:41 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <wchar.h>
# include "libft.h"

# define BUFFSIZE			127

typedef struct				s_out
{
	int						len;
	int						stocked;
	char					out1[BUFFSIZE];
	char					*out;
}							t_out;

typedef struct				s_data
{
	int						d;
	unsigned int			u;
	unsigned long int		lu;
	unsigned long long int	llu;
	void					*p;
	long int				ld;
	wchar_t					lc;
	char					c;
	long long int			ll;
	unsigned char			uc;
	long double				f;
}							t_data;

typedef	struct				s_arg
{
	int						nul;
	char					type;
	char					format;
	char					modifier;
	int						pad;
	char					padchar;
	int						precision;
	int						len;
	int						padleft;
	int						hash;
	int						plus;
	int						space;
	int						wild;
	int						zero;
	int						sharp;
	int						unsign;
	struct s_data			data;
}							t_arg;

typedef struct				s_mylst
{
	int						i;
	void					*data;
	size_t					ldata;
	struct s_mylst			*next;
	struct s_mylst			*prev;
}							t_mylst;

t_mylst						*prt_list_at(t_mylst *lst, int i);
void						prt_ilist(t_mylst **lst);
t_arg						*prt_arg(void);
void						prt_ladd_back(t_mylst **list, t_mylst *add);
void						prt_alpha(t_out *output, t_out *tmp, t_arg *ele);
void						prt_asalpha(t_out *output, t_out *tmp, t_arg *ele);
int							prt_as_end(char **strp, t_out *out, t_arg **ele, \
																	va_list ap);
int							prt_dend(int fd, t_out *out, t_arg **ele, \
																	va_list ap);
void						prt_asprocess_format(t_out *output, t_arg *ele);
void						prt_aswide(t_out *output, t_out *tmp, t_arg *ele);
int							ft_asprintf(char **strp, const char *format, ...);
int							ft_dprintf(int fd, const char *format, ...);
void						prt_dprocess_format(t_out *output, t_arg *ele);
void						prt_wild(const char *str, int i, t_arg *ele, \
																	va_list ap);
int							prt_precision(t_arg *ele, int i, const char *str);
void						prt_flags_num(t_out *output, t_arg *ele);
void						prt_format_u1(va_list ap, t_arg *ele);
void						prt_format_alpha1(va_list ap, t_arg *ele);
void						prt_format1(t_arg *ele, va_list ap);
t_arg						*prt_print(t_out *out, const char **str, \
																	va_list ap);
void						prt_free_ele(t_arg **arg);
void						prt_init_out(t_out *out);
void						prt_free_out(t_out *out);
char						*prt_init_base(char type, size_t *base);
void						prt_nonspec(t_out *output, t_out *tmp, t_arg *ele);
void						prt_point_b1(t_out *output, t_arg *ele, \
													t_out *tmp, t_out *flag);
void						prt_point(unsigned long int nb, t_out *output, \
														t_out *tmp, t_arg *ele);
void						prt_itoa_base1(unsigned long int nb, t_arg *ele, \
																	t_out *tmp);
void						prt_percent(t_out *output, t_out *tmp, t_arg *ele);
void						prt_find_typea(t_arg *ele, const char *str, int i);
int							prt_find_typeb(const char *str, t_arg *ele, \
																	va_list ap);
t_arg						*prt_find_modif(const char **str, va_list ap);
void						prt_num_modif1(t_arg *ele);
void						prt_modifier(t_arg *ele);
void						prt_prec_num1(t_arg *ele, t_out *tmp, t_out *flag);
void						prt_make_num1(t_arg *ele, t_out *tmp, t_out *flag, \
																t_out *out);
void						prt_float(t_out *output, t_out *tmp, t_arg *ele);
void						prt_num(t_out *output, t_out *tmp, t_arg *ele);
void						prt_fill_out(t_out *out, const char *format, \
																	int len);
void						*prt_realloc(void *ptr, size_t size, \
															size_t old_size);
void						prt_join_before(t_out *out, const char *s, int len);
int							prt_find_pad(t_arg *ele, int i, const char *str);
void						prt_pad(t_out *output, char *flag, t_arg *ele);
int							prt_widesize1(wchar_t c);
void						prt_bit_mask1(int decalage, wchar_t c, char *ch, \
																size_t size);
void						prt_putwide1(t_out *output, wchar_t c, \
													size_t size, int decalage);
void						prt_print_wide(t_out *tmp, t_arg *ele, \
														wchar_t **ls, int *put);
void						prt_wide(t_out *output, t_out *tmp, t_arg *ele);
int							prt_wide_slen(const wchar_t *s);
void						prt_dtoa(double n, int prec, t_arg *ele, \
																	t_out *tmp);
void						prt_itoa1(long long int n, t_arg *ele, t_out *tmp);
double						prt_pow(double pow, int nb);
void						prt_ladd_back(t_mylst **list, t_mylst *add);
t_mylst						*prt_mylstnew(void *data, size_t ldata);
int							ft_printf(const char *format, ...);

#endif
