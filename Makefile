# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xirib <xirib@student.42.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/04 00:00:00 by xirib             #+#    #+#              #
#    Updated: 2025/09/04 00:00:00 by xirib            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libgetnextline.a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
AR			:= ar
ARFLAGS		:= rcs
RM			:= rm -f

INCDIR		:= include
SRCDIR		:= src

SRC_MAIN	:= \
	$(SRCDIR)/gnl/get_next_line.c \
	$(SRCDIR)/utils/utils.c \
	$(SRCDIR)/utils/list_utils.c \

OBJ			:= $(SRC_MAIN:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

test: $(NAME) test/main.c
	$(CC) $(CFLAGS) test/main.c -L. -I$(INCDIR) -lgetnextline -o test/test_exec

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

run_test: test
	./test/test_exec

re: fclean all

.PHONY: all clean fclean re test
