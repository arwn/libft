/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:42:25 by awindham          #+#    #+#             */
/*   Updated: 2018/12/18 15:12:55 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <wchar.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *s);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strcat(char *s1, const char *s2);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_strdel(char **as);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
char				*ft_strjoin(const char *s1, const char *s2);
size_t				ft_strlen(const char *s);
void				ft_strclr(char *s);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				**ft_strsplit(char const *s, char c);
char				*ft_strdup(char const *s1);
char				*ft_strchr(char const *s, int c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strrchr(char const *s, int c);
char				*ft_strnstr(char const *h, char const *n, size_t len);
char				*ft_strmap(char const *s, char (*f)(char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_strrev(unsigned char *s);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isspace(int c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_countwords(char const *src, char c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
char				*ft_fstrjoin(char *s1, char *s2, int f);
int					get_next_line(int fd, char **line, size_t buff_size);
int					ft_strchri(char *str, char c);

#endif
