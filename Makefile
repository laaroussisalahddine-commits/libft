LIB = libft.a
FLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar rcs
RM = rm -f

FILES = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_bzero.c ft_memset.c ft_strlen.c \
		ft_memcpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c \
		ft_strchr.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_strlcpy.c ft_strlcat.c \
		ft_atoi.c ft_tolower.c ft_toupper.c \
		ft_calloc.c ft_strdup.c \
		ft_strjoin.c ft_strtrim.c ft_substr.c ft_itoa.c ft_split.c \
		ft_putchar_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c \
		ft_striteri.c ft_strmapi.c \
		ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJ = $(FILES:.c=.o)

.PHONY : all clean fclean re 

all : $(LIB)

$(LIB) : $(OBJ)
	$(AR) $(LIB) $(OBJ)

%.o:%.c libft.h
	$(CC) $(FLAGS) -c $< -o $@
	
clean : 
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(LIB)

re: fclean all