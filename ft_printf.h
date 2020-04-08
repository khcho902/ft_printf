/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:55:00 by kycho             #+#    #+#             */
/*   Updated: 2020/04/09 03:06:40 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

# define FT_PRINTF_TARGET '%'
# define FT_PRINTF_SPECIFIERS "cspdiuxX%"
# define FT_PRINTF_FD STDOUT
# define ERROR -1
# define SUCCESS 1

typedef struct	s_printf_condition
{
	const char	*format;
	va_list		ap;
	int			fd;
}				t_printf_condition;

typedef struct	s_printf_flag
{
	char		specifier;
	int			space;
	int			zero;
	int			minus;
	size_t		width;
	int			precision_exist;
	size_t		precision;
}				t_printf_flag;

typedef struct	s_num_str
{
	int			minus;
	char		*pnum;
	size_t		pnum_len;
	size_t		write_pnum_len;
}				t_num_str;

typedef struct	s_printf_content
{
	char		*prefix;
	size_t		prefix_len;
	char		*content;
	size_t		content_len;
	size_t		must_content_len;
}				t_printf_content;

typedef struct	s_printf_res
{
	char		*res;
	size_t		res_len;
}				t_printf_res;

typedef int		(*t_converter)
					(t_printf_condition *, t_printf_flag *, t_printf_res *);

int				ft_printf(const char *format, ...);
int				ft_conversion_handler
					(t_printf_condition *condition, char *specifiers);
int				ft_printf_putchar(t_printf_condition *condition);
char			ft_get_specifier(const char *format, const char *specifiers);
int				ft_set_flag
					(t_printf_flag *f, t_printf_condition *c, char specifier);

int				ft_printf_converter_char
					(t_printf_condition *c, t_printf_flag *f, t_printf_res *r);
int				ft_printf_converter_string
					(t_printf_condition *c, t_printf_flag *f, t_printf_res *r);
int				ft_printf_converter_pointer
					(t_printf_condition *c, t_printf_flag *f, t_printf_res *r);
int				ft_printf_converter_int
					(t_printf_condition *c, t_printf_flag *f, t_printf_res *r);
int				ft_printf_converter_unsigned_int
					(t_printf_condition *c, t_printf_flag *f, t_printf_res *r);
int				ft_printf_converter_hex
					(t_printf_condition *c, t_printf_flag *f, t_printf_res *r);
int				ft_printf_converter_percent
					(t_printf_condition *c, t_printf_flag *f, t_printf_res *r);

int				ft_isinset(char ch, const char *set);
char			*ft_uitoa(unsigned int n);
char			*ft_uitoa_base(unsigned int n, const char *base);
char			*ft_ultoa_base(unsigned long n, const char *base);

#endif
