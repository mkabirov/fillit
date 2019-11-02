# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 19:05:10 by mkabirov          #+#    #+#              #
#    Updated: 2019/10/11 22:24:02 by mkabirov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LNAM = libft.a

LIBF = ./includes/libft

INCL = ./includes/fillit.h

SRCS = ./src

CCFL = gcc -Wall -Wextra -Werror

GIT = "version control"

GREEN = \033[0;32m

all: $(NAME)

$(NAME):
	@make -C $(LIBF) re
	@$(CCFL) -L $(LIBF) -lft $(SRCS)/*.c -I $(LIBF) -I $(INCL) -o $(NAME)

clean:
	@make -C $(LIBF) clean

fclean: clean
	@make -C $(LIBF) fclean
	@/bin/rm -f $(NAME)

re: fclean all

git:
	@make fclean
	@git add .
	@git commit -m '$(GIT)'
	@git push
	printf "$(GREEN) ✔  %s\n\$(GREEN)" "Git pushed $(NAME)"

.PHONY: all clean fclean re
