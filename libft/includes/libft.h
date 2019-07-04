/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:14:33 by viclucas          #+#    #+#             */
/*   Updated: 2019/06/25 02:30:24 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_data
{
	int				nb;
	char			*content;
	char			*uid;
	char			*perm;
	char			*date;
	char			*group;
	int				total;
	long long		size;
	long int		modif;
	char			*symb;
	int				attr;
	int				min_dev;
	int				maj_dev;
}				t_data;

typedef struct	s_flag
{
	int				rec;
	int				r;
	int				t;
	int				a;
	int				flag;
	int				i;
	int				io;
	int				j;
	int				uid;
	int				gid;
	char			*name;
	char			*new;
	int				o;
	char			*c;
	char			*ret;
	char			*hate;
}				t_flag;

typedef struct	s_slist
{
	t_data				data;
	struct s_slist		*next;
}				t_slist;

typedef struct	s_file
{
	char			*content;
	struct s_file	*next;
	t_slist			*cont;
	t_data			data;
}				t_file;

t_file			*ft_lstnew1(char *content, t_file *list, int flag);
char			*ft_souder(char *s1, char *s2, char *s3);
int				ft_check_str(char *s, int c);
char			**ft_free_db_tab(char **av);
char			*ft_sous_d(char *s1, char *s2);
void			ft_striter(char *s, void (*f)(char*));
void			ft_strclr(char *s);
int				ft_atoi(const char *str);
void			ft_bzero(void *z, size_t n);
int				ft_isalnum(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
char			*ft_strnew(size_t size);
char			*ft_strncpy(char *dst, const char *src, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_strdup1(const char *s1);
void			ft_strdel(char **as);
char			*ft_strcpy(char *dst, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strcat(char *s1, const char *s2);
void			ft_putstr(char const *s);
void			ft_putchar(char c);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			ft_memdel(void **ap);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strndup(const char *s1, int nb);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putnbrl(int n);
void			ft_putnbr_size_t(size_t nb);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_is_sort(int *s, int lenght, int (*f)(int, int));
char			*ft_strcapitalize(char *str);
int				ft_any(char **s, int (*f)(char*));
void			print_db(char **board);
char			*ft_concat_params(int argc, char **argv);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del) (void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char			**ft_cpy_db_tab(char **env);
void			show_alloc_mem_lib(void);
void			hexa_for(int nb);
#endif
