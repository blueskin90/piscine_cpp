# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toliver <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/20 19:50:33 by toliver           #+#    #+#              #
#    Updated: 2021/07/17 19:21:10 by toliver          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= clang++

NAME = ex04

INCLUDES = -I ./includes/. 

FLAGS = -Wall -Wextra -Werror -Wno-conversion -std=c++98

OBJS = $(addprefix objs/, $(addsuffix .o, \
				main \
				Token \
				NumToken \
				OpToken \
				ParCloseToken \
				ParOpenToken \
				utils	\
				parsing \
				print	\
				convert \
		)) 

all: $(NAME) 


$(NAME): objs $(OBJS)
	@printf "\033[92m\033[1:32mCompiling -------------> \033[91m$(NAME)\033[0m:\033[0m%-16s\033[32m[✔]\033[0m\n"
	@$(CC) $(OBJS) $(FLAGS) -o $(NAME)

objs/%.o: srcs/%.cpp
	@printf  "\033[1:92mCompiling $(NAME)\033[0m %-31s\033[32m[$<]\033[0m\n" ""
	@$(CC) -o $@ -c $< $(FLAGS) -fPIC $(INCLUDES)
	@printf "\033[A\033[2K"

objs:
	@mkdir -p objs/

clean:
	@printf  "\033[1:32mCleaning object files -> \033[91m$(NAME)\033[0m\033[1:32m:\033[0m%-16s\033[32m[✔]\033[0m\n"
	@rm -rf objs

fclean: clean
	@printf  "\033[1:32mCleaning binary -------> \033[91m$(NAME)\033[0m\033[1:32m:\033[0m%-16s\033[32m[✔]\033[0m\n"
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)
