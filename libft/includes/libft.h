/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 10:54:05 by rsathiad          #+#    #+#             */
/*   Updated: 2018/11/08 21:02:00 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define BUFF_SIZE 100
# define SH_ON  1
# define SIGNED 2
# define BLNK_P 4
# define RT_P   8
# define ZERO_P 16
# define O_X 	32

# define H  1
# define HH 2
# define L  4
# define LL 8
# define J  16
# define Z  32
# define ULL unsigned long long

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_fmt
{
	int				dot;
	int				width;
	int				precision;
	char			conver;
	char			star;
	unsigned char	flagstore;
	unsigned char	modifier;
}					t_fmtblk;

/*
*** GET_NEXT_LINE  && PRINTF
*/
int					get_next_line(const int fd, char **line);
int					ft_printf(const char *format, ...);
int					workhorse(va_list ap, const char *format);
char				*conversionblockunpacker(const char *format);
int					ismodi(char c);
char				isflag(char c);
int					isconversionchr(char c);
char				flaghandler(char *str);
t_fmtblk			formatinit(t_fmtblk	*store);
t_fmtblk			formatblockmaker(char *str);
char				*precisionndot(char *str, t_fmtblk *store);
int					modihandler(char *str);
int					outputstringmaker(char *strlst, va_list ap);
int					functiondispatcher (char chr, t_fmtblk head, va_list ap);
int					print_d(char chr, t_fmtblk blk, va_list ap);
int					print_cs(char chr, t_fmtblk blk, va_list ap);
int					print_u(char chr, t_fmtblk blk, va_list ap);
int					print_o(char chr, t_fmtblk blk, va_list ap);
int					print_x(char chr, t_fmtblk blk, va_list ap);
int					print_lx(char chr, t_fmtblk blk, va_list ap);
int					print_i(char chr, t_fmtblk blk, va_list ap);
int					print_g(char chr, t_fmtblk blk, va_list ap);
int					print_per(t_fmtblk blk);
int					print_wide(char chr, t_fmtblk blk, va_list ap);
char				*addprecisioncs(int precision, char *str);
char				*addprecisiondioux(int precision, char *str);
char				*addsharp_o(t_fmtblk blk, char *tmp);
char				*addsharp_x(t_fmtblk blk, char *tmp, uintmax_t value);
char				*applysharp(char *str, char c);
char				*adjusthex(char *tmp, t_fmtblk blk);
char				*addwidth(int width, char pad, unsigned char flags,
		char *str);
char				*addwidthcs(int width, unsigned char flags, char *str);
char				*addspace(int value, unsigned char flags, char *str);
char				*addsign(int value, unsigned char flags, char *str);
char				*checkneg(int value, char pad, int preci, char *str);
int					pnf_d(t_fmtblk blk, char *con, intmax_t value);
int					pnf_s(t_fmtblk blk, char *con);
int					pnf_u(t_fmtblk blk, char *con);
int					pnf_c(t_fmtblk blk, char con);
int					pnf_o(t_fmtblk blk, char *con, uintmax_t value);
int					pnf_x(t_fmtblk blk, char *con, uintmax_t value);
int					pnf_p(t_fmtblk blk, char *con, uintmax_t value);
int					pnf_wc(wchar_t tmp);
int					pnf_ws(wchar_t *tmp);

/*
*** LIBFT
*/

void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_subnjoin(char *s1, char*s2, int start, int end);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char	**as);
void				ft_strclr(char *s);
void				ft_striter(char	*s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const	*s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_itoabase(int n, int base);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void(*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstmergesort(t_list **alst);
void				ft_lstsplit(t_list *head, t_list **front, t_list **back);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
unsigned char		ft_setbit (char name, int position);
unsigned char		ft_clearbit (char name, int position);
char				*ft_lltoa_base(long long num, unsigned int base,
		int is_cap);
char				*ft_uintmaxtoa_base(uintmax_t num, unsigned int base,
					int is_cap);
char				*ft_intmaxtoa_base(intmax_t num, unsigned int base,
					int is_cap);
char				*ft_ltoa_base(long num, unsigned int base, int is_cap);
int					ft_getarraylen(char **array);
void				ft_free_dblarray(char **list);
char				**ft_split_whitespace(char *str);
char				**ft_split_args_in_line(char *line);
int					ft_count_char(char c, char *str);
char				*ft_char_subst(char pattern, char *sub, char*str);
int					ft_isinteger(char *string);
#endif
