/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 02:59:31 by lmurray           #+#    #+#             */
/*   Updated: 2021/06/03 23:53:44 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define BUFFER_SIZE 64

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_double_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*previous;
}					t_double_list;

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);

size_t				ft_strlen(const char *s);
int					ft_strlen_int(int num);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
int					ft_strindx(const char *s, int c, int indx);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
char				*ft_strnstr(const char *haystack, \
		const char *needle, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);

void				*ft_calloc(size_t count, size_t size);

int					ft_atoi(const char *str);
long				ft_atoi_long(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					str_isdigits(char *str);

int					ft_toupper(int c);
int					ft_tolower(int c);

char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s1, const char *set);
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
int					ft_putchar(int c);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);

t_list				*ft_create_elem(void *content);
void				ft_list_push_back(t_list **begin_list, void *content);
void				ft_list_push_front(t_list **begin_list, void *data);
void				ft_list_clear(t_list **begin_list);
int					ft_list_size(t_list *map_list);
t_list				*ft_list_at(t_list *begin_list, unsigned int nbr);
t_list				*ft_list_last(t_list *begin_list);
void				*ft_list_last_content(t_list *begin_list);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
int					ft_lstsize(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
	void (*del)(void *));
t_list				*get_stack(int argc, int *digits);
void				print_list(t_list *list);

void				ft_skip_spaces(char *str, int *i);
int					only_digits_ln(char *str);
int					only_digits_comma(char *str);

int					ft_clear_all(int fd, char **save);
int					return_line(int fd, char **line, char **persistant);
int					get_next_line(int fd, char **line);
char				*ft_allocate_join(unsigned int n, unsigned m, \
		char const *s1, char const *s2);
void				print_matrix(char **map, int size);

int					exit_error(char *message, char *command);

#endif
