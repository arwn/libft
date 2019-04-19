/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awindham <awindham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:25:48 by awindham          #+#    #+#             */
/*   Updated: 2019/04/19 11:40:22 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <wchar.h>
# include <libftstruct.h>
# include <libftprintf.h>
# include <macros.h>

int			g_opterr;
int			g_optind;
int			g_optopt;
int			g_optreset;
char		*g_optarg;

/*
** ft_mem
*/
void		ft_bzero(void *s, size_t n);
void		*ft_memalloc(size_t size);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_memdel(void **ap);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_realloc(void *p, size_t o, size_t n);
void		free_tab(char **tab);
void		freev(void *data, ...);

/*
** ft_io
*/
void		ft_putchar(char c);
void		ft_putstr(const char *s);
void		ft_putendl(const char *s);
void		ft_putnbr(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putarr(char **str, char c);
void		ft_putarr_fd(char **str, char c, int fd);
void		ft_printpad(int w, char *delim, int align, ...);

/*
** ft_string
*/
int			ft_atoi(const char *s);
char		*ft_itoa(int64_t n);
char		*ft_uitoa(uint64_t n);
char		*ft_itoa_base(uint64_t n, int base, int cas);
char		*ft_dtoa(long double d, int prec);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnew(size_t size);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strjoin(const char *s1, const char *s2);
int			ft_strlen(const char *s);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strncat(char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		**ft_strsplit(char const *s, char c);
char		*ft_strdup(char const *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(char const *s, int c);
char		*ft_strrchr(char const *s, int c);
char		*ft_strnstr(char const *h, char const *n, size_t len);
char		*ft_strstr(char const *h, char const *n);
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s);
void		ft_strrev(unsigned char *s);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_striter(char *s, void (*f)(char *));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_countwords(char const *src, char c);
char		*ft_fstrjoin(char *s1, char *s2, int f);
char		*ft_toupperstr(char *str);
int			ft_strchri(char *str, char c);
int			ft_arrlen(void **arr);
char		**ft_strsplitws(char const *s);
char		*ft_strvcat(char *s, ...);
int			array_len(char **tab);
char		**arrdup(char **arr);

/*
**	ft_char
*/
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_islower(int c);
int			ft_isupper(int c);
int			ft_isspace(int c);

/*
** ft_tools
*/
int			ft_getopt(int nargc, char *const nargv[], const char *ostr);
int			get_next_line(int fd, char **line, size_t buff_size);
int			dir_size(char *dirs);
void		log_init(char *str);
void		log_write(char *str);
void		log_close(void);

/*
** ft_math
*/
int			ft_abs(int num);
int64_t		ft_rand(void);

/*
** ft_lst
*/
t_list		*ft_lstnew(void const *content, size_t content_size);
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void		ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void		ft_lstadd(t_list **alst, void *new, size_t size);
void		*ft_lstat(t_list *list, int index);
int			ft_lstlen(t_list *list);
void		ft_lstapd(t_list **alst, t_list *elem);

#endif
