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
	$(SRCDIR)/get_next_line/get_next_line.c \
	$(SRCDIR)/utils/utils.c

OBJ			:= $(SRC_MAIN:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: $(NAME) test/main.c
	$(CC) $(CFLAGS) test/main.c -I$(INCDIR) -L. -lgetnextline -o test_gnl && ./test_gnl


.PHONY: all clean fclean re test
