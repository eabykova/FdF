/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicheli <mmicheli@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:19:12 by mmicheli          #+#    #+#             */
/*   Updated: 2022/05/18 15:46:28 by mmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			ft_bzero(void *s, size_t n);
int				ft_wordcount(char const *s, char c);

size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strnstr(const char *heystack, const char *needle, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strdup(const char *s1);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_char_join(char *s1, char ch);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			**ft_split(char const *s, char c);

void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

int				ft_atoi(const char *str);
unsigned int	ft_htoi(const char *s);
char			*ft_itoa(int n);
float			ft_mod(float i);
float			ft_max_i(float a, float b);
float			ft_min_i(float a, float b);

void			*ft_calloc(size_t nmemb, size_t size);
void			ft_exit(int exit_code);
void			ft_error(int stream_code, int exit_code);
void			ft_malloc_error(int exit_code);
void			ft_kraft_error(char *message, int exit_code);

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
int				ft_lstsize_gnl(t_list *list);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
					void (*del)(void*));

int				ft_putchar_counter(char c);
int				ft_putstr_counter(char *str);
long int		ft_putnbr_counter(long int i);

int				ft_spec_c(va_list args, char ch);
int				ft_spec_s(va_list args, char *str);
int				ft_spec_i_d(va_list args, int i);
int				ft_spec_u(va_list args, unsigned int i);
int				ft_spec_xs(va_list args, unsigned int i);
int				ft_spec_xl(va_list args, unsigned int i);
int				ft_spec_p(va_list args, unsigned long int i);

int				ft_convert_hex_dwn(unsigned long int decnum);
long int		ft_convert_hex_upp(unsigned long int decnum);
int				ft_specificator( const char *strin, va_list args);
long int		ft_convert_uint(int i);
int				ft_strparse(const char *strin, va_list args);
int				ft_printf(const char *frm, ...);

char			*ft_strcat(char *dest, char *src);
char			*ft_strmaker(t_list **list);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_checkbuf(t_list **list, char *buf, int *place);
void			ft_lstadd_back_ch(t_list **lst, char *new);
char			*get_next_line(int fd);
char			**get_lines_fd(int fd);

#endif
