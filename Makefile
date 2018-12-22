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

fdfSRC = fdf.c

fdfHDR = includes/fdf.h

all:  LIBFT fdf

fdf:
	@gcc -o push_swap $(CFLAGS) $(fdfSRC) -I $(fdfHDR) -lmlx  -lXext -lX11  -lft -L libft -L minilibx -L /usr/X11/lib
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
