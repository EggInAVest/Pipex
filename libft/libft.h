/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:50:01 by reerikai          #+#    #+#             */
/*   Updated: 2025/01/02 08:48:15 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

void	ft_bzero(void *ptr, size_t n);
void	ft_striteri(char *str, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);

void	*ft_memchr(const void *str, int search, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memset(void *ptr, int c, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);
void	*ft_calloc(size_t membox, size_t size);

char	*ft_strchr(const char *str, int search);
char	*ft_strrchr(const char *str, int search);
char	*ft_strdup(const char *str);
char	*ft_strnstr(const char *str, const char *to_find, size_t size);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strtrim(char const *str, char const *set);
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char));
char	*ft_itoa(int n);

char	**ft_split(char const *str, char c);

int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_strncmp(const char *str1, const char *str2, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t size);
int		ft_atoi(const char *ptr);

size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t destsize);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);

// 		BONUS (Linked Lists)

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));

int		ft_lstsize(t_list *lst);

//		Get Next Line

char	*get_next_line(int fd);
char	*leftover(char *buffer);
char	*extract_line(char *buffer);
char	*ft_strdup_nl(const char *str);
char	*ft_strjoin_nl(char *str1, char *str2);

size_t	find_nl(char *buffer);
size_t	ft_strlen_nl(const char *str);

//		Printf

int		ft_printf(const char *format, ...);
int		sort_arg(va_list arguments, const char c);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_pcount(int nb);
int		ft_un_count(unsigned int nb);
int		ft_printnbr(int nb);
int		ft_un_printnbr(unsigned int nb);
int		ft_hex_count(unsigned long nb);
int		ft_printhex(unsigned long nb, const char c);
int		ft_printptr(unsigned long ptr);

#endif
