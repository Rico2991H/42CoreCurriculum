# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/26 09:15:00 by rhoogend          #+#    #+#              #
#    Updated: 2026/02/17 12:02:14 by rhoogend         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

CC = cc
CFLAGS = -Wall -Wextra -Werror


SRC = main.c making_philosophers.c helpers.c threading.c eatsleepraverepeat.c checkers.c printaction.c
OBJDIR = objects
OBJ = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

INCLUDES = -I .

all: $(NAME)
	
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ)
	
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

