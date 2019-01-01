# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/16 02:32:39 by rsathiad          #+#    #+#              #
#    Updated: 2018/12/28 12:10:43 by rsathiad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = *.o

fdfSRC = src/fdf.c src/line.c src/map_builder.c src/builder_util.c

fdfHDR = includes/fdf.h

all:  LIBFT fdf

fdf:
	@gcc -o fdf $(CFLAGS) $(fdfSRC) -I $(fdfHDR) -lmlx -framework OpenGL -framework AppKit  -lft -L libft -L minilibx_macos -g
	@echo "\033[1;32m[Compiled]\033[0m: \033[1;36m./fdf\033[0m"

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
