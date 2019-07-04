# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viclucas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 10:53:53 by viclucas          #+#    #+#              #
#    Updated: 2019/06/25 02:30:38 by viclucas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean all fclean re

NAME = libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror -I$(INC_PATH)

SRC_PATH = ./src/
SRCS = $(addprefix $(SRC_PATH), $(SRC))
SRC = ft_atoi.c ft_isascii.c ft_memcpy.c ft_strcmp.c ft_strlen.c ft_strnstr.c \
	ft_toupper.c ft_bzero.c ft_isdigit.c ft_memset.c ft_strcpy.c ft_strncat.c \
	ft_strrchr.c ft_isalnum.c ft_isprint.c ft_strcat.c ft_strdup.c \
	ft_strncmp.c ft_strstr.c ft_isalpha.c ft_memccpy.c ft_strchr.c \
	ft_strlcat.c ft_strncpy.c ft_tolower.c ft_memmove.c ft_memchr.c \
	ft_memcmp.c ft_itoa.c ft_memdel.c ft_putstr.c ft_strnew.c ft_memalloc.c \
	ft_putchar.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	ft_strmap.c ft_strequ.c ft_strmapi.c ft_strnequ.c ft_strjoin.c ft_strsub.c \
	ft_strtrim.c ft_strsplit.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
	ft_putnbr.c ft_putstr_fd.c ft_putnbr_fd.c ft_strcapitalize.c ft_any.c \
	ft_is_sort.c print_db.c ft_concat_params.c ft_lstnew.c \
	ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_lstadd.c ft_lstmap.c \
	get_next_line.c ft_printf.c ft_lst_pack.c ft_sous_d.c ft_cpy_db_tab.c\
	ft_free_db_tab.c ft_check_str.c ft_souder.c ft_lstnew1.c ft_strndup.c \
	ft_strdup1.c ft_putnbrl.c ft_putnbr_size_t.c show_alloc_mem_lib.c hexa_for.c \

OBJ_PATH = ./obj/
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
OBJ = $(SRC:.c=.o)

INC_PATH = ./includes/
INCS = $(addprefix $(INC_PATH), $(INC))
INC = libft.h

all : $(NAME)

$(NAME): $(OBJ_PATH) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INCS)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME) 

re: fclean all
