# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbehr <lbehr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 12:22:14 by lbehr             #+#    #+#              #
#    Updated: 2024/08/01 14:09:08 by lbehr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= a.out
OBJ_DIR	:= obj
SRCS	:= main.cpp
#ls *.cpp | tr "\n" " " | sed 's/\s$//' | xclip -selection clipboard
OBJS	:= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
DEPS	:= $(OBJS:.o=.d)
CC		:= c++
CFLAGS	:= -Wall -Werror -Wextra -std=c++98 -g3
RM		:= rm -rf
DIR_DUP	= mkdir -p $(@D)

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	$(DIR_DUP)
	$(CC) -c $< $(CFLAGS) -MMD -MP -o $@

-include $(DEPS)

clean	:
	rm -rf $(OBJ_DIR)

fclean	:	clean
	$(RM) $(NAME)

re		:	clean all

.PHONY: all clean re