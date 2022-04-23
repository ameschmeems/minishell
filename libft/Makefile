# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/30 00:07:43 by aionescu          #+#    #+#              #
#    Updated: 2021/06/05 23:30:32 by aionescu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
		ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
		ft_substr.c ft_tolower.c ft_toupper.c
BON = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstiter.c ft_lstmap.c

all: $(NAME)

$(NAME): clean
	$(CC) -c -Wall -Wextra -Werror $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)
	rm -f *.o

bonus: clean
	$(CC) -c -Wall -Wextra -Werror $(BON)
	ar rc $(NAME) *.o
	ranlib $(NAME)
	rm -f *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all bonus clean fclean re
