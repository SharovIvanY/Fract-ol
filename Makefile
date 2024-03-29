# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 15:39:39 by amace-ty          #+#    #+#              #
#    Updated: 2019/10/13 15:53:06 by amace-ty         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

INC_DIR		=	./inc
LIB_DIR		=	./lib
SRC_DIR		=	./src
OBJ_DIR		=	./obj

INC_DIRS	=	$(shell find . | grep '\.h' | sed "s/\(.*\)\/.*/\1/" | sort -u)
LIB_DIRS	=	$(shell find . -mindepth 2 -maxdepth 2 | grep "lib")
LIB_SRCS	=	$(shell find . | grep "\.a" | awk -F / '{printf " " substr($$NF, 4, length($$NF) - 5)}')

SRC			=	$(shell ls $(SRC_DIR))
OBJ			=	$(SRC:.c=.o)

OBJS		=	$(addprefix $(OBJ_DIR)/, $(OBJ))
INCS		=	$(shell $(foreach dir,$(INC_DIRS),echo "-I$(dir)";))
LIBS_DIRS	=	$(shell $(foreach dir,$(LIB_DIRS),echo "-L$(dir)";))
LIBS_SRCS	=	$(shell $(foreach src,$(LIB_SRCS),echo "-l$(src)";))

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all: lall
	@echo $(LIB_SRCS)
	@echo "\033[36m\033[1m$(NAME) - all:\033[0m"
	@$(MAKE) $(NAME)

$(NAME): $(OBJ_DIR)
	@echo "\033[32m\033[1m$(NAME) - compile executable:\033[0m"
	$(CC) $(CFLAGS) $(OBJS) $(INCS) $(LIBS_DIRS) $(LIBS_SRCS) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJ_DIR):
	@echo "\033[32m\033[1m$(NAME) - create obj directory:\033[0m"
	mkdir -p $(OBJ_DIR)
	@echo "\033[32m\033[1m$(NAME) - compile sources:\033[0m"
	@$(MAKE) $(OBJS)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

oclean:
	@echo "\033[32m\033[1m$(NAME) - remove obj directory:\033[0m"
	rm -rf $(OBJ_DIR)

clean:
	@echo "\033[36m\033[1m$(NAME) - clean:\033[0m"
	@$(MAKE) lclean
	@$(MAKE) oclean

fclean:
	@echo "\033[36m\033[1m$(NAME) - fclean:\033[0m"
	@$(MAKE) lfclean
	@$(MAKE) oclean
	rm -f $(NAME)

re:
	@echo "\033[36m\033[1m$(NAME) - re:\033[0m"
	@$(MAKE) fclean
	@$(MAKE) all

lall:
	@$(foreach lib,$(LIB_DIRS),echo "\033[91m\033[1m--->$(lib) all:\033[0m";make -C $(lib) all;)

lclean:
	@$(foreach lib,$(LIB_DIRS),echo "\033[91m\033[1m--->$(lib) clean:\033[0m";make -C $(lib) clean;)

lfclean:
	@$(foreach lib,$(LIB_DIRS),echo "\033[91m\033[1m--->$(lib) fclean:\033[0m";make -C $(lib) fclean;)

.PHONY: all clean fclean re lall lclean lfclean lre
