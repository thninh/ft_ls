# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thninh <thninh@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/11 16:50:13 by thninh            #+#    #+#              #
#    Updated: 2017/07/18 08:09:32 by thninh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = ./libft.h ./get_next_line.h ./ft_printf.h

SRC = ./ft_atoi.c ./ft_bzero.c ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c \
	  ./ft_isdigit.c ./ft_isprint.c ./ft_itoa.c ./ft_memalloc.c \
	  ./ft_memccpy.c ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memdel.c \
	  ./ft_memmove.c ./ft_memset.c ./ft_putchar.c ./ft_putchar_fd.c \
	  ./ft_putendl.c ./ft_putendl_fd.c ./ft_putnbr.c ./ft_putnbr_fd.c \
	  ./ft_putstr.c ./ft_putstr_fd.c ./ft_strlcat.c ./ft_strcat.c \
	  ./ft_strchr.c ./ft_strclr.c ./ft_strcmp.c ./ft_striteri.c \
	  ./ft_strequ.c ./ft_strmapi.c ./ft_strnequ.c ./ft_strnew.c \
	  ./ft_strnstr.c ./ft_strncmp.c ./ft_strncat.c ./ft_strsplit.c \
	  ./ft_strrchr.c ./ft_strsub.c ./ft_strcpy.c ./ft_toupper.c \
	  ./ft_tolower.c ./ft_strtrim.c ./ft_strstr.c ./ft_strmap.c \
	  ./ft_strncpy.c ./ft_strjoin.c ./ft_strlen.c ./ft_striter.c \
	  ./ft_strdup.c ./ft_strdel.c ./ft_lstadd.c ./ft_lstdel.c \
	  ./ft_lstdelone.c ./ft_lstiter.c ./ft_lstmap.c ./ft_lstnew.c \
	  ./ft_strrev.c ./ft_swap.c ./ft_max.c ./ft_swap_bits.c \
	  ./ft_list_size.c ./ft_strjoin_free.c \
	  ./get_next_line.c ./ft_isprint_char.c ./ft_isprint_charact.c \
	  ./ft_strndup.c ./ft_strlen_i.c ./ft_char_in_arg.c \
	  ./ft_sorter_comparator.c ./ft_asprintf.c ./ft_dprint.c \
		./ft_printf.c ./prt_alpha.c ./prt_arg.c ./prt_as_end.c \
		./prt_as_end.c ./prt_asalpha.c ./prt_asprocess_format.c \
		./prt_aswide.c ./prt_bit_mask1.c ./prt_dend.c ./prt_dtoa.c \
		./prt_fill_out.c ./prt_find_modif.c ./prt_find_pad.c \
		./prt_find_typea.c ./prt_find_typeb.c ./prt_flags_num.c \
		./prt_float.c ./prt_format_alpha1.c ./prt_format_u1.c \
		./prt_format1.c ./prt_free_ele.c ./prt_free_out.c \
		./prt_init_base.c ./prt_init_out.c ./prt_itoa_base1.c \
		./prt_join_before.c ./prt_make_num1.c ./prt_modifier.c \
		./prt_nonspec.c ./prt_num_modif1.c ./prt_num.c ./prt_pad.c \
		./prt_percent.c ./prt_point.c ./prt_prec_num1.c ./prt_precision.c \
		./prt_print_wide.c ./prt_print.c ./prt_putwide1.c ./prt_realloc.c \
		./prt_wide_slen.c ./prt_wide.c ./prt_widesize1.c ./prt_wild.c \
		./prt_dprocess_format.c ./prt_point_b1.c ./prt_ladd_back.c \
		./prt_mylstnew.c ./ft_len_grid.c ./prt_itoa1.c ./prt_pow.c \
		./prt_list_at.c ./prt_ilist.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\\033[1;34m [ ✔︎ ] Create libft\\033[0;39m"

%.o : %.c
	@gcc -Wall -Werror -Wextra -I. -c $<
	@printf '\033[34m [ ✔︎ ] %s\n\033[0m' "$<"

clean:
	@/bin/rm -rf $(OBJ)
	@/bin/rm -f libft.h.gch

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean
