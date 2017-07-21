# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thninh <thninh@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/22 12:06:38 by thninh            #+#    #+#              #
#    Updated: 2017/07/21 16:16:18 by thninh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

LDFLAGS = -I./include/
CFLAGS = -Wall -Wextra -Werror

SRC = ./dirs_manage.c ./display_manage.c error_display.c files_manage.c \
	  ./free_manage.c ./ft_ls.c ./init_manage.c ./option_handler.c \
	  ./permission_handler.c ./format_manage.c ./display_info_elem.c \
	  ./display_column.c ./check_param.c ./listing_file.c ./create_new_elem.c

OBJ = $(SRC:.c=.o)
	SRCDIR = ./src/
	OBJDIR = ./obj/
	INCDIR = ./include/
	SRCS = $(addprefix $(SRCDIR), $(SRC))
	OBJS = $(addprefix $(OBJDIR), $(OBJ))
	INCS = $(addprefix $(INCDIR), $(INC))

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	@gcc $(CFLAGS) -o $@ $^ -L./libft/ -lft
	@echo "\\033[1;32m [ ✔︎ ] Success. \\033[0;39m"

$(OBJS) : $(SRCS)
	@make -C libft/
	@echo "\\033[1;34m [ ✔︎ ] Generated objects.\\033[0;39m"
	@gcc $(CFLAGS) -c $(SRCS) $(LDFLAGS)
	@mkdir -p $(OBJDIR)
	@mv $(OBJ) $(OBJDIR)

clean:
	@make -C libft/ clean
	@echo "\\033[1;34m [ ✔︎ ] Deleted objects.\\033[0;39m"
	@/bin/rm -f $(OBJS)
	@/bin/rm -Rf $(OBJDIR)

fclean: clean
	@make -C libft/ fclean
	@echo "\\033[1;34m [ ✔︎ ] Deleted $(NAME).\\033[0;39m"
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: fclean re
