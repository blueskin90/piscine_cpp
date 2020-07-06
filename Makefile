# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toliver <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/20 19:50:33 by toliver           #+#    #+#              #
#    Updated: 2020/07/06 17:48:05 by toliver          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= clang++

NAME = megaphone

INCLUDES = -I 

FLAGS = -Wall -Wextra -Werror -g3

OBJS = $(addsuffix .o, \
			megaphone \
		)

HEADERS =

all: $(NAME) 

$(NAME): objs $(OBJS) $(HEADERS)
	@printf "\033[92m\033[1:32mCompiling -------------> \033[91m$(NAME)\033[0m:\033[0m%-16s\033[32m[✔]\033[0m\n"
	@$(CC) $(OBJS) $(FLAGS) -o $(NAME) #ne pas oublier de check la dependance

objs/%.o: srcs/%.cpp
	@printf  "\033[1:92mCompiling $(NAME)\033[0m %-31s\033[32m[$<]\033[0m\n" ""
	@$(CC) -o $@ -c $< $(FLAGS) -fPIC $(INCLUDES)
	@printf "\033[A\033[2K"

objs:
	@mkdir -p objs/core
	@mkdir -p objs/utils

clean:
	@printf  "\033[1:32mCleaning object files -> \033[91m$(NAME)\033[0m\033[1:32m:\033[0m%-16s\033[32m[✔]\033[0m\n"
	@rm -rf objs

fclean: clean
	@printf  "\033[1:32mCleaning binary -------> \033[91m$(NAME)\033[0m\033[1:32m:\033[0m%-16s\033[32m[✔]\033[0m\n"
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)
