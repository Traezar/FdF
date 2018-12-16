# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 08:38:15 by rsathiad          #+#    #+#              #
#    Updated: 2018/12/01 16:51:07 by rsathiad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NC = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
CYAN = \033[1;36m
SUNFLOWER = \033[1;33m




NAME = libft.a

SRC = $(addprefix src/libft/, $(libftbasic)) \
				$(addprefix src/ft_printf/, $(printf))
OBJ = *.o
HDR = $(addprefix includes/, $(ft_printf.h)) \
			$(addprefix includes/, $(libft.h))


all: $(NAME)



libftbasic =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	   	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c \
		ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
		ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
		ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
		ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_itoabase.c \
		ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
		ft_setbit.c ft_clearbit.c ft_uintmaxtoa_base.c ft_subnjoin.c\
		ft_ltoa_base.c ft_lltoa_base.c ft_intmaxtoa_base.c ft_freeandretint.c \
		ft_freeandretstr.c ft_lstsplit.c ft_lstmergesort.c ft_free_dblarray.c\
		get_next_line.c ft_getarraylen.c ft_split_whitespace.c\
	  ft_split_args_in_line.c ft_char_subst.c ft_count_char.c ft_isinteger.c


printf =	ft_printf.c assembler.c conversion.c precisionandwidth.c \
		   applypnftypesone.c applypnftypestwo.c print_cs.c \
		   print_d.c print_o.c print_x.c misc_funcs.c

$(NAME):
			@gcc $(CFLAGS) $(SRC) -I includes/ $(HDR)
			@echo "\033[1;32m[Compiled]\033[0m: object files"
			@ar rc $(NAME) $(OBJ) $(HDR)
			@echo "\033[1;32m[Compiled]\033[0m: libft.a"
			@mkdir libft_object_files
			@mv $(OBJ) libft_object_files

clean:
	@rm -rf $(OBJ)
	@rm -rf libft_object_files
	@echo "\033[1;31m[Removed]\033[0m: object files"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[1;31m[Removed]\033[0m: libft.a"

re: fclean all

CFLAGS = -c  -Wall -Werror -Wextra

PHONY:
	clean fclean all re
