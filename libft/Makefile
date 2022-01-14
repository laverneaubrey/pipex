NAME = libft.a

SRC =   ft_isalpha.c    ft_isdigit.c    ft_isalnum.c    ft_isascii.c \
        ft_isprint.c    ft_toupper.c    ft_tolower.c    ft_memset.c \
        ft_memcpy.c     ft_memccpy.c    ft_memmove.c    ft_memchr.c \
        ft_memcmp.c     ft_strncmp.c    ft_strnstr.c    ft_strlen.c \
        ft_strlcpy.c    ft_strchr.c     ft_strrchr.c    ft_strnstr.c \
        ft_strlcat.c    ft_strdup.c     ft_bzero.c      ft_atoi.c \
        ft_calloc.c     ft_substr.c     ft_strjoin.c    ft_strtrim.c \
        ft_strmapi.c    ft_putchar_fd.c ft_putstr_fd.c  ft_putendl_fd.c \
        ft_putnbr_fd.c  ft_itoa.c       ft_split.c      libft.h

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

DEL = rm

all		: $(NAME)


$(NAME)	: $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o : %.c libft.h
	gcc $(FLAG) -c $< -o $@

clean   :
	$(RM)    *.o

fclean	:	clean
	$(RM) $(NAME)

re	    :	fclean all

.PHONY	:	all clean fclean re
