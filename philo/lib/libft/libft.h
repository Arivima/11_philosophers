/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:41:29 by avilla-m          #+#    #+#             */
/*   Updated: 2022/03/28 17:15:33 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

/* get_next_line */
# define BUFFER_SIZE 2048

/* list mgt */
typedef struct s_list
{
	int				n;
	int				index;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

size_t			ft_strlen(const char *s);

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
// unsigned char	ft_is_ext_ascii(unsigned char c);
int				ft_isblank(int c);
int				ft_isspace(char c);

int				ft_toupper(int c);
int				ft_tolower(int c);
/* locates first occurence of c in s, returns pointer */
char			*ft_strchr(const char *s, int c);
/* locates first occurence of c in s, returns index */
int				ft_strchr_i(const char *s, int c);
/* locates last occurence of c in s */
char			*ft_strrchr(const char *s, int c);
int				ft_strrchr_i(const char *s, int c);
/* compares s1 and s2 and return index where different */
int				ft_strncmp(const char *s1, const char *s2, size_t n);
/* compares s1 and s2 and sees if the len is the same */
int				ft_super_strncmp(const char *s1, const char *s2);
/* locates needle in haystack, ret ptr to 1st char of 1st occurence of needle */
char			*ft_strnstr(const char *haystack, const char *needle, \
size_t len);
/*size-bounded string copying, no malloc */
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
/* size-bounded string concatenation, no malloc */
size_t			ft_strlcat(char *dst, const char *src, size_t size);

int				ft_atoi(const char *str);
int				ft_atoi_base(const char *str, int base);
char			*ft_itoa(int n);

/* returns new allocated s2, copied from s1 */
char			*ft_strdup(const char *s1);
/* returns new allocated substring, copied from s1 */
char			*ft_substr(char const *s, int start, size_t len);
/* returns new allocated string concatenated from s1 and s2 */
char			*ft_strjoin(char const *s1, char const *s2);
/* returns new allocated string concatenated from s1, s2 and s3 */
char			*ft_strjoin_three(char *s1, char *s2, char *s3);
/*  returns new allocated string, trimmed from set */
char			*ft_strtrim(char const *s1, char const *set);
/* returns new allocated string modified by function */
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* writes to stdout */
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
int				ft_putchar_int(int c);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd); // putstr_fd + newline
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr_base(int nbr, int base);

/* gnl */
int				get_next_line(int fd, char **line);

/* later additions */
int				ft_abs(int n); // return absolute number
int				ft_getnbr(char *str); // returns int from string // a corriger
int				ft_min(int a, int b);
int				ft_max(int a, int b);

/* array manipulation */
/* return allocated array from string splitted by char c */
char			**ft_split(char const *s, char c);
/* returns allocated array with specified dimensions (square) */
char			**ft_arr_calloc(int rows, int cols);
/* returns number of rows of array */
int				ft_arr_rows(char **arr);
/* return nb of columns in array (size of longest string) */
int				ft_arr_cols(char **arr);
/* returns new allocated array copied from old array */
char			**ft_array_cpy(char **old);
/* free any array */
void			ft_arr_free(char **l_split);
char			**ft_arr_remove(char **arr, int row);

/* matrix */
int				ft_char_mtx_linecount(char **mtx);

/*List mgt, take as example */
t_list			*create_element(int n, int index);
// t_list			*go_to_end(t_list *list);
// t_list			*go_to_top(t_list *list);
int				append_element(t_list **head, int n, int index);
void			remove_element(t_list *elem);
void			delete_list(t_list **list);
int				size(t_list **a);

/* sorting */
void			bubble_sort_stack(t_list **b);

/* graphic */
int				ft_trgb(int t, int r, int g, int b);

#endif
