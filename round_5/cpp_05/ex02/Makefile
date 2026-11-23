# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhoogend <rhoogend@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/24 13:46:52 by rhoogend          #+#    #+#              #
#    Updated: 2026/06/12 12:26:37 by rhoogend         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Form2b
CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Bureaucrat.cpp main.cpp AForm.cpp PresidentialPardonForm.cpp \
RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re