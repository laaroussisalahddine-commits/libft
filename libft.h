#ifndef LIBFT_H
# define LIBFT_H

#include<string.h>
#include<unistd.h>
#include<stdlib.h>

//part_1:
int ft_atoi(const char *str);
void ft_bzero(void *s, size_t n);
int ft_isalnum(int c);
int ft_isalpha(int c);
int ft_isascii(int c);
int ft_isdigit(int c);
int ft_isprint(int c);
int ft_tolower(int c);
int ft_toupper(int c);
void *ft_memccpy(void *dst, const void *src, int c, size_t n);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void *ft_memcpy(void *dst, const void *src, size_t n);
void *ft_memset(void *b, int c, size_t len);
char *ft_strcat(char *s1, const char *s2);
char *ft_strchr(const char *s, int c);
int ft_strcmp(const char *s1, const char *s2);
char *ft_strcpy(char *dst, const char *src);
char *ft_strdup(const char *s1);
size_t ft_strlcat(char *dst, const char *src, size_t size);
size_t ft_strlen(const char *s);
char *ft_strncat(char *s1, const char *s2, size_t n);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strncpy(char *dst, const char *src, size_t len);
char *ft_strrchr(const char *s, int c);
char *ft_strstr(const char *haystack, const char *needle);

//part_2:
void ft_putchar(char c);
void ft_putstr(char const *s);
void ft_putendl(char const *s);
void ft_putnbr(int n);
void ft_putchar_fd(char c ,int fd);
void ft_putstr_fd(char const *s ,int fd);
void ft_putendl_fd(char const *s, int fd);
void ft_putnbr_fd(int n, int fd);

#endif
