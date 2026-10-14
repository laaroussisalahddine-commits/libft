#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//------part 1-----:
// caracter clasification : 
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);

// string lenght and memory :
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);

// copying and moving memory :
void	*ft_memcpy(void *dst, const void *src, size_t n);

// copying and serching memory :
void	*ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);

// string searching and comparion :
char *ft_strrchr(const char *s, int c);
char *ft_strchr(const char *s, int c);
int strncmp(const char *s1, const char *s2, size_t n);
char *ft_strnstr(const char *haystack, const char *needle, size_t len);

// bonded string :

// case conversion and integer parsim :
int ft_tolower(int c);
int ft_tolower(int c);
int ft_atoi(const char *str);

// dynamique allocation :
void *ft_calloc(size_t nmemb, size_t size);
char *ft_strdup(const char *s);

//---------parte 2-----:
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strtrim(char const *s1, char const *set);

#endif 