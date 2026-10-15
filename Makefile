LIB = libft.a
FLAGS = -Wall -Wextra -Werror -I ./level0
CC = cc
AR = ar rcs
RM = rm -f

FIlES = level1/ft_isalnum level1/ft_isalpha level1/ft_isascii level1/ft_isdigit level1/ft_isprint \
		level2/ft_bzero level2/ft_memset level2/ft_strlen \
		level3/ft_memcpy \
		level4/ft_memchr level4/ft_memcmp \
		level5/ft_strchr level5/ft_strncmp level5/ft_strnstr level5/ft_strrchr \
		level7/ft_atoi level7/ft_tolower level7/ft_toupper \
		level8/ft_calloc level8/ft_strdup \
		level9/ft_strjoin level9/ft_strtrim level9/ft_substr level9/ft_itoa \
		level10/ft_putchar_fd level10/ft_putnbr_fd level10/ft_putendl_fd level10/ft_putstr_fd \
			level10/ft_striteri level10/ft_strmapi 

OBJ = $(FIlES:=.o)

.PHONY : all clean fclean re 

all : $(LIB)
$(LIB) : $(OBJ)
	$(AR) $(LIB) $(OBJ)
%.o:%.c 
	$(CC) $(FLAGS) -c $< -o $@
	
clean : 
	$(RM) $(OBJ)
fclean : clean
	$(RM) $(LIB)

re: fclean all



