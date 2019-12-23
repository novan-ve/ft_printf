# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: novan-ve <novan-ve@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/20 14:11:17 by novan-ve       #+#    #+#                 #
#    Updated: 2019/12/20 17:37:05 by novan-ve      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra libft/libft.h -c

SRCS = ft_printf.c \
		ft_printi.c \
		ft_printp.c \
		ft_prints.c \
		ft_printu.c \
		ft_printx.c \
		ft_printc.c \
		ft_putprec_fd.c \
		ft_uputnbr_fd.c \
		ft_calcwidth.c \
		ft_dec_to_hex.c \
		ft_format.c \
		ft_nbrleni.c \
		ft_nbrlenu.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(SRCS) ft_printf.h
	make -C libft
	cp libft/libft.a .
	mv libft.a $(NAME)
	clang $(FLAGS) $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
