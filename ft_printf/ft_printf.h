       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.02 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <stdint.h>

# define U6						2147483648U

# define FM_FLAG_MINUS			1
# define FM_FLAG_PLUS			2
# define FM_FLAG_0				4
# define FM_FLAG_OCTOTHORPE		8
# define FM_FLAG_SPACE			16

# define FM_FLAG_WIDTH			32
# define FM_FLAG_ACCURACY		64
# define FM_FLAG_DOLLAR			128

# define FM_PREFIX_L			1
# define FM_PREFIX_LL			2
# define FM_PREFIX_H			4
# define FM_PREFIX_HH			8
# define FM_PREFIX_J			16
# define FM_PREFIX_Z			32
# define FM_PREFIX_T			64
# define FM_PREFIX_BIG_L		128

typedef union					u_long_double
{
	long double					val;
	struct
	{
		unsigned long long int	mantis : 64;
		unsigned int			exponent : 15;
		unsigned int			sign : 1;
	}							s;
	struct
	{
		unsigned char			c[16];
	}							b;
}								t_long_double;

typedef union					u_utf32
{
	wchar_t						wc;
	struct
	{
		unsigned int			a : 6;
		unsigned int			b : 6;
		unsigned int			c : 6;
		unsigned int			d : 6;
		unsigned int			e : 6;
		unsigned int			f : 1;
		unsigned int			g : 1;
	}							utf32;
}								t_utf32;

typedef union					u_fm_param
{
	int							i;
	int							d;
	short int					hd;
	long int					ld;
	long long int				lld;
	unsigned int				u;
	unsigned short int			hu;
	unsigned long int			lu;
	unsigned long long int		llu;
	float						f;
	double						lf;
	t_long_double				llf;
	char						c;
	char						*s;
	unsigned char				hh;
	size_t						st;
	intmax_t					jd;
	uintmax_t					ju;
	wchar_t						lc;
	wchar_t						*ls;
}								t_fm_param;

typedef struct					s_format_modifiers
{
	int							dollar;
	int							flags;
	int							width;
	int							accuracy;
	int							prefix;
	char						type[1];
}								t_format_modifiers;

typedef struct					s_format_list_el
{
	t_format_modifiers			modifiers;
	t_fm_param					param;
	size_t						str_size;
	char						*str;
	int							sign;
	int							radix;
	struct s_format_list_el		*last;
	struct s_format_list_el		*next;
}								t_format_list_el;

void							ft_check_str(t_format_list_el *lst);
void							ft_ltoa(
									unsigned long long param,
									t_format_list_el *lst);

size_t							ft_strlen(const char *s);
size_t							ft_param_len(t_format_list_el *lst);

void							ft_check_accuracy(
									t_format_list_el *lst,
									char *s,
									size_t *n);
void							ft_check_zero(
									t_format_list_el *lst,
									char *s,
									size_t *n,
									size_t len);
void							ft_check_minus(
									t_format_list_el *lst,
									char *s,
									size_t *n);
void							ft_check_sign(
									t_format_list_el *lst,
									char *s,
									size_t *n);
void							ft_check_flags(t_format_list_el *lst);

void							ft_fill_octothorpe(
									t_format_list_el *lst,
									char *s,
									size_t *n);

void							ft_fill_zero(
									char *s,
									size_t *n,
									int len);
void							ft_fill_space(
									t_format_list_el *lst,
									char *s,
									size_t *n,
									int len);
void							ft_fill_param(
									t_format_list_el *lst,
									char *s,
									size_t *n);
char							*ft_fill_str(t_format_list_el *lst, size_t len);

void							ft_fm_int(t_format_list_el *lst);
void							ft_fm_ld(t_format_list_el *lst);
void							ft_fm_lld(t_format_list_el *lst);
void							ft_fm_hd(t_format_list_el *lst);
void							ft_fm_hhd(t_format_list_el *lst);

void							ft_fm_uint(t_format_list_el *lst);
void							ft_fm_lu(t_format_list_el *lst);
void							ft_fm_llu(t_format_list_el *lst);
void							ft_fm_hu(t_format_list_el *lst);
void							ft_fm_hhu(t_format_list_el *lst);

void							ft_fm_percent(t_format_list_el *lst);
void							ft_fm_char(t_format_list_el *lst);
void							ft_fm_str(t_format_list_el *lst);
void							ft_fm_wchar(t_format_list_el *lst);
void							ft_fm_wstr(t_format_list_el *lst);

void							ft_fm_list_free(t_format_list_el **p_fm_list);
void							ft_fm_list_add_el(t_format_list_el **p_fm_list);
void							ft_fm_list_del_first_el(
									t_format_list_el **p_fm_list);

void							ft_printf_get_mult_arg(
									va_list *p_args_root,
									t_format_list_el *fm_list);
long long int					ft_printf_get_n_arg(
									va_list *p_args_root,
									int n);
unsigned int					ft_printf_get_fm_uint(
									const char *format_n,
									size_t i0);

size_t							ft_printf_get_star(
									const char *format_n,
									long long int *result,
									va_list *p_args,
									va_list *p_args_root);
size_t							ft_printf_get_type(
									const char *format_n,
									va_list *p_args,
									va_list *p_args_root,
									t_format_list_el *fm_list);
size_t							ft_printf_get_flags(
									const char *format_n,
									t_format_list_el *fm_list);
size_t							ft_printf_get_dollar(
									const char *format_n,
									t_format_list_el *fm_list);
size_t							ft_printf_get_width(
									const char *format_n,
									va_list *p_args,
									va_list *p_args_root,
									t_format_list_el *fm_list);
size_t							ft_printf_get_accuracy(
									const char *format_n,
									va_list *p_args,
									va_list *p_args_root,
									t_format_list_el *fm_list);
size_t							ft_printf_get_prefix(
									const char *format_n,
									t_format_list_el *fm_list);

void							ft_printf_set_str_from_rapam(
									t_format_list_el *fm_list);
int								ft_printf(const char *format, ...);

int								convert_utf32_to_utf8(
									wchar_t wc_utf32,
									char **utf8);
int								calculate_wstrlen(
									wchar_t *lst,
									int max,
									int flag);
int								convert_utf32_to_utf8_str(
									t_format_list_el *lst);
void							ft_printf_check_color(
									char *str,
									char c,
									size_t *i);
void							ft_printf_exit(
									t_format_list_el **fm_list);
#endif
