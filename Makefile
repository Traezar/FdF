# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/16 02:32:39 by rsathiad          #+#    #+#              #
#    Updated: 2018/12/16 02:33:31 by rsathiad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = *.o

fdfSRC = 
			 check/shared_util.c check/stdout_msg.c

fdfHDR = includes

all: LIBFT fdf

fdf:
	@gcc -o push_swap $(CFLAGS) $(fdfSRC) -I $(fdfHDR) -L libft -lft -g
	@echo "\033[1;32m[Compiled]\033[0m: \033[1;36m./pushswap\033[0m"

LIBFT :
	@cd libft && make


clean:
	@rm -rf $(OBJ)
	@echo "\033[1;31m[Removed]\033[0m: checker object files"

fclean: clean
	@clear
	@rm -rf fdf
	@cd libft && make fclean

re: fclean all

CFLAGS = -Wall -Werror -Wextra

PHONY:
	clean fclean all re
