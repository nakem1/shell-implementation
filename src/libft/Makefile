
FLAGS = -g3 -Wall -Werror -Wextra -I. -c

LIB = ar rcs

NAME = libft.a

HEADER = libft.h

SRC = ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_calloc.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_split.c \
	ft_itoa.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putnbr_fd.c \
	ft_isascii.c  \
	ft_isprint.c \
	ft_strmapi.c \
	ft_putendl_fd.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_memmove.c \
	ft_strcmp.c \
	ft_strlen_int.c \
	get_next_line.c \
	only_digits_comma.c \
	only_digits_ln.c \
	get_stack.c \
	str_isdigits.c \
	ft_list_push_back.c \
	ft_create_elem.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstclear.c \
	ft_lstmap.c \
	ft_atoi_long.c \
	ft_list_size.c \
	ft_list_at.c \
	ft_list_clear.c \
	ft_strindx.c \
	ft_putchar.c \
	ft_list_last_content.c \
	ft_list_push_front.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(LIB) $(NAME) $(OBJ)

$(OBJ): $(SRC)
	@gcc $(FLAGS) $(SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
