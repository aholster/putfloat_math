# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: aholster <aholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/16 15:46:43 by aholster       #+#    #+#                 #
#    Updated: 2019/07/28 20:43:21 by aholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

DATE := $(shell date)

SOURCE := main longdouble_analyse ft_custom_ld_to_text ft_numlst_del ft_numlst_to_str\
 ft_numlst_new  ft_numlst_len ft_numlst_postfix ft_numlst_prefix\
 ft_lst_math_div ft_lst_math_mul ft_lst_math_pow ft_lst_math_add

FILEC := $(SOURCE:%=./%.c)

HEAD := float_tech.h

NAME := test

NORM := norminette $(FILEC) $(HEAD) | grep -e "Error"  -e "Warning" -B 1

CC := gcc -Wall -Werror -Wextra -g -I ./libft/ -L ./libft/ -lft

all: $(NAME)

assemble:
	@$(CC) -o $(NAME) $(FILEC)

$(NAME):
	@make -C ./libft/
	@echo "\033[0;33mStarting assembly of $(NAME)…\033[0;00m"
	@time make assemble
	@echo "\033[0;32m$(NAME) successfully assembled!\033[0;00m\n"

clean:
#	@make clean -C ./libft/
	@echo "\033[0;33mInitializing Summary Deletions...\033[0;00m"
	@find "./" -type f \( -name '*~' -o -name '\#*\#' -o -name '.DS_Store' \)\
	 -exec rm -rfv {} \;
	@echo "\033[0;31m	Executed!\033[0;00m\n"

fclean: clean
#	@make fclean -C ./libft/
	@rm -rf $(NAME)
	@echo "\033[0;31mObituary of $(NAME): Deceased on $(shell date).\
	\033[0;00m\n"

re: fclean all

norm:
	@echo "**+++=====*=====*=====*=====*{\033[0;31mOUT\033[0;00m}\
	*=====*=====*=====*=====+++**\033[0;33m"
	@$(NORM) || TRUE 
	@echo "\033[0;00m**+++=====*=====*=====*=====*\
=====*=====*===*=====*=====+++**"

add:
	@git add $(FILEC) $(HEAD) Makefile author
	git status

push: norm
ifdef MSG
	@git commit -m "$(MSG)"
	git push
else
	@git commit
	git push
endif