/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 21:58:11 by slaarous          #+#    #+#             */
/*   Updated: 2026/10/16 22:52:24 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
#include <limits.h>
#include <stdint.h>

// ----------Part 1------------ 
//Character classification 
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

/* String length and memory */
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);

/* Copying and moving memory */
void	*ft_memcpy(void *dst, const void *src, size_t n);

/* Copying and searching memory */
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/* String searching and comparison */
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/* String concatenation */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/* Case conversion and integer parsing */
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_atoi(const char *str);

/* Dynamic allocation */
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);

//----------Part 2-------------------------
//String manipulation 
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_striteri(char *s, void (*f)(unsigned int , char *str));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);

//convertion to string 
char	*ft_itoa(int n);

//file descriptor 
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

//----------------parte 3--------------------
// typedef :

typedef struct s_list
{
	void	*content;
	struct	s_list *next;
} 	
t_list;

//      linkd list :
t_list			*ft_lstnew(void	*content);
void			ft_lstadd_front(t_list **lst, t_list *new);
unsigned int	ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void	*));
void			ft_lstiter(t_list *lst, void (*f)(void *content));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
