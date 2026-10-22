LIB = libft.a
FLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar rcs
RM = rm -f

FIlES = ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint \
		ft_bzero ft_memset ft_strlen \
		ft_memcpy ft_memmove \
		ft_memchr ft_memcmp \
		ft_strchr ft_strncmp ft_strnstr ft_strrchr \
		ft_strlcpy ft_strlcat \
		ft_atoi ft_tolower ft_toupper \
		ft_calloc ft_strdup \
		ft_strjoin ft_strtrim ft_substr ft_itoa ft_split \
		ft_putchar_fd ft_putnbr_fd ft_putendl_fd ft_putstr_fd \
		ft_striteri ft_strmapi \
		ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone \
		ft_lstiter ft_lstlast ft_lstmap ft_lstnew ft_lstsize

OBJ = $(FIlES:=.o)

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
