/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:31:34 by alajara-          #+#    #+#             */
/*   Updated: 2023/07/27 17:10:11 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DEFINE THE LIBRARY

#ifndef LIBFT_H
# define LIBFT_H

// INCLUDED LIBRARIES

# include <stdlib.h>
# include <ctype.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>

// DEFINES

typedef struct s_list
{
	int				val;
	struct s_list	*nxt;
	struct s_list	*pre;
}	t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// PRINT_F FUNCTIONS

int				ft_printf(const char *a, ...);
int				ft_putchr_pf(int c, int i);
int				ft_putstr_pf(char *str, int i);
int				ft_putptr_pf(unsigned long long pointer, int i);
int				ft_putnbr_pf(int n, int i);
int				ft_putunsi_pf(unsigned int n, int i);
int				ft_puthex_pf(unsigned int hexl, int i);
int				ft_puthexup_pf(unsigned int hexu, int i);

// GNL FUNCTIONS

char			*get_next_line(int fd);
char			*get_the_line(char *storage);
char			*clean_storage(char *storage);
char			*gnl_strchr(char *str, int c);
char			*gnl_join_free(char *storage, char *buffer);
unsigned int	gnl_strlen(char *str);
unsigned int	gnl_strlcat(char *dst, char *src, unsigned int dstsize);
unsigned int	gnl_strlcpy(char *dest, char *src, unsigned int size);

// ASCII FUNCTIONS

int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_atoi(const char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);

//	MEMORY FUNCTIONS

void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);

//	PUT_FD FUNCTIONS

void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);

// STRING FUNCTIONS

char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *d, char *s, unsigned int size);
size_t			ft_strlcpy(char *d, char *s, unsigned int size);
size_t			ft_strlen(const char *str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t len);
char			*ft_strnstr(const char *hystck, const char *needl, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s1, char const *set);

//	LIST FUNCTIONS

t_list			*ft_lstnew(int content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(int));
void			ft_lstclear(t_list **lst);
void			ft_lstiter(t_list *lst, void (*f)(int));
//t_list			*ft_lstmap
//(t_list *l, void *(*f)(void *), void (*del)(void *));

// END OF THE LIBRARY

#endif
