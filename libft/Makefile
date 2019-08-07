# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 15:01:00 by spuisais          #+#    #+#              #
#    Updated: 2019/07/22 15:44:59 by spuisais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
CC                      = gcc
NAME            = libft.a
CFLAGS          = -Wextra -Werror -Wall
OBJDIR          = ./objs/
SRCDIR          = ./srcs/
HDRDIR          = ./includes/
RED                     = \033[1;31m
CYAN            = \033[1;36m
GREEN           = \033[1;32m
NO_COLOR        = \033[0m

SRCS    =       ft_memset.c             \
						ft_bzero.c              \
						ft_memcpy.c             \
						ft_memccpy.c            \
						ft_memmove.c            \
						ft_memchr.c             \
						ft_memcmp.c             \
						ft_strlen.c             \
						ft_strdup.c             \
						ft_strcpy.c             \
						ft_strncpy.c            \
						ft_strcat.c             \
						ft_strncat.c            \
						ft_strlcat.c            \
						ft_strchr.c             \
						ft_strrchr.c            \
						ft_strstr.c             \
						ft_strnstr.c            \
						ft_strcmp.c             \
						ft_strncmp.c            \
						ft_atoi.c               \
						ft_isalpha.c            \
						ft_isdigit.c            \
						ft_isalnum.c            \
						ft_isascii.c            \
						ft_isprint.c            \
						ft_toupper.c            \
						ft_tolower.c            \
						ft_memalloc.c   \
						ft_memdel.c             \
						ft_strnew.c             \
						ft_strdel.c             \
						ft_strclr.c             \
						ft_striter.c            \
						ft_striteri.c   \
						ft_strmap.c             \
						ft_strmapi.c            \
						ft_strequ.c             \
						ft_strnequ.c            \
						ft_strsub.c             \
						ft_strjoin.c            \
						ft_strjoinf.c           \
						ft_strtrim.c            \
						ft_strsplit.c   \
						ft_itoa.c               \
						ft_putchar.c            \
						ft_putstr.c             \
						ft_putendl.c            \
						ft_putnbr.c             \
						ft_putchar_fd.c \
						ft_putstr_fd.c  \
						ft_putendl_fd.c \
						ft_putnbr_fd.c  \
						ft_lstnew.c             \
						ft_lstdelone.c  \
						ft_lstdel.c             \
						ft_lstadd.c             \
						ft_lstiter.c            \
						ft_lstmap.c             \
						ft_print_words_table.c \
						ft_print_num_table.c \
						get_next_line.c \
						high_sqrt.c

SRCFILES = $(addprefix $(SRCDIR), $(SRCS))
OBJFILES = $(addprefix $(OBJDIR),$(OBJ))
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c Makefile
			mkdir -p objs/
			$(CC) $(CFLAGS) -o $@ -c $< -I $(HDRDIR)
			echo "$(CYAN)Compiling:\t\t$(GREEN)$<$(NO_COLOR)"

$(NAME): $(OBJFILES)
				ar rc $(NAME) $(OBJFILES)
				ranlib $(NAME)
				echo "$(CYAN)Library:\t\t$(GREEN)[Done]$(NO_COLOR)"

clean:
				$(RM) -rf $(OBJDIR)
				echo "$(RED)Deleted:\t\tall object files$(NO_COLOR)"

fclean: clean
				$(RM) $(NAME)
				echo "$(RED)Deleted:\t\t$(NAME)$(NO_COLOR)"

re: fclean all
.PHONY: all clean fclean