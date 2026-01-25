/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_plus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:10:39 by migarrid          #+#    #+#             */
/*   Updated: 2026/01/25 06:51:29 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PLUS_H
# define LIBFT_PLUS_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdbool.h>
# include <malloc.h>
# include <limits.h>
# include <sys/mman.h>

# define MLOCK_FLAG		9223372036854775808UL
# define MAX_ALLOC_SIZE	9223372036854775807UL

// LIBFT

// ----------- Obligatorios (Prototipos) ------------
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_issign(int c);
int		ft_isspace(int c);
int		ft_isspecial(int c);
int		ft_ishex(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
bool	ft_atoi_range(const char *nptr);
bool	ft_atol_range(const char *nptr);
long	ft_strtol(const char *nptr, int base);
float	ft_strtof(const char *nptr);
float	ft_square(float x);
int		ft_max(int a, int b);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strmatch_cmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strindex(const char *haystack, const char *needle, size_t start);
size_t	ft_strlcat(char *dst, const char *src, size_t cat_size);
size_t	ft_strlcpy(char *dst, const char *src, size_t cpy_size);
size_t	ft_strlen(const char *s);
size_t	ft_arraylen(char **str_array);
size_t	ft_count_char(const char *str, int c);
void	ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_print_str_array(char **array, int fd);
void	ft_print_int_matrix(int **matrix, size_t rows, size_t cols, int fd);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_alloc(size_t nmemb, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_priv_alloc(size_t nmemb, size_t size);
void	*ft_privatize(void *dirty_ptr, size_t size);
void	*ft_realloc(void *old_ptr, size_t new_size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_memnuke(void *ptr, size_t size);
void	ft_free(void **ptr);
void	ft_free_str_array(char ***array);
void	ft_free_int_matrix(int ***matrix, size_t rows);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strcut(char *str, int c);
char	*ft_strchr_swap(char *str, int old_c, int new_c);
char	*ft_strnorm_spaces(char *str, int space);
char	*ft_strnorm_multi(const char *str, const char *set, int c);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strjoin_multi(int count, ...);
char	*ft_strightrim(const char *str, const char *set);
char	*ft_strleftrim(const char *str, const char *set);
char	*ft_strtrim(const char *s1, const char *s2);
char	*ft_strfilter_c(const char *old_str, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strmapi(const char *s, char (*f)(size_t, char));
char	*ft_capitalize(char *str);
void	ft_str_replace(char **old_str, char *new_str);
void	ft_free_multi(size_t counter, ...);

// ------------ Bonus (Linked List) ------------
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void **));
void	ft_lstclear(t_list **lst, void (*del)(void **));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void **));

// PRINTF

// ------------ Bonus (Stuct Flags) ------------
typedef struct s_format
{
	int		width;			// Flags '0' y '-' min width (ej: %-10s)
	int		precision;		// Flag '.' Presicion (ej: %.5d)
	int		zero_pad;		// Flag '0' (ej: %05d)
	int		left_align;		// Flag '-' (ej: %-10s)
	int		hash;			// Flag '#' (ej: %#x)
	int		space;			// Flag ' ' (ej: % d)
	int		plus;			// Flag '+' (ej: %+d)
	char	specifier;		// Chat of convertion (c, s, d, etc.)
}	t_format;

// ------------- Funtion (Principal) ----------------
int		ft_printf_fd(int fd, char const *str, ...);
int		ft_var_printf_fd(int fd, char const *str, va_list args);

// ----------- Aux. Funtion (flags bonus) ------------
void	ft_apply_flags(char **str, t_format *fmt);
void	ft_apply_hash(char **str, t_format *fmt);
void	ft_apply_left_align(char **str, t_format *fmt);
void	ft_apply_plus(char **str, t_format *fmt);
void	ft_apply_precision(char **str, t_format *fmt);
void	ft_apply_space(char **str, t_format *fmt);
void	ft_apply_zero_pad(char **str, t_format *fmt);
void	ft_apply_min_width(char **str, t_format *fmt);

// ------------ Print Funtion (Utils) ----------------
int		ft_print_char_fd(char c, t_format *fmt, int fd);
int		ft_print_str_fd(char *str, t_format *fmt, int fd);
int		ft_print_ptr_fd(void *ptr, t_format *fmt, int fd);
int		ft_print_num_fd(int n, t_format *fmt, int fd);
int		ft_print_unsigned_fd(unsigned int n, t_format *fmt, int fd);
int		ft_print_hex_fd(unsigned int n, t_format *fmt, int uppercase, int fd);
int		ft_print_float_fd(double f, t_format *fmt, int fd);

// ------------ Aux. Funtion (Utils) --------------
char	*ft_itoa_base(long n, char *base);
char	*ft_utoa_base(unsigned long n);

// ------------ Aux. Funtion float (Utils) --------------
long	ft_power_10(int exp);
int		ft_is_special(double f, char **result);
void	ft_add_zeros(char *result, int *pos, int count);

// GET_NEXT_LINE

# define RESET	-999

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

// ------------- Funtion (Principal) --------------
char	*get_next_line(int fd);

#endif
