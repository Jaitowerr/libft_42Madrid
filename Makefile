# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/26 12:17:33 by aitorres          #+#    #+#              #
#    Updated: 2026/01/29 15:30:49 by aitorres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRC		=	ft_atoi.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmapi.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strtrim.c\
			ft_striteri.c\
			ft_substr.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c

OBJ		=	$(SRC:.c=.o)

AR		=	ar rcs
CC		=	cc
FLAGS	=	-Wall -Werror -Wextra

all:		$(NAME)	#crea la librería con todos los objetos (incluyendo listas)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@echo "$(NAME) creado."

%.o:		%.c	#para compilar cualquier .c a .o
			@$(CC) $(FLAGS) -c $< -o $@

clean:		
			@rm -f $(OBJ)
			@echo "Objetos eliminados."
			
fclean:		clean
			@rm -f $(NAME)
			@echo "Librería eliminada."

re:			fclean	all	#recompila desde cero

# make        # Compila todo
# make clean  # Borra objetos
# make fclean # Borra objetos y librería
# make re     # Limpia y recompila